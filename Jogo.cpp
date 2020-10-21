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
	
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fase.desenhar();
		fase.executar();
		if (!gTeclado.pressionou[TECLA_I])
			tInicio = gTempo.getTicks();
		if (tInicio == 0)
			texto.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 10);
		else
		{
			tempo = gTempo.getTempoAteTickAtual(tInicio);
			texto.setString("Pontos " + to_string(tempo));
			texto.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 10);
		}
		uniTerminarFrame();
	}
}

void Jogo::finalizar()
{
	
	fase.finalizar();
	
	uniFinalizar();
}