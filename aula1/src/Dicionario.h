#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "BST.h"


class PalavraSignificado {
      string palavra;
      string significado;
public:
       PalavraSignificado(string p, string s): palavra(p), significado(s) {}
       string getPalavra()  const { return palavra; }
       string getSignificado() const { return significado; }
       void setSignificado(string sig) { significado=sig; }
       bool operator < (const PalavraSignificado &ps1) const;
       bool operator ==(const PalavraSignificado &ps1) const;
};

class PalavraNaoExiste{
	  PalavraSignificado antes, apos;
public:
	  PalavraNaoExiste(PalavraSignificado antes, PalavraSignificado apos) : antes(antes), apos(apos){};
	  string getPalavraAntes() const {return antes.getPalavra();};
	  string getSignificadoAntes() const {return antes.getSignificado();};
	  string getPalavraApos() const {return apos.getPalavra();};
	  string getSignificadoApos() const {return apos.getSignificado();};
};

class Dicionario
{
      BST<PalavraSignificado> palavras;
public:
      Dicionario();
      BST<PalavraSignificado> getPalavras() const;
      void lerDicionario(ifstream &fich);
      void imprime() const;
      string consulta(string palavra) const;
      bool corrige(string palavra, string significado);

};


#endif
