#include "Objeto.h"

void Objeto::inicializar(float x, float y)
{
	if (!gRecursos.carregouSpriteSheet("spriteCoco"))
	{
		gRecursos.carregarSpriteSheet("spriteCoco", "bin/assets/imagens/coco.png", 1, 6);
	}
	sprite.setSpriteSheet("spriteCoco");

	/*if (!gRecursos.carregouAudio("somMoeda"))
	{
		gRecursos.carregarAudio("somMoeda", "assets/sons/moeda.wav");
	}

	posicao.x = x;
	posicao.y = y;
	resetar();*/
}

void Objeto::atualizar(Vetor2D p, Sprite s)
{
	sprite.avancarAnimacao();
	if (vivo) {
		if (uniTestarColisao(sprite, posicao.x, posicao.y, 0, s, p.x, p.y, 0))
		{
			vivo = false;
			gAudios.tocar("somMoeda", 50);
		}
	}

}

void Objeto::desenhar()
{
	if (vivo)
		sprite.desenhar(posicao.x, posicao.y);
}

void Objeto::resetar()
{
	vivo = true;
}
