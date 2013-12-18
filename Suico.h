/*
 * Suico.h
 *
 *  Created on: 14/12/2013
 *      Author: alcyr
 */

#ifndef SUICO_H_
#define SUICO_H_

#include"Torneio.h"
#include <math.h>

class Suico : public Torneio{
	public:

		void novaRodada();
		void emparceiramento();
		void mostraTabela();

		Suico();
		virtual ~Suico();

	private:
		int mesa;
};

#endif /* SUICO_H_ */
