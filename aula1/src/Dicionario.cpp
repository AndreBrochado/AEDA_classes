#include <iostream>
#include <string>
#include <fstream>
#include "Dicionario.h"
#include "BST.h"

using namespace std;

Dicionario::Dicionario() : palavras(PalavraSignificado("", "")){
}



BST<PalavraSignificado> Dicionario::getPalavras() const
{ return palavras; }

bool PalavraSignificado::operator< (const PalavraSignificado &ps1) const{
	return this->palavra < ps1.palavra;
}

void Dicionario::lerDicionario(ifstream &fich){
	string palavra, significado;

	while(getline(fich, palavra)){
		getline(fich, significado);
		palavras.insert(PalavraSignificado(palavra, significado));
	}

}

void Dicionario::imprime() const{
	BSTItrIn<PalavraSignificado> it(palavras);
	while(!it.isAtEnd()){
		cout << it.retrieve().getPalavra() << endl << it.retrieve().getSignificado() << endl;
		it.advance();
	}
}

string Dicionario::consulta(string palavra) const{
	BSTItrIn<PalavraSignificado> it(palavras);
	PalavraSignificado antes("", "");
	PalavraSignificado apos("", "");
	while(!it.isAtEnd()){
		if(it.retrieve().getPalavra() == palavra)
			return it.retrieve().getSignificado();
		if(it.retrieve().getPalavra() < palavra)
			antes = it.retrieve();
		if(it.retrieve().getPalavra() > palavra){
			apos = it.retrieve();
			break;
		}
		it.advance();
	}
	throw(PalavraNaoExiste(antes, apos));
}

bool Dicionario::corrige(string palavra, string significado){
	BSTItrIn<PalavraSignificado> it(palavras);
	while(!it.isAtEnd()){
		if(it.retrieve().getPalavra() == palavra){
			it.retrieve().setSignificado(significado);
			return true;
		}
		it.advance();
	}
	palavras.insert(PalavraSignificado(palavra, significado));
	return false;
}




