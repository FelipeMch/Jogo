#include "Jogo.h"
#include "Fase.h"
#include "Obstaculos.h"


Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(900, 500, false);

	faseatual = 0;



		
	if (!gRecursos.carregouSpriteSheet("fundo"))
	{
		gRecursos.carregarSpriteSheet("fundo", "assets/imagens/fundo.png");
	}
	fundo.setSpriteSheet("fundo");

	

	
}

void Jogo::finalizar()
{
	

	uniFinalizar();
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		uniTerminarFrame();
	}
	
}