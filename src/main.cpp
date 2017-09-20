/*
	Aluna: Gabriela Barrozo Guedes
	Matricula: 16/0121612
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "matriz.hpp"
#include "block.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"

int testaTamanho(){
	int tamanho;

	cout << "(OBS : Escreva somente 1 número para o TAMANHO, pois a matriz é"
	<< " quadrada, tem o mesmo número para linhas e colunas)"<< endl;
	cout << "Tamanho da matriz: ";
	cin >> tamanho;

	if(tamanho < 1 || tamanho > 90){
		throw(1);
	}else{
		return tamanho;
	}
}

int testaGeracao(){
	int geracao;

	cout << "GERAÇÕES: ";
	cin >> geracao;

	if(geracao < 1 || geracao == '\0'){
		throw(1);
	}else{
		return geracao;
	}
}

int main(int argc, char ** argv) {
	Block block;
	Blinker blinker;
	Glider glider;
	GliderGun gun;
	Matriz habtat, memoria;
	int linha, coluna, tamanho, geracao, contador = 0, vizinhasVivas, celulasVivas = 1, erro = 0;
	char resposta;

	// Menu inicial, onde o usuario escolhe a matriz do jogo
	// A função system("clear") está sendo ultilizada para limpar a tela do
	//terminal entre a mudança de telas
	system("clear");
	cout << "BEM VINDO(A) AO JOGO DA VIDA! \n\n" << endl;
	cout << "Qual conjunto de células você gostaria de rodar?" << endl;

	cout << "DIGITE:\n B para Blinker\n K para Block\n G para Glider\n"
	<< " U para Gosper Glider Gun\n A para um conjunto aleatorio\n M para montar"
	<< " seu próprio conjunto\n E para escrever seu conjunto de células\n"
	<< endl;
	cin >> resposta;
	cout << endl;

	if (resposta < 97) {
		// Transforma as letras maiúsculas da resposta do usuario em minúsculas
		resposta = resposta + 32;
	}

	while (resposta != 'e' && resposta != 'g' && resposta != 'b' && resposta !='u'
	&& resposta != 'm' && resposta!= 'k' && resposta!= 'a') {
		cout << "\n\nERRO: SEU CONJUNTO INICIAL NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
		cin >> resposta;
		cout << endl;

		if (resposta < 97) {
			resposta = resposta + 32;
		}
	}

	// Nessa sequência de ifs, a matriz desejada é formada, o try e o catch
	//asseguram de que ela seja montada devidamente
	if(resposta == 'e' || resposta == 'm'){
		habtat.escolheNome();
	}
	if (resposta == 'a' || resposta == 'e' || resposta == 'm') {
		try{
			tamanho = testaTamanho();
			habtat.setTamanho(tamanho);
		}catch(int excecao){
			// Caso o programa capture uma exceção, o programa será parado com
			//a mensagem de erro.
			cout << "ERRO: O JOGO NÃO SUPORTA UMA MATRIZ DESTE TAMANHO." << endl;
			sleep(1);
			erro = 1;
		}
	}
	if (resposta == 'e'&& erro == 0) {
		habtat.escreveMatriz();
	}else if (resposta == 'a'&& erro == 0){
		habtat.montaAleatoria();
	}else if(resposta == 'm' && erro == 0){
		try{
			habtat.juntaMatriz();
		}catch(int excecao){
			cout << "ERRO: A POSIÇÃO NÃO PERTENCE A MATRIZ DO JOGO." << endl;
			sleep(1);
			erro = 1;
		}
	}else if (resposta == 'k') {
		habtat = block;
	}else if (resposta == 'b') {
		habtat = blinker;
	}else if (resposta == 'g') {
		habtat = glider;
	}else if (resposta == 'u'){
		habtat = gun;
	}

	memoria = habtat;

	if(!erro){
		// Esse if garante que os próximos passos só serão efetuados se o jogo foi
		//devidamente montado.
		system("clear");
		cout << "JOGO DA VIDA\n" << endl;
		habtat.printBordaHorizontal();
		habtat.printJogo();
		cout << endl;

		cout << endl;
		cout << "Você escolheu: " <<  habtat.getNome() << endl;
		cout << " - É uma matriz "<< habtat.getTamanho() << "X" << habtat.getTamanho() << endl;
		cout << " - Possui " << habtat.getGeracoes() << " gerações" << endl;

		cout << "\nDeseja alterar a quantidade de gerações das suas células? (S/N) ";
		cin >> resposta;
		cout << endl;

		while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N'){
			cout << "\n\nERRO: ESCREVA 'S' PARA SIM E 'N' PARA NÃO\n\nTente novamente: ";
			getchar();
			cin >> resposta;
			cout << endl;
		}

		if (resposta == 's' || resposta == 'S') {
			// Mudança na quantidade de gerações
			// Mudança na quantidade de gerações
			try{
				geracao = testaGeracao();
				habtat.setGeracoes(geracao);
			}catch(int excecao){
				cout << "ERRO: NÚMERO DE GERAÇÕES INVÁLIDO." << endl;
				sleep(1);
				erro = 1;
			}
		}
	}

	//Começa o loop do jogo
	while (contador < habtat.getGeracoes() && celulasVivas > 0 && erro == 0) {
		contador++;

		system("clear");
		cout << "JOGO DA VIDA" << endl;

		// Impressão do jogo
		habtat.printBordaHorizontal(contador);
		habtat.printJogo();

		for(linha = 0; linha < 100; linha++){
			for(coluna = 0; coluna < 100; coluna++){
				// Contagem das células vivas vizinhas
				vizinhasVivas = memoria.contaVivas(linha,coluna);

				// REGRAS DO JOGO DA VIDA:
				if (habtat.getCelula(linha,coluna) == 'o' && (vizinhasVivas < 2
					|| vizinhasVivas > 3)) {
						habtat.setCelula(' ',linha,coluna);
					}else if(habtat.getCelula(linha,coluna) == ' ' && vizinhasVivas == 3){
						habtat.setCelula('o',linha,coluna);
					}else if(habtat.getCelula(linha,coluna) == 'o' && (vizinhasVivas == 2
						|| vizinhasVivas == 3)){
							habtat.setCelula('o',linha,coluna);
						}
					}
				}

				// Contagem das células vivas no jogo inteiro
				celulasVivas = memoria.contaVivas();

				if (celulasVivas == 0) {
					// O jogo acaba com essa mensagem quando não há mais células
					cout << endl << "Suas células morreram." << endl;
				}

				memoria = habtat;

				// A função usleep foi utilizada para que cada geração fosse impressa com
				//1/4 de segundo de tempo entre elas, dessa forma o jogo parece ser animado
				usleep(250000);
			}

			//Tela de fim de jogo
			sleep(1);
			system("clear");
			cout << "JOGO DA VIDA\n\n" << endl;
			cout << "FIM DE JOGO!\n"<< endl;
			cout << "Para jogar novamente digite: MAKE RUN\n\n" << endl;



	return 0;
}
