#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(850, 800, false);

	fase.inicializar();
	persoPrincipal.inicializar();
	
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fase.executar();
		persoPrincipal.desenhar();
		persoPrincipal.executar();

		uniTerminarFrame();
	}
}

void Jogo::finalizar()
{
	
	fase.finalizar();
	persoPrincipal .finalizar();

	uniFinalizar();
}