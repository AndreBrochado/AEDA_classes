#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <vector>
#include <stdexcept>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes):
							lotacao(lot), num_max_clientes(n_max_clientes) {
	num_clientes=0;
	vagas=lot;
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::get_clientes() const { return clientes; }


bool ParqueEstacionamento::novo_cliente(const string & nome) 
{
	if ( num_clientes==num_max_clientes ) return false;
	if ( posicao_cliente(nome)!=-1 ) return false;
	InfoCartao info;
	info.nome=nome;
	info.presente=false;
	info.utilizacao=0;
	clientes.push_back(info);
	num_clientes++;
	return true;
}

bool ParqueEstacionamento::retira_cliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( (*it).nome==nome ) {
			if ( (*it).presente==false ) {
				clientes.erase(it);
				num_clientes--;
				return true;
			}
			else return false;
		}
	return false;
}

unsigned int ParqueEstacionamento::num_lugares() const
{
	return lotacao;
}

unsigned int ParqueEstacionamento::num_lugares_ocupados() const
{
	return lotacao-vagas;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas==0 ) return false;
	int pos=posicao_cliente(nome);
	if ( pos==-1 ) return false;
	if ( clientes[pos].presente==true ) return false;
	clientes[pos].presente=true;
	vagas--;
	clientes[pos].utilizacao++;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	int pos=posicao_cliente(nome);
	if ( pos==-1 ) return false;
	if ( clientes[pos].presente==false ) return false;
	clientes[pos].presente=false;
	vagas++;
	return true;
}

bool operator==(const InfoCartao& c1, const InfoCartao& c2){
	return c1.nome == c2.nome;
}

bool operator<(const InfoCartao& c1, const InfoCartao& c2){
	if(c1.utilizacao == c2.utilizacao)
		return c1.nome < c2.nome;
	return c1.utilizacao > c2.utilizacao;
}

// a alterar
int ParqueEstacionamento::posicao_cliente(const string & nome) const {
	InfoCartao c2 = {nome, false, 0};
	return sequentialSearch(clientes, c2);
}

int ParqueEstacionamento::num_utilizacoes(const string &nome) const {
	InfoCartao searchPrototype = {nome, false, 0};
	try{
		searchPrototype = clientes.at(sequentialSearch(clientes, searchPrototype));
	}catch(out_of_range& e){
		throw(ClienteNaoExistente(nome));
	}
	return searchPrototype.utilizacao;
}

void ParqueEstacionamento::ordena_clientes_utilizacao(){
	insertionSort(clientes);
}

vector<string> ParqueEstacionamento::clientes_gama_uso(int n1, int n2){
	vector<string> vectorCortado;
	ordena_clientes_utilizacao();
	for(size_t i = 0; i < clientes.size(); i++){
		if(clientes[i].utilizacao > n2)
			break;
		if(clientes[i].utilizacao >= n1)
			vectorCortado.push_back(clientes[i].nome);
	}
	return vectorCortado;
}

void ParqueEstacionamento::ordena_clientes_nome(){
	for (unsigned int p = 1; p < clientes.size(); p++)  //insertionSort para nomes
	{
		InfoCartao tmp = clientes[p];
		int j;
		for (j = p; j > 0 && tmp.nome < clientes[j-1].nome; j--)
			clientes[j] = clientes[j-1];
		clientes[j] = tmp;
	}
}

InfoCartao ParqueEstacionamento::get_cliente_pos(int p) const{
	try{
		return clientes.at(p);
	}catch(out_of_range& e){
		throw PosicaoNaoExistente(p);
	}
}

ostream & operator << (ostream &os, const ParqueEstacionamento &pe){
	for(size_t i = 0;i < pe.get_clientes().size(); i++){
		os<<"nome: "<<pe.get_clientes()[i].nome<<endl<<"presente? ";
		if(pe.get_clientes()[i].presente)
			os<<"sim";
		else
			os<<"nao";
		os<<endl<<"num utilizacoes: "<<pe.get_clientes()[i].utilizacao<<endl;
	}
	return os;
}
