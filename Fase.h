#pragma once
#include "Personagem.h"
#include "Objetos.h"



class Fase
{
public:

	void inicializar(Personagem *p);
	void desenhar();
	void executar();
	int getVelocidade() { return velocidade; }
	int getTempo() { return tempo; }
	void finalizar();
	void controladorVelocidade();

protected:

	Sprite fundo;
	Personagem *persoPrincipal;
	Objetos cocos[4], guardas[2], tubarao;
	Vetor2D posicoes[2];
	Uint64 tInicio;
	bool colidiu;
	int tempo;
	Texto texto;
	float velocidade = 0;
};

