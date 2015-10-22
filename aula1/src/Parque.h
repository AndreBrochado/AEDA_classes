#ifndef PARQUE_H_
#define PARQUE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
	int utilizacao;

};

class ClienteNaoExistente{
	string nome;
public:
	ClienteNaoExistente(string nome){this->nome = nome;};
	string getNome(){return nome;};
};

class PosicaoNaoExistente{
	int posicao;
public:
	PosicaoNaoExistente(int posicao){this->posicao = posicao;};
	int getValor(){return posicao;};
};

class ParqueEstacionamento {
	unsigned int vagas;
	const unsigned int lotacao;
	vector<InfoCartao> clientes;
	unsigned int num_clientes;
	const unsigned int num_max_clientes;
public:
	ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes);
	~ParqueEstacionamento();
	vector<InfoCartao> get_clientes() const;
	bool novo_cliente(const string & nome);
	bool retira_cliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	unsigned int num_lugares() const;
	unsigned int num_lugares_ocupados() const;
	int posicao_cliente(const string & nome) const;
	friend ostream & operator<<(ostream & os, const ParqueEstacionamento & pe);
	int num_utilizacoes(const string &nome) const;
	InfoCartao get_cliente_pos(int p) const;
	void ordena_clientes_utilizacao();
	void ordena_clientes_nome();
	vector<string> clientes_gama_uso(int n1, int n2);
};


#endif /*PARQUE_H_*/
