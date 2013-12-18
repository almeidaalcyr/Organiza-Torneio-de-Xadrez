/*
 * Suico.cpp
 *
 *  Created on: 14/12/2013
 *      Author: alcyr
 */

#include "Suico.h"

Suico::Suico()
{
	this->mesa=0;
	this->pontuacoes = new Pontuacoes[Enxadrista::qt_jogadores];
}

void Suico::emparceiramento()
{
	if (this->rodada_atual==0){
		this->jogos = new jogo[Enxadrista::qt_jogadores*this->max_rodadas];
		this->pontuacoes = new Pontuacoes[Enxadrista::qt_jogadores];
		for (int i=0; i<Enxadrista::qt_jogadores; i++){
			this->pontuacoes[i].jogador=i;
			this->pontuacoes[i].pts=0;
		}
	}

	for (int i=0; i<Enxadrista::qt_jogadores; i++) this->competidores[i].setAlocado(false);


	////////////////////////
	int x = 0, y = 0;
	for (x=0; x< Enxadrista::qt_jogadores; x++)
	{
		for(y=x+1; y<Enxadrista::qt_jogadores; y++){
			if (this->pontuacoes[x].pts > this->pontuacoes[y].pts){
				Pontuacoes aux=pontuacoes[x];
				this->pontuacoes[x]=this->pontuacoes[y];
				this->pontuacoes[y]=aux;
			}
		}
	}

	///////////////////////////
	for (int i=0; i<Enxadrista::qt_jogadores; i++){//brancas
		int jogadorB=this->pontuacoes[i].jogador;
		if (competidores[jogadorB].getAlocado()==false){
			this->jogos[this->mesa].brancas=this->pontuacoes[i].jogador;
			int mesaB=mesa;
			competidores[jogadorB].setAlocado(true);
			for (int j=i; j<Enxadrista::qt_jogadores; j++){
				int jogadorP=this->pontuacoes[j].jogador;
				if (competidores[jogadorP].getAlocado()==false && competidores[jogadorP].verificaAdversario(jogadorB)==false && mesaB==mesa){
					this->jogos[mesa].pretas=jogadorP;
					this->competidores[jogadorP].setAlocado(true);

					this->competidores[jogadorP].setAdversario(jogadorB);
					this->competidores[jogadorB].setAdversario(jogadorP);

					this->jogos[mesa].rodada=this->rodada_atual;
					this->jogos[mesa].numero=mesa;
					cout <<"\n" <<mesa <<": " << this->competidores[jogadorB].getNome() <<" - " <<this->competidores[jogadorP].getNome();
					mesa++;
				}
			}
		}
	}
	cout<<"\n";
}

void Suico::mostraTabela()
{
	cout << "\n---TABELA DE JOGOS---\n";
	int i=0;
	while(i <= this->mesa-1){
		cout <<this->jogos[i].numero <<": " << this->jogos[i].brancas << " - " << this->jogos[i].pretas <<"\n";
		i++;
	}
	cout<<"\n";
}

void Suico::novaRodada()
{
	this->rodada_atual++;
	for (int i = 0; i<Enxadrista::qt_jogadores; i++)
		competidores[i].setAlocado(false);
}

Suico::~Suico() {
	delete [] pontuacoes;
}
