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
	Objetos coco, guarda, tubarao;
	Vetor2D posicao;
	bool vivo, destrutivel;
	

};

