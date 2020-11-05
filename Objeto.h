#pragma once
#include "libUnicornio.h"

class Objeto
{
public:
	void inicializar(float x, float y);
	void atualizar(Vetor2D p, Sprite s);
	void desenhar();
	void resetar();

protected:
	Sprite sprite;
	Vetor2D posicao;
	bool vivo;
};

