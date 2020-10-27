#pragma once
#include "Personagem.h"
#include "Objetos.h"



class Fase
{
public:

	void inicializar();
	void desenhar();
	void executar();
	void finalizar();
	

protected:

	Sprite fundo;
	Personagem persoPrincipal;
	Objetos cocos[4], guarda, tubarao;
	Vetor2D posicoes[2];
	Uint64 tInicio;
	int tempo, velocidade = 0;
	Texto texto;

};

