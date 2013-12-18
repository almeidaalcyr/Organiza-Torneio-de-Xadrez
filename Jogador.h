/*
 * Jogador.h
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <string>
using::std::string;

class Jogador {

	public:

		static void somaJogador();
		static int qt_jogadores;

		float getPontos() {return this->pontos; };
		void setAlocado(bool alocado) {this->alocado=alocado; };
		bool getAlocado() {return this->alocado; };


		Jogador();
		Jogador(string nome);
		virtual ~Jogador();

		void somaPontos(float pontos);
		void subtraiPontos(float pontos);
		void setId(int id);

	protected:
		bool alocado;
		string nome;
		int id;
		float pontos;
};

#endif /* JOGADOR_H_ */
