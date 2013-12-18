/*
 * Torneio.h
 *
 *  Created on: 13/12/2013
 *      Author: alcyr
 */

#ifndef TORNEIO_H_
#define TORNEIO_H_

#include "Enxadrista.h"
#include "Data.h"

class Torneio {

	public:

		Torneio();
		virtual ~Torneio();

		void cadastraJogador(string nome, int rating);
		void listaJogadores();
		void resultado(int jogo, float resultado_brancas, float resultado_pretas, int dia, int mes);
		void corrigirResultado(int jogo, float resultado_brancas, float resultado_pretas);
		void setMax_rodadas(int rodadas){ this->max_rodadas=rodadas; };

		void ranking();
		void getJogo(int jogo) {cout <<this->jogos[jogo].brancas <<" [ " <<this->jogos[jogo].resultado_brancas <<" x " <<this->jogos[jogo].resultado_pretas <<" ] " <<this->jogos[jogo].pretas<<"\n";};
		float getPontos(int jogador) {return competidores[jogador].getPontos(); };

		string getJogador(int numero);

		virtual void novaRodada() = 0;
		virtual void emparceiramento() = 0;
		virtual void mostraTabela() = 0;

	protected:
		int max_rodadas;
		int rodada_atual;

		struct jogo
		{
			int numero; //contagem sequencial de TODOS os jogos. começando de 0.
			int rodada;

			int brancas, pretas; //códigos dos jogadores.

			float resultado_brancas, resultado_pretas;

			int dia, mes;

			} *jogos;

			Enxadrista *competidores;

			struct Pontuacoes{
				int jogador;
				float pts;
			} *pontuacoes;
};

#endif /* TORNEIO_H_ */
