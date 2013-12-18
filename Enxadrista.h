/*
 * Enxadrista.h
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#ifndef ENXADRISTA_H_
#define ENXADRISTA_H_

#include<iostream>
using namespace std;

#include "Jogador.h"

class Enxadrista : public Jogador{
	public:
		void operator++(int);
		void setEnxadrista(string nome, int rating, int id);
		void setAdversario(int adversario);
		int getJogos() const {return this->jogos;}
		bool verificaAdversario(int adversario); //verifica se competidores[n] e competidores[a] já se enfrentaram.
		string getNome();
		Enxadrista();
		Enxadrista(Enxadrista &e);
		~Enxadrista();

	private:
		int rating;
		int jogos;
		float pontos;

		int *adversario;
};

#endif /* ENXADRISTA_H_ */
