#pragma once
#include "Fase.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void executar();
	void finalizar();

protected:
	Uint64 tInicio;
	int tempo;
	Texto texto;
	Fase fase;
	
};

