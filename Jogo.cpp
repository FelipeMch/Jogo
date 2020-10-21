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

	/*tInicio = 0;
	gRecursos.carregarFonte("fonte", "bin/assets/fontes/fonte.ttf", 17);
	texto.setFonte("fonte");
	texto.setCor(3, 0, 147);*/



}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fase.desenhar();
		fase.executar();
		
		
		/*tInicio = gTempo.getTicks();
		tempo = gTempo.getTempoAteTickAtual(tInicio);
		texto.setString("Pontos " + to_string(tempo));
		texto.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 10);*/
		

		uniTerminarFrame();
	}
}

void Jogo::finalizar()
{
	
	fase.finalizar();
	
	uniFinalizar();
}