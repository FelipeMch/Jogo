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
	if (!gRecursos.carregouSpriteSheet("telaCreditos"))
		gRecursos.carregarSpriteSheet("telaCreditos", "bin/assets/imagens/fundocreditos.png", 1, 1);
	creditosBackground.setSpriteSheet("telaCreditos");
	if (!gRecursos.carregouSpriteSheet("telaInstrucoes"))
		gRecursos.carregarSpriteSheet("telaInstrucoes", "bin/assets/imagens/fundoInstrucoes.png", 1, 1);
	instrucoesBackground.setSpriteSheet("telaInstrucoes");

	if(!gRecursos.carregouFonte("fonteMenu"))
		gRecursos.carregarFonte("fonteMenu", "bin/assets/fontes/menu.ttf", 13);
	texto.setFonte("fonteMenu");
	texto.setCor(3, 0, 147);

	
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
	botoes[bOk].setPos(750, 750);

	gRecursos.carregarSpriteSheet("bVoltar", "bin/assets/botoes/voltar.png", 3);
	botoes[bVoltar].setSpriteSheet("bVoltar");
	botoes[bVoltar].setPos(750, 750);
	
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
	creditosBackground.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
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
	instrucoesBackground.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	botoes[bVoltar].atualizar();
	botoes[bVoltar].desenhar();
	if (botoes[bVoltar].estaClicado())
	{
		telaAtual = tInicial;
	}

}

void Jogo::telaGameOver()
{
	if (!gMusica.estaTocando())
		gMusica.tocar("praiafundo", 10);
	background.desenhar(425, 400);
	background.avancarAnimacao();
	background.setVelocidadeAnimacao(0.4);
	botoes[bVoltar].atualizar();
	botoes[bVoltar].desenhar();
	if (botoes[bVoltar].estaClicado())
	{
		telaAtual = tInicial;
	}

	texto.setString("Você fez um tempo de " + to_string(fase.getTempo()) + " segundos.");
	texto.desenhar(250, 180);
	texto.setString("Coletou " + to_string(personagem.getCocos()) + " cocos.");
	texto.desenhar(250, 240);
	texto.setString("Fatiou " + to_string(personagem.getTubaroes()) + " vezes os tubarões. Brabo!");
	texto.desenhar(250, 300);
	
}
