/*
 * Data.cpp
 *
 *  Created on: 31/10/2013
 *      Author: alcyr
 */

#include "Data.h"
#include <string>

const int Data::diasMes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Data::diasMesBiSexto[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string Data::diaDaSemana(const int dia, const int mes, const int ano){

	int chaveMes[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

	string semana[7]={"segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"};

	int a = ano - 1900;
	int b;
	if ((a%4 == 0) && (mes <= 2)) b = a/4 - 1;
	else b=a/4;
	int c = chaveMes[mes-1];
	int d = dia-1;

	int soma = a+b+c+d;
	int resto=soma%7;


	return semana[resto];
}

bool Data::diaValido(const int dia, const int mes, const int ano){ //TODO corrigir
	string erro;

	if (mes < 1 || mes > 12){
		erro = "mes invalido";
		return false;
	}
	else if ((ano-2000)%4 == 0 && (dia < 1 || dia > diasMesBiSexto[mes-1])){
		erro = "Dia invalido[1]";
		return false;
	}
	else if ((dia < 1) || (dia > diasMes[mes-1])){
		erro = "Dia invalido[2]";
		return false;
	}

	return true;
}

Data::Data() {
}

Data::~Data() {
}
