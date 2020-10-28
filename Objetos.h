#pragma once
#include "Personagem.h"

class Objetos
{
public:

	void inicializar(string nome, string caminho, int animacoes, int frames, float posicaox, float posicaoy, int valor, bool destrutivel);
	void desenhar();
	int executar(Vetor2D posPersonagem, Sprite sprPersonagem, bool verificarMorte);
	void resetarPosicao();
	bool getDestrutivel() { return destrutivel; }
	void finalizar();
	void setVelocidade();

	

protected:

	Sprite sprite;
	string nome, caminho;
	Vetor2D posicao, posicoes[3];
	bool vivo, destrutivel;
	int valor, velocidade = 0, sorteado, tempo;
	Uint64 tInicio;
	
};

