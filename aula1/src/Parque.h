#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
};

class ParqueEstacionamento {
public:
	ParqueEstacionamento(unsigned int lot, unsigned int n_max_clientes);
	bool novo_cliente(const string & nome);
	bool retira_cliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	int posicao_cliente(const string & nome) const;
	unsigned int num_lugares() const;
	unsigned int maximo_clientes() const;
	unsigned int num_lugares_ocupados() const;
	unsigned int num_clientes_atuais() const;

private:
	unsigned int vagas;
	const unsigned int lotacao;
	vector<InfoCartao> clientes;
	unsigned int num_clientes;
	const unsigned int num_max_clientes;
};
