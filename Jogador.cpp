/*
 * Jogador.cpp
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#include "Jogador.h"

int Jogador::qt_jogadores=0;

void Jogador::somaJogador(){
	Jogador::qt_jogadores++;
}

Jogador::Jogador() {
	this->nome="BYE";
	this->id=id;
	this->pontos=0;
	this->alocado=false;
}

void Jogador::setId(int id){
	this->id=id;
}

void Jogador::somaPontos(float pontos)
{
	this->pontos+=pontos;
}

void Jogador::subtraiPontos(float pontos)
{
	this->pontos-=pontos;
}

Jogador::~Jogador() {
}

