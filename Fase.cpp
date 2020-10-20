#include "Fase.h"

void Fase::inicializar()
{
	if(!gRecursos.carregouSpriteSheet("background"))
		gRecursos.carregarSpriteSheet("background", "bin/assets/imagens/fundopraia.png", 1, 1);

	fundo.setSpriteSheet("background");
}

void Fase::executar()
{
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
}

void Fase::finalizar()
{
	gRecursos.descarregarSpriteSheet("background");
}
