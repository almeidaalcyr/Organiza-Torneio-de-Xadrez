/*
 * Schuring.h
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#ifndef SCHURING_H_
#define SCHURING_H_

#include <math.h>

#include "Torneio.h"

class Schuring : public Torneio {
	public:

		void emparceiramento();
		void mostraTabela();
		void novaRodada(){};

		Schuring();
		~Schuring();

	private:
		struct mesa{ //não define quem joga de brancas ou negras!!!
			int a,b;
		} *tabela;

		int cont_jogos;

};

#endif /* SCHURING_H_ */
