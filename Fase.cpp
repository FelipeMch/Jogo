#include "Fase.h"




void Fase::inicializar(Obstaculos* o, int nivel)
{
	if (nivel == 0)
	{
		if (!gRecursos.carregouSpriteSheet("armario"))
		{
			gRecursos.carregarSpriteSheet("armario", "assets/imagens/ArmarioPorta.png");
		}
		obstaculo.setSpriteSheet("armario");
	}
}

void Fase::finalizar()
{
}

void Fase::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		obstaculo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		uniTerminarFrame();
	}
}
