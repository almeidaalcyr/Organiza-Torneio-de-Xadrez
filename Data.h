/*
 * Data.h
 *
 *  Created on: 31/10/2013
 *      Author: alcyr
 */

#ifndef DATA_H_
#define DATA_H_
#include <string>
using::std::string;

class Data {


	public:
		const static int diasMes[12];
		const static int diasMesBiSexto[12];

		static string diaDaSemana(const int, const int, const int);
		static bool diaValido(const int, const int, const int);

		Data();
		~Data();

	private:



};

#endif /* DATA_H_ */
