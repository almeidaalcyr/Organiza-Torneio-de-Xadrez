//============================================================================
// Name        : NovoXadrez.cpp
// Author      : Alcyr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include"Torneio.h"
#include "Schuring.h"
#include "Suico.h"

int main() {
	//TODO LIST:
	//DONE OK - atributos static.
	//DONE OK - Métodos static.
	//TODO Composição com classe Data.
	//DONE OK - operadores sobrecarregados.
	//DONE OK - static_cast
	//DONE OK - Construtor de cópia
	//DONE OK - operador de atribuição.
	//DONE OK - Polimorfismo


	/* Classe main */

	Torneio *torneio;

	int resposta;

	cout <<"[0] Schuring;\n[1] Suiço.\n--> tipo o ritmo do torneio: ";
	cin >> resposta;
	if (resposta==0)
		torneio = new Schuring();

	else if (resposta==1){
		int rodadas;
		torneio = new Suico();

		cout <<"Quantidade de rodadas: ";
		cin >> rodadas;
		torneio->setMax_rodadas(rodadas);
	}

	cout <<"\n --- CADASTRO DE JOGADORES ---\n";

	resposta=1; //pra entrar no while
	while (resposta!=0){ //cadastra jogadores
		string nome;
		//int rating;
		cout << "Nome do jogador: ";
		cin >> nome;
		//cout << "Rating: ";
		//cin >> rating;

		torneio->cadastraJogador(nome, 500);
		cout <<"\n-> Cadastrar novo jogador? [0] NÃO / [1] SIM \nAo dizer que não você inicia o torneio:";
		cin >>resposta;
	}

	int dia=50,mes=1, ano=2000;

	while(!Data::diaValido(dia,mes,ano)){
		cout << "\nOs resultados inseridos são referentes ao dia:";
		cin >> dia;
		cout << "mês:";
		cin >> mes;
		cout << "ano: ";
		cin >> ano;
	}

	torneio->listaJogadores();
	torneio->emparceiramento();
	torneio->mostraTabela();

	resposta=10;
	while (resposta!=0){
		int jogo;
		float b,p;
		cout<<"1 - Inserir resultado\n2 - Corrigir resultado\n3 - Proxima rodada\n4 - Ranking\n";
		cin >> resposta;
		switch (resposta){
			case (1): {
				cout <<"Jogo: ";
				cin >> jogo;
				cout <<"Resultado das Brancas: "; //mostrar nome do jogador
				cin >> b;
				cout <<"Resultado das Pretas: ";
				cin >> p;
				torneio->resultado(jogo,b,p, dia, mes);
				break;
			}

			case(2):{
				cout << "Jogo que será alterado: ";
				cin >> jogo;
				cout << "o jogo " <<jogo << "é:\n";
				torneio->getJogo(jogo);
				cout <<"Resultado das Brancas: "; //mostrar nome do jogador
				cin >> b;
				cout <<"Resultado das Pretas: ";
				cin >> p;
				torneio->corrigirResultado(jogo, b, p);
				break;
			}

			case(3):{
				torneio->novaRodada();
				torneio->emparceiramento();
				torneio->mostraTabela();
				break;
			}

			case(4):{
				torneio->ranking();
				break;
			}

			case (0): break;
		}
	}
	return 0;
}
