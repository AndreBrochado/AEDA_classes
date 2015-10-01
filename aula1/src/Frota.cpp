#include "Frota.h"
#include <iostream>
#include <string>

using namespace std;

Veiculo::Veiculo(string marca, int mes, int ano){
	this->marca = marca;
	this->mes = mes;
	this->ano = ano;
}

Motorizado::Motorizado(string marca, int mes, int ano, string combustivel, int cilindrada):
				Veiculo(marca, mes, ano)
{
	this->combustivel = combustivel;
	this->cilindrada = cilindrada;
}

Automovel::Automovel(string marca, int mes, int ano, string combustivel, int cilindrada):
		Motorizado(marca, mes, ano, combustivel, cilindrada) {}

Camiao::Camiao(string marca, int mes, int ano, string combustivel, int cilindrada, int carga_maxima):
		Motorizado(marca, mes, ano, combustivel, cilindrada)
{
	this->carga_maxima = carga_maxima;
}

Bicicleta::Bicicleta(string marca, int mes, int ano, string tipo):
		Veiculo(marca, mes, ano)
{
	this->tipo = tipo;
}

int Veiculo::info() const{
	cout<<"marca: "<<marca<<endl<<"data: "<<mes<<"/"<<ano<<endl;
	return 3;
}

int Motorizado::info() const{
	Veiculo::info();
	cout<<"combustivel: "<<combustivel<<endl<<"cilindrada: "<<cilindrada<<endl;
	return 5;
}

int Automovel::info() const{
	return Motorizado::info();
}

int Camiao::info() const{
	Motorizado::info();
	cout<<"carga maxima: "<<carga_maxima<<endl;
	return 6;
}

int Bicicleta::info() const{
	Veiculo::info();
	cout<<"tipo: "<<tipo<<endl;
	return 4;
}

/*float Motorizado:: calcImposto() const{
	if(this->combustivel == "gasolina" && this->cilindrada <= 1000 &&)
}*/

bool Veiculo::operator < (const Veiculo & v) const{
	if(this->ano != v.ano)
		return this->ano < v.ano;
	else
		return this->mes < v.mes;
}

void Frota::adicionaVeiculo(Veiculo *v1){
	veiculos.push_back(v1);
}

int Frota::numVeiculos() const{
	return veiculos.size();
}

int Frota::menorAno() const{
	if(veiculos.size() == 0)
		return 0;
	int anoMin = veiculos[0]->getAno();
	for(size_t i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getAno() < anoMin)
			anoMin = veiculos[i]->getAno();
	}
	return anoMin;
}

void Frota::info() const{
	for(size_t i = 0; i < veiculos.size(); i++){
		veiculos[i]->info();
	}
}

string Veiculo::getMarca() const{
	return marca;
}

int Veiculo::getAno() const{
	return ano;
}

string Motorizado::getCombustivel() const{
	return combustivel;
}
