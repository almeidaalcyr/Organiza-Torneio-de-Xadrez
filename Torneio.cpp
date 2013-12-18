/*
 * Torneio.cpp
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#include "Torneio.h"

Torneio::Torneio()
{
	this->rodada_atual=0;
	this->max_rodadas=0;

	this->jogos= 0;
	this->competidores=new Enxadrista[1];
	this->pontuacoes=new Pontuacoes[1];
}

void Torneio::cadastraJogador(string nome, int rating)
{
	int i;

	Enxadrista *competidores_aux;
	competidores_aux = new Enxadrista[Enxadrista::qt_jogadores+1];
	for (i=0; i < Enxadrista::qt_jogadores; i++) competidores_aux[i]=competidores[i];
	//delete [] competidores;

	competidores = new Enxadrista[Enxadrista::qt_jogadores+1];
	for (i=0; i<Enxadrista::qt_jogadores+1; i++)
		competidores[i]=competidores_aux[i];
	delete [] competidores_aux;

	competidores[Enxadrista::qt_jogadores].setEnxadrista(nome,rating, Enxadrista::qt_jogadores);

	Enxadrista::somaJogador();
}

void Torneio::listaJogadores()
{
	cout <<"\n--- JOGADORES CADASTRADOS---\n";
	for (int i=0; i< Enxadrista::qt_jogadores; i++)	cout << i <<" " <<this->competidores[i].getNome() <<"\n";
}

void Torneio::resultado(int jogo, float resultado_brancas, float resultado_pretas, int dia, int mes)
{
	int brancas=this->jogos[jogo].brancas;
	int pretas=this->jogos[jogo].pretas;

	this->jogos[jogo].dia=dia;
	this->jogos[jogo].mes=mes;

	this->jogos[jogo].resultado_brancas=resultado_brancas;
	this->jogos[jogo].resultado_pretas=resultado_pretas;

	competidores[brancas].somaPontos(resultado_brancas);
	competidores[brancas]++;
	competidores[brancas].setAdversario(pretas);
	this->pontuacoes[brancas].pts+=resultado_brancas;

	competidores[pretas].somaPontos(resultado_pretas);
	competidores[pretas]++;
	competidores[pretas].setAdversario(brancas);
	this->pontuacoes[pretas].pts+=resultado_pretas;
}

void Torneio::corrigirResultado(int jogo, float b, float p)
{
	int brancas=this->jogos[jogo].brancas;
	int pretas=this->jogos[jogo].pretas;

	if(b != brancas) competidores[brancas].subtraiPontos(this->jogos[jogo].resultado_brancas);
	if(p != pretas) competidores[pretas].subtraiPontos(this->jogos[jogo].resultado_pretas);

	this->jogos[jogo].resultado_brancas=b;
	this->jogos[jogo].resultado_pretas=p;

	competidores[brancas].somaPontos(b);
	cout << "o jogador [" <<brancas <<"] agora tem " <<this->competidores[brancas].getPontos() <<" pontos.\n";

	competidores[pretas].somaPontos(p);
	cout << "o jogador [" <<pretas <<"] agora tem " <<this->competidores[pretas].getPontos() <<" pontos de " <<competidores[pretas].getJogos() <<"\n";
}

void Torneio::ranking()
{
	float p=static_cast<float>(this->rodada_atual)+1;
	while (p>=0){
		for (int j=0; j<Enxadrista::qt_jogadores;j++){
			if (this->competidores[j].getPontos()==p)
				cout <<competidores[j].getNome() <<" - " <<p <<"\n";
		}
		p-=0.5;
	}
}

Torneio::~Torneio() {
	delete [] competidores;
}
