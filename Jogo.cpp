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

	if(!gRecursos.carregouMusica("praiafundo"))
		gRecursos.carregarMusica("praiafundo", "bin/assets/audios/praia.mp3", 20);
	if (!gRecursos.carregouSpriteSheet("fundoInicial"))
		gRecursos.carregarSpriteSheet("fundoInicial", "bin/assets/imagens/praiainicial.png", 1, 3);

	background.setSpriteSheet("fundoInicial");

	
	gRecursos.carregarSpriteSheet("bJogar", "bin/assets/botoes/jogar.png", 3);
	botoes[bJogar].setSpriteSheet("bJogar");
	botoes[bJogar].setPos(gJanela.getLargura() / 2, 500);

	gRecursos.carregarSpriteSheet("bCreditos", "bin/assets/botoes/creditos.png", 3);
	botoes[bCreditos].setSpriteSheet("bCreditos");
	botoes[bCreditos].setPos(gJanela.getLargura() / 2, 550);

	gRecursos.carregarSpriteSheet("bInstrucoes", "bin/assets/botoes/instrucoes.png", 3);
	botoes[bInstrucoes].setSpriteSheet("bInstrucoes");
	botoes[bInstrucoes].setPos(gJanela.getLargura() / 2, 600);

	gRecursos.carregarSpriteSheet("bSair", "bin/assets/botoes/sair.png", 3);
	botoes[bSair].setSpriteSheet("bSair");
	botoes[bSair].setPos(gJanela.getLargura() / 2, 650);

	gRecursos.carregarSpriteSheet("bOk", "bin/assets/botoes/ok.png", 3);
	botoes[bOk].setSpriteSheet("bOk");
	botoes[bOk].setPos(gJanela.getLargura() / 2, 400);

	gRecursos.carregarSpriteSheet("bVoltar", "bin/assets/botoes/voltar.png", 3);
	botoes[bVoltar].setSpriteSheet("bVoltar");
	botoes[bVoltar].setPos(gJanela.getLargura() / 2, 400);
	
	telaAtual = tInicial;

	

}

void Jogo::executar()
{
	while(telaAtual != tSaida && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
			case tInicial: telaInicial();
					break;
		
			case tJogo: telaJogo();
				break;
		
			case tCreditos: telaCreditos();
				break;
		
			case tInstrucoes: telaInstrucoes();
				break;
		
			case tGameOver: telaGameOver();
				break;
		}

		uniTerminarFrame();
	}
}

void Jogo::finalizar()
{
	
	fase.finalizar();
	gRecursos.descarregarTudo();
	
	uniFinalizar();
}

void Jogo::telaInicial()
{
	//Fundo e música
	background.desenhar(425, 400);
	background.avancarAnimacao();
	background.setVelocidadeAnimacao(0.4);
	if(!gMusica.estaTocando())
		gMusica.tocar("praiafundo", 10);

	//Inicio das Telas
	botoes[bJogar].atualizar();
	botoes[bJogar].desenhar();
	if (botoes[bJogar].estaClicado())
	{
		telaAtual = tJogo;
		fase.inicializar(&personagem); //& pega o endereço do personagem na memória
	}

	botoes[bCreditos].atualizar();
	botoes[bCreditos].desenhar();
	if (botoes[bCreditos].estaClicado())
	{
		telaAtual = tCreditos;
	}

	botoes[bInstrucoes].atualizar();
	botoes[bInstrucoes].desenhar();
	if (botoes[bInstrucoes].estaClicado())
	{
		telaAtual = tInstrucoes;
	}

	botoes[bSair].atualizar();
	botoes[bSair].desenhar();
	if (botoes[bSair].estaClicado())
	{
		telaAtual = tSaida;
	}
}

void Jogo::telaJogo()
{
	gMusica.parar();
	fase.desenhar();
	fase.executar();
	
	if (personagem.getMorte() == false)
	{
		telaAtual = tGameOver;
	}

}

void Jogo::telaCreditos()
{
	background.desenhar(425, 400);
	background.avancarAnimacao();
	background.setVelocidadeAnimacao(0.4);
	botoes[bOk].atualizar();
	botoes[bOk].desenhar();
	if (botoes[bOk].estaClicado())
	{
		telaAtual = tInicial;
	}
}

void Jogo::telaInstrucoes()
{
	background.desenhar(425, 400);
	background.avancarAnimacao();
	background.setVelocidadeAnimacao(0.4);
	botoes[bVoltar].atualizar();
	botoes[bVoltar].desenhar();
	if (botoes[bVoltar].estaClicado())
	{
		telaAtual = tInicial;
	}

}

void Jogo::telaGameOver()
{
}
