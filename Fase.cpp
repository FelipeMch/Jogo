#include "Fase.h"

void Fase::inicializar(Personagem* personagem)
{
	if (!gRecursos.carregouSpriteSheet("background"))
		gRecursos.carregarSpriteSheet("background", "bin/assets/imagens/praiainicial.png", 1, 3);


	fundo.setSpriteSheet("background");


	//Inicialização do Personagem e objetos.
	persoPrincipal = personagem; // associa personagem do jogo com o da fase;
	persoPrincipal->inicializar();
	for (int c = 0; c < 2; c++)
		cocos[c].inicializar("somcoco", "bin/assets/audios/cocosom.mp3", "coco", "bin/assets/imagens/cocoteste.png", 1, 1, 300, 0 + c * -80, 10, true);
	for (int g = 0; g < 2; g++)
		guardas[g].inicializar("apito", "bin/assets/audios/apito.mp3", "guarda", "bin/assets/imagens/guardateste.png", 1, 1, 600, -60, -500, false);
	tubarao.inicializar("facada", "bin/assets/audios/somfaca.mp3", "tubarao", "bin/assets/imagens/tubaraonovo.png", 2, 2, 320, -200, -100, true);


	//Inicialação do tempo.
	tInicio = gTempo.getTicks();
	gRecursos.carregarFonte("fonte", "bin/assets/fontes/fonte.ttf", 17);
	texto.setFonte("fonte");
	texto.setCor(3, 0, 147);


	posicoes[0].x = gJanela.getLargura() / 2;
	posicoes[0].y = gJanela.getAltura() / 2;
	posicoes[1].x = gJanela.getLargura() / 2;
	posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	velocidade = 1;

}

void Fase::desenhar()
{
	fundo.desenhar(posicoes[0].x, posicoes[0].y);
	fundo.desenhar(posicoes[1].x, posicoes[1].y);
	fundo.avancarAnimacao();
	fundo.setVelocidadeAnimacao(0.6);
	persoPrincipal->desenhar();
	for (int c = 0; c < 2; c++)
		cocos[c].desenhar();
	guardas[0].desenhar();
	if (tempo > 50)
		guardas[1].desenhar();
	tubarao.desenhar();
}

void Fase::executar()
{
	//Atualizações de tempo
	tempo = gTempo.getTempoAteTickAtual(tInicio);
	texto.setString("Tempo " + to_string(tempo));
	texto.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 10);

	//Movimentação da fase
	controladorVelocidade();

	//Atualizações das execuções
	persoPrincipal->executar();
	for (int c = 0; c < 2; c++)
		cocos[c].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());
	guardas[0].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());
	if (tempo > 50)
		guardas[1].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());
	tubarao.executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());

	//Atualizações das colisões
	for (int c = 0; c < 2; c++)
		persoPrincipal->atualizarColisao(cocos[c].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), cocos[c].getDestrutivel());
	persoPrincipal->atualizarColisao(guardas[0].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), guardas[0].getDestrutivel());
	if (tempo > 50)
		persoPrincipal->atualizarColisao(guardas[1].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), guardas[1].getDestrutivel());
	persoPrincipal->atualizarColisao(tubarao.executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), tubarao.getDestrutivel());


	//Atualizações de colisão dos objetos
	for (int c = 0; c < 2; c++)
	{
		cocos[c].testarColisao(tubarao.getposicao(), tubarao.getSprite());
		cocos[c].testarColisao(guardas[0].getposicao(), guardas[0].getSprite());
		cocos[0].testarColisao(cocos[1].getposicao(), cocos[1].getSprite());
		if (tempo > 50)
			cocos[c].testarColisao(guardas[1].getposicao(), guardas[1].getSprite());

	}
	for (int g = 0; g < 2; g++)
		guardas[g].testarColisao(tubarao.getposicao(), tubarao.getSprite());

	if (tempo > 50)
		guardas[0].testarColisao(guardas[1].getposicao(), guardas[1].getSprite());
}

void Fase::finalizar()
{
	gRecursos.descarregarSpriteSheet("background");
	persoPrincipal->finalizar();
	for (int c = 0; c < 2; c++)
		cocos[c].finalizar();
	for (int g = 0; g < 2; g++)
		guardas[g].finalizar();
	tubarao.finalizar();
}

void Fase::controladorVelocidade()
{
	if (tempo >= 20)
		if (posicoes[0].y == gJanela.getAltura() / 2)
			velocidade = 2;
	if (tempo >= 100)
		if (posicoes[0].y == gJanela.getAltura() / 2)
			velocidade = 4;
	if (tempo >= 200)
		if (posicoes[0].y == gJanela.getAltura() / 2)
			velocidade = 8;

	posicoes[0].y = posicoes[0].y + velocidade;
	posicoes[1].y = posicoes[1].y + velocidade;
	if (posicoes[0].y == gJanela.getAltura() / 2)
		posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	if (posicoes[1].y == gJanela.getAltura() / 2)
		posicoes[0].y = gJanela.getAltura() / 2 - gJanela.getAltura();
}
