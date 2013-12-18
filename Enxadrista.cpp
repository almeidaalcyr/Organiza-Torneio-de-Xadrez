/*
 * Enxadrista.cpp
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#include "Enxadrista.h"

void Enxadrista::setEnxadrista(string nome, int rating, int id){
	this->nome=nome;
	this->id=id;

	if (rating==0) this->rating=500;
	else this->rating=rating;
}


string Enxadrista::getNome(){
	return this->nome;
}

Enxadrista::Enxadrista(){
	this->jogos=0;
	this->rating=500;
	this->pontos=0;
	this->adversario=new int[1];
}

Enxadrista::Enxadrista(Enxadrista &e)
{
	this->nome=e.nome;
	this->rating=e.rating;
	this->id=e.id;
	this->jogos=e.jogos;
	this->pontos=e.pontos;
	this->adversario=e.adversario;
}

void Enxadrista::setAdversario(int adv)
{
	//this->jogos++;
	int *adv_aux;
	adv_aux = new int[this->jogos];
	for (int i=0; i<jogos; i++)
		adv_aux[i] = this->adversario[i];
	//delete this->adversario;

	adversario = new int[this->jogos];
	for (int i=0; i<jogos; i++)
		adversario[i] = adv_aux[i];
	adversario[jogos]=adv;

}

bool Enxadrista::verificaAdversario(int a)
{
	for (int i=0; i<this->jogos; i++)
		if(a==this->adversario[i]) return true;
	return false;
}

void Enxadrista::operator++(int) { this->jogos++; }

Enxadrista::~Enxadrista() {
delete [] adversario;
}

