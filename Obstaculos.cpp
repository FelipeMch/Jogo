#include "Obstaculos.h"

void Obstaculos::inicializar()
{

	if (!gRecursos.carregouSpriteSheet("obstaculo"))
	{
		gRecursos.carregarSpriteSheet("obstaculo", "assets/imagens/ArmarioPorta.png");
	}
	obstaculo.setSpriteSheet("obstaculo");
}

void Obstaculos::finalizar()
{
}

void Obstaculos::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		obstaculo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		uniTerminarFrame();
	}
}
