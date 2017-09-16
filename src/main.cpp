#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "matriz.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"

int main(int argc, char ** argv) {
	Quadrado quadrado;
	Blinker blinker;
	Glider glider;
	GliderGun gun;
	Matriz habtat, memoria;
	int linha, coluna, geracao, contador = 0, vivas, tamanho, celulasVivas = 1;
	char resposta;

	// Menu inicial, onde o usuario escolhe a matriz do jogo
	cout << "Qual conjunto de celulas você gostaria de rodar?" << endl;

	cout << "DIGITE:\n Q para Quadrado\n B para Blinker\n G para Glider\n"
		<< " U para Glider Gun\n A para um conjunto aleatorio\n M para montar"
		<< " seu próprio conjunto\n E para escrever seu conjunto de celulas\n"
		<< endl;

	cin >> resposta;
	cout << endl;

	if (resposta < 97) {
		// Transforma as letras maiúsculas da resposta do usuario em minusculas
		resposta = resposta + 32;
	}

	while (resposta != 'e' && resposta != 'g' && resposta != 'b' && resposta !='u'
	&& resposta != 'm' && resposta!= 'q' && resposta!= 'a') {
		cout << "\n\nERRO: SEU CONJUNTO INICIAL NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
		cin >> resposta;
		cout << endl;
	}

	// Nessa sequencia de ifs, a matriz desejada é formada
	if (resposta == 'e') {
		habtat.escreveMatriz();
	}else if (resposta == 'a'){
		habtat.montaAleatoria();
	}else if(resposta == 'm'){
		habtat.juntaMatriz();
	}else if (resposta == 'q') {
		habtat = quadrado;
	}else if (resposta == 'b') {
		habtat = blinker;
	}else if (resposta == 'g') {
		habtat = glider;
	}else if (resposta == 'u'){
		habtat = gun;
	}

	memoria = habtat;
	tamanho = habtat.getTamanho();

	cout << endl;
	cout << "Você escolheu: " <<  habtat.getNome() << endl;
	cout << " - É uma matriz "<< habtat.getTamanho() << "X" << habtat.getTamanho() << endl;
	cout << " - Possui " << habtat.getGeracoes() << " gerações" << endl;

	cout << "\nDeseja alterar a quantidade de gerações das suas celulas? (S/N) ";
	cin >> resposta;
	cout << endl;

	while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N'){
		cout << "\n\nERRO: ESCREVA 'S' PARA SIM E 'N' PARA NÃO\n\nTente novamente: ";
		cin >> resposta;
		cout << endl;
	}

	if (resposta == 's' || resposta == 'S') {
		// Mudança na quantidade de geraçoes
		cout << "GERAÇÕES: ";
		cin >> geracao;
		habtat.setGeracoes(geracao);
	}

	if (tamanho > 20) {
		// A mensagem a seguir aparece quando a matriz for muito grande, pois não
		//poderá ser devidamente visualizada com a tela pequena. A função sleep foi
		//utilizada para o usuario ter tempo de ver a mensagem.
		cout << "\n\nOBS.: Maximize sua tela para melhor visualização.\n\n" << endl;
		sleep(1);
	}


	//Começa o loop do jogo
	while (contador < habtat.getGeracoes() && celulasVivas > 0) {
		contador++;
		habtat.printBordaHorizontal(contador);

		for(linha = 0; linha < tamanho; linha++){
			habtat.printBordaVertical(linha);

			for(coluna = 0; coluna < tamanho; coluna++){
				//Print das celulas
				cout << habtat.getCelula(linha, coluna) << "  ";

				// Contagem das celulas vivas vizinhas
				vivas = memoria.contaVivas(linha,coluna);

				// REGRAS DO JOGO DA VIDA:
				if (habtat.getCelula(linha,coluna) == 'o' && (vivas < 2 || vivas > 3)) {
					habtat.setCelula(' ',linha,coluna);
				}else if(habtat.getCelula(linha,coluna) == ' ' && vivas == 3){
					habtat.setCelula('o',linha,coluna);
				}else if(habtat.getCelula(linha,coluna) == 'o' && (vivas == 2 || vivas == 3)){
					habtat.setCelula('o',linha,coluna);
				}
			}
			cout << endl;
		}

		// Contagem das celulas vivas no jogo
		celulasVivas = memoria.contaVivas();

		if (celulasVivas == 0) {
			// O jogo acaba com essa mensagem quando não há mais celulas
			cout << endl << "Suas celulas morreram." << endl;
		}

		memoria = habtat;

		// A função usleep foi utilizada para que cada geração fosse impressa com
		//1/4 de segundo de tempo entre elas, dessa forma, o jogo parece ser animado
		usleep(250000);
	}

	return 0;
}
