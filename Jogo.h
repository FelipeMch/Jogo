#pragma once
#include "libUnicornio.h"
#include "Fase.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

protected:
	Sprite fundo;
	int faseatual;
	Obstaculos obstaculo;
	Fase fase;

};

