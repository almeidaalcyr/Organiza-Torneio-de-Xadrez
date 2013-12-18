/*
 * Schuring.cpp
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#include "Schuring.h"

Schuring::Schuring() {
	this->tabela='\0';
	this->cont_jogos=0;
}

Schuring::~Schuring() {}

void Schuring::emparceiramento()
{
	int i,
			t_mesas=ceil(Enxadrista::qt_jogadores/2);

	this->jogos = new jogo[(t_mesas*(Enxadrista::qt_jogadores-1))]; //TODOS os jogos do torneio
	this->tabela = new mesa[t_mesas]; //integrantes das mesas por rodada. NÃO INDICA A ORDEM DOS JOGADORES.
	int rodada;

	for(rodada=0; rodada<Enxadrista::qt_jogadores-1; rodada++){
		int inv=Enxadrista::qt_jogadores-1-rodada;

		for(i=0; i<t_mesas; i++){
			tabela[i].b=inv--;
			if (inv==0) inv = Enxadrista::qt_jogadores-1;
		}

		for (i=1; i<t_mesas; i++){//
			tabela[t_mesas-i].a=inv--;
			if (inv==0) inv = Enxadrista::qt_jogadores-1;
		}

		tabela[0].a=0;

		/* (...) */

		for (i=0; i<t_mesas; i++){
			if (i==0 && rodada%2==1){
				this->jogos[this->cont_jogos].brancas=this->tabela[i].b;
				this->jogos[this->cont_jogos].pretas=this->tabela[i].a;
			}
			else if (i==0 && rodada%2!=1){
				this->jogos[this->cont_jogos].brancas=this->tabela[i].a;
				this->jogos[this->cont_jogos].pretas=this->tabela[i].b;
			}
			else if (i%2==1){
				this->jogos[this->cont_jogos].brancas=this->tabela[i].b;
				this->jogos[this->cont_jogos].pretas=this->tabela[i].a;
			}
			else if (i%2!=1){
				this->jogos[this->cont_jogos].brancas=this->tabela[i].a;
				this->jogos[this->cont_jogos].pretas=this->tabela[i].b;
			}

			this->jogos[this->cont_jogos].numero=this->cont_jogos;
			this->jogos[this->cont_jogos].rodada=rodada;
			this->cont_jogos++;
		}
	}
}

void Schuring::mostraTabela()
{
	cout << "\nTABELA DE JOGOS:\n";
	for (int i=0; i<this->cont_jogos;i++){
		cout <<this->jogos[i].numero <<": " << this->jogos[i].brancas << " - " << this->jogos[i].pretas <<"\n";
	}
}
