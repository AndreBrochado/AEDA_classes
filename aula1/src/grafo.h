#include <iostream>
#include <vector>

using namespace std;

/**
 * Versão da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template<class N>
class NoRepetido{
public: N info; NoRepetido(N info){ this->info = info;}
};

template<class N>
class ArestaRepetida{
public: N inicio; N fim; ArestaRepetida(N inicio, N fim){this->inicio = inicio; this->fim = fim;
}
};

template<class N>
class NoInexistente{
public: N info; NoInexistente(N info){ this->info = info;}
};

template<class N>
ostream& operator<<(ostream& out, NoRepetido<N> no){
	out<< "No repetido: "<< no.info;
	return out;
}

template<class N>
ostream& operator<<(ostream& out, ArestaRepetida<N> aresta){
	out<<"Aresta repetida: "<< aresta.inicio << " , "<< aresta.fim;
	return out;
}

template<class N>
ostream& operator<<(ostream& out, NoInexistente<N> no){
	out<< "No inexistente: "<< no.info;
	return out;
}

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
public:
	Grafo(){};
	~Grafo(){};
	Grafo<N, A> & inserirNo(const N &dados){
		for(size_t i = 0; i < nos.size(); i++){
			if(nos[i]->info == dados)
				throw(NoRepetido<N>(dados));
		}
		No<N,A>* novoNo = new No<N,A>(dados);
		nos.push_back(novoNo);
		return *this;
	};
	Grafo & inserirAresta(const N &inicio, const N &fim, const A &val){
		int j = -1;
		int k = -1;
		for(size_t i = 0; i < nos.size(); i++){
			if(nos[i]->info == inicio)
				j = i;
			if(nos[i]->info == fim)
				k = i;
		}
		if(j==-1)
			throw(NoInexistente<N>(inicio));
		if(k==-1)
			throw(NoInexistente<N>(fim));
		for(size_t i = 0; i < nos[j]->arestas.size(); i++){
			if(nos[j]->arestas[i].destino->info == fim)
				throw ArestaRepetida<N>(inicio, fim);
		}
		Aresta<N,A> novaAresta(nos[k], val);
		nos[j]->arestas.push_back(novaAresta);
		return *this;
	}
	Grafo & eliminarAresta(const N &inicio, const N &fim);
	A & valorAresta(const N &inicio, const N &fim);
	int numArestas(void) const{
		int sum = 0;
		for(size_t i = 0; i < nos.size(); i++){
			sum += nos[i]->arestas.size();
		}
		return sum;
	};
	int numNos(void) const{return nos.size();};
	void imprimir(std::ostream &os) const;
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);

