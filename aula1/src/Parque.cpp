#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes)
	: lotacao(lot), num_max_clientes(n_max_clientes)
{
	num_clientes = 0;
	vagas = lot;
}

unsigned int ParqueEstacionamento::num_lugares() const{
	return lotacao;
}

unsigned int ParqueEstacionamento::maximo_clientes() const{
	return num_max_clientes;
}

int ParqueEstacionamento::posicao_cliente(const string & nome) const{
	for(size_t i=0; i<clientes.size(); i++){
		if(nome == clientes[i].nome)
			return i;
	}
	return -1;
}

bool ParqueEstacionamento::novo_cliente(const string & nome){
	if(num_max_clientes>num_clientes && this->posicao_cliente(nome) == -1){
			InfoCartao novo_cliente{nome, false};
			clientes.push_back(novo_cliente);
			num_clientes++;
			return true;
	}
	return false;
}

bool ParqueEstacionamento::entrar(const string & nome){
	int pos = this->posicao_cliente(nome);
	if(vagas!=0 && pos!=-1){
		if(!clientes[pos].presente){
			clientes[pos].presente = true;
			vagas--;
			return true;
		}
	}
	return false;
}

bool ParqueEstacionamento::retira_cliente(const string & nome){
	int pos = this->posicao_cliente(nome);
	if(pos != -1 && clientes[pos].presente == false){
		clientes.erase(clientes.begin()+pos);
		num_clientes--;
		return true;
	}
	return false;
}

bool ParqueEstacionamento::sair(const string & nome){
	int pos = this->posicao_cliente(nome);
	if(pos != -1 && clientes[pos].presente){
		clientes[pos].presente=false;
		vagas++;
		return true;
	}
	return false;
}

unsigned int ParqueEstacionamento::num_lugares_ocupados() const{
	return lotacao-vagas;
}

unsigned int ParqueEstacionamento::num_clientes_atuais() const{
	return clientes.size();
}
