#include "zoo.h"

Veterinario::Veterinario(string nome, long codOrdem){
	this->nome = nome;
	this->codOrdem = codOrdem;
}

int Animal::maisJovem = -1;

Animal::Animal(string nome, int idade, Veterinario* vet){
	this-> nome = nome;
	this-> idade = idade;
	this-> vet = vet;
	if(idade < maisJovem || maisJovem == -1)
		maisJovem = idade;
}

string Animal::getNome() const {
	return nome;
}



string Veterinario::getNome() const {
	return nome;
}


int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

static int Animal::getMaisJovem(){
	return maisJovem;
}
