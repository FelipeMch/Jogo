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
	uniInicializar(850, 800, false);

	fase.inicializar();
	persoPrincipal.inicializar();

	tInicio = 0;
	gRecursos.carregarFonte("fonte", "bin/assets/fontes/fonte.ttf", 17);
	texto.setFonte("fonte");
	texto.setCor(4, 0, 130);

	
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fase.executar();
		persoPrincipal.desenhar();
		persoPrincipal.executar();

		if (gTeclado.pressionou[TECLA_I]) {

		tInicio = gTempo.getTicks();

		if (tInicio == 0)
		{
		texto.desenhar(gJanela.getLargura() / 5, gJanela.getAltura() / 10);
		}
		
		}
		else
		{

		tempo = gTempo.getTempoAteTickAtual(tInicio);
		texto.setString("Pontos " + to_string(tempo * 2));
		texto.desenhar(gJanela.getLargura() / 5, gJanela.getAltura() / 10);

		}

		uniTerminarFrame();
	}
}

void Jogo::finalizar()
{
	
	fase.finalizar();
	persoPrincipal .finalizar();

	uniFinalizar();
}