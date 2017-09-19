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

int main(int argc, char ** argv) {
	Block block;
	Blinker blinker;
	Glider glider;
	GliderGun gun;
	Matriz habtat, memoria;
	int linha, coluna, geracao, contador = 0, vizinhasVivas, celulasVivas = 1;
	char resposta;


	// Menu inicial, onde o usuario escolhe a matriz do jogo
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
			// Transforma as letras maiúsculas da resposta do usuario em minúsculas
			resposta = resposta + 32;
		}
	}

	try{
		// Nessa sequência de ifs, a matriz desejada é formada, o try e o catch
		//asseguram de que ela seja montada devidamente
		if (resposta == 'e') {
			habtat.escreveMatriz();
		}else if (resposta == 'a'){
			habtat.montaAleatoria();
		}else if(resposta == 'm'){
			habtat.juntaMatriz();
		}else if (resposta == 'k') {
			habtat = block;
		}else if (resposta == 'b') {
			habtat = blinker;
		}else if (resposta == 'g') {
			habtat = glider;
		}else if (resposta == 'u'){
			habtat = gun;
		}
	}catch(int excecao){
		// Caso o programa capture uma exceção, o programa será parado com
		//a mensagem de erro.
		cout << "\nERRO: SEU CONJUNTO NÃO FOI MONTADO DEVIDAMENTE" << endl;
		habtat.setGeracoes(0);
	}

	memoria = habtat;

	if (habtat.getGeracoes() > 0) {
		system("clear");

		cout << "JOGO DA VIDA\n" << endl;

		// Esse if garante que os próximos passos só serão efetuados se o jogo foi
		//devidamente montado.
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
			cout << "GERAÇÕES: ";
			cin >> geracao;
			try{
				habtat.setGeracoes(geracao);
			}catch(int excecao){
				cout << "ERRO: NÚMERO DE GERAÇÕES INVÁLIDO." << endl;
				habtat.setGeracoes(0);
			}
		}
	}

	//Começa o loop do jogo
	while (contador < habtat.getGeracoes() && celulasVivas > 0) {
		contador++;
		// A função system("clear") está sendo ultilizada para limpar a tela do
		//terminal entre a mudança de gerações
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

	return 0;
}
