/*
 * zoo.h
 */

#ifndef ZOO_H_
#define ZOO_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Veterinario {
	string nome;
	long codOrdem;
	//...
public:
	Veterinario(string nome, long codOrdem);
	string getInformacao() const;
	string getNome() const;
	//...
};

class Animal {
protected:
	string nome;
	int idade;
	Veterinario *vet;
	static int maisJovem;
public:
	Animal(string nome, int idade, Veterinario* vet);
	virtual ~Animal(){};
	string getNome() const;
	virtual string getInformacao() const;  // informacao sobre nome animal, idade animal, nome do veterinario
	virtual bool eJovem() const = 0;
	static int getMaisJovem();
};



class Cao: public Animal {
	string raca;
public:
	//...
};



class Voador {
	int velocidade_max;
	int altura_max;
public:
	virtual ~Voador(){};
	virtual string getInformacao() const;  // informacao sobre velocidade, altitude maxima
	//...
};



class Morcego: public Animal, public Voador {
public:
	//...
};


class Zoo {
	vector<Animal *> animais;
	vector<Veterinario *> veterinarios;
public:
	int numAnimais() const;
	int numVeterinarios() const;
	void adicionaAnimal(Animal *a1);
	string getInformacao() const;
	bool animalJovem(string nomeA);
	void alocaVeterinarios(istream &isV);
	bool removeVeterinario(string nomeV);
	bool operator < (Zoo& zoo2) const;
};


#endif /* ZOO_H_ */
