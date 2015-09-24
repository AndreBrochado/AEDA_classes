#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <string>
#include "Parque.h"


// Este teste serve para avaliar a correcta implementação da questão a) da ficha prática 01
 void test_1a_AbrirParque() {

	ParqueEstacionamento p1(4, 6);
	// Testa se o parque foi aberto com a lotação indicada
	ASSERT_EQUAL(4, p1.num_lugares());
	// Testa se o parque foi aberto com o número máximo de clientes indicado
	ASSERT_EQUAL(6, p1.maximo_clientes());
}


//Este teste serve para avaliar a correcta implementação da questão b) da ficha prática 01
void test_1b_AdicionarCliente() {

	ParqueEstacionamento p1(3, 5);
	// Testa se deixa adicionar um novo cliente
	ASSERT_EQUAL(true, p1.novo_cliente("Joao"));
	p1.novo_cliente("Antonio");
	p1.novo_cliente("Rui");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Clara");
	// Testa se recusa novo cliente quando numero máximo de clientes foi atingido
	ASSERT_EQUAL(false, p1.novo_cliente("Paula"));
	// Testa se retorna a posição correcta do cliente
	ASSERT_EQUAL(1, p1.posicao_cliente("Antonio"));
	// Testa se retorna -1 caso o cliente não exista
	ASSERT_EQUAL(-1, p1.posicao_cliente("Joana"));

}


// Este teste serviria para avaliar a correcta implementação da questão c) da ficha prática 01
void test_1c_EntrarParque() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Antonio");
	p1.novo_cliente("Rui");
	// Testa se deixa entrar no parque um cliente existente
	ASSERT_EQUAL(true, p1.entrar("Maria"));
	// Testa se não deixa entrar no parque um cliente que não existe
	ASSERT_EQUAL(false, p1.entrar("Paula"));
	// Testa se não dexia entrar em cliente que já lá está
	ASSERT_EQUAL(false, p1.entrar("Maria"));
	p1.entrar("Joao");
	p1.entrar("Antonio");
	// Testa se não deixa entrar quando a lotação está completa
	ASSERT_EQUAL(false, p1.entrar("Rui"));

}


// Este teste serve para avaliar a correcta implementação da questão d) da ficha prática 01
void test_1d_RetiraCliente() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Antonio");
	p1.entrar("Maria");
	// Testa se não deixa remover cliente que está dentro do parque
	ASSERT_EQUAL(false, p1.retira_cliente("Maria"));
	// Testa se deixa remover cliente que está fora do parque
	ASSERT_EQUAL(true, p1.retira_cliente("Antonio"));
	// Testa se nao deixa remover cliente que nao existe
	ASSERT_EQUAL(false, p1.retira_cliente("Ana"));

}


// Este teste serviria para avaliar a correcta implementação da questão g) da ficha prática 01
void test_1e_SairParque() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Rui");
	p1.entrar("Maria");
	p1.entrar("Joao");
	p1.entrar("Rui");
	// Testa se um cliente estacionado no parque, sai.
	ASSERT_EQUAL(true, p1.sair("Maria"));
	// Testa se não deixa sair um cliente que não está estacionado.
	ASSERT_EQUAL(false, p1.sair("Maria"));
	// Testa se não deixa sair um cliente que não existe.
	ASSERT_EQUAL(false, p1.sair("Antonio"));

}


// Este teste serve para avaliar a correcta implementação da questão e) da ficha prática 01
void test_1f_LugaresLotacaoParque() {

	ParqueEstacionamento p1(3, 5);
	p1.novo_cliente("Joao");
	p1.novo_cliente("Maria");
	p1.novo_cliente("Antonio");
	p1.entrar("Maria");
	p1.entrar("Antonio");
	// Testa se Lotacao do parque está correcta
	ASSERT_EQUAL(3, p1.num_lugares());
	// Testa se o numero de viaturas presentes no parque está correcto
	ASSERT_EQUAL(2, p1.num_lugares_ocupados());
	// Testa se o o número de clientes registados no parque está correcto
	ASSERT_EQUAL(3, p1.num_clientes_atuais());

}



void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_1a_AbrirParque));
	s.push_back(CUTE(test_1b_AdicionarCliente));
	s.push_back(CUTE(test_1c_EntrarParque));
	s.push_back(CUTE(test_1d_RetiraCliente));
	s.push_back(CUTE(test_1e_SairParque));
	s.push_back(CUTE(test_1f_LugaresLotacaoParque));

	cute::ide_listener<> lis;
	cute::makeRunner(lis)(s,"AEDA 2015/2016 - Aula Pratica 1" );
}


int main(){
    runSuite();
}



