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

	Fase fase;
	
};

