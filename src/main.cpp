#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include "matriz.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"

Matriz escolheMatriz(char m){
	// Esta função, a partir da letra da resposta do usuario devolve a matriz escolhida
	Quadrado quadrado;
	Blinker blinker;
	Glider glider;
	GliderGun gun;
	Matriz habtat;

	if (m == 'q') {
		habtat = quadrado;
	}else if (m == 'b') {
		habtat = blinker;
	}else if (m == 'g') {
		habtat = glider;
	}else if (m == 'u') {
		habtat = gun;
	}

	return habtat;
}

int main(int argc, char ** argv) {
	Matriz habtat, memoria;
	int linha, coluna, geracao, times = 0, vivas, tamanho, cellVivas = 1;
	char resposta, m;

	// Menu inicial:
	cout << "Qual conjunto de celulas você gostaria de rodar?" << endl;
	printf("DIGITE:\n Q para Quadrado\n B para Blinker\n G para Glider\n"
		" U para Glider Gun\n M para montar seu conjunto de celulas\n A "
		"para um conjunto aleatorio\n\n");
	scanf(" %c", &m);
	cout << endl;

	if (m < 97) {
		m = m + 32;
	}

	while (m != 'g' && m != 'b' && m !='u' && m != 'm' && m!= 'q' && m!= 'a') {
		cout << "\n\nERRO: SEU CONJUNTO INICIAL NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
		scanf(" %c", &m);
		cout << endl;
	}

	if (m == 'm') {
		habtat.montaMatriz();
	}else if (m == 'a'){
		habtat.montaAleatoria();
	}else{
		habtat = escolheMatriz(m);
	}

	memoria = habtat;
	tamanho = habtat.getTamanho();

	cout << endl;
	cout << "Você escolheu: " <<  habtat.getNome() << endl;
	cout << " - É uma matriz "<<habtat.getTamanho()<<"X"<<habtat.getTamanho()<< endl;
	cout << " - Possui " << habtat.getGeracoes() << " gerações" << endl;

	cout << "\nDeseja alterar a quantidade de gerações das suas celulas? (S/N) ";
	scanf(" %c", &resposta);
	cout << endl;

	while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N'){
		cout << "\n\nERRO: ESCREVA 'S' PARA SIM E 'N' PARA NÃO\n\nTente novamente: ";
		scanf(" %c", &resposta);
		cout << endl;
	}

	if (resposta == 's' || resposta == 'S') {
		cout << "GERAÇÕES: ";
		scanf("%d", &geracao);
		habtat.setGeracoes(geracao);
	}


	if (tamanho > 20) {
		cout << "\n\nOBS.: Maximize sua tela para melhor visualização.\n\n" << endl;
		sleep(1);
	}


	//Começa o loop do jogo
	while (times < habtat.getGeracoes() && cellVivas > 0) {
		times++;
		habtat.printBordaHorizontal(times);

		//Começando a ler a matriz
		for(linha = 0; linha < tamanho; linha++){
			habtat.printBordaVertical(linha);

			//Entra no 2o for para efetuar a real leitura e print dos elementos
			for(coluna = 0; coluna < tamanho; coluna++){

				cout << habtat.getCell(linha, coluna) << "  ";

				if (linha > 0 && linha < (tamanho-1) && coluna > 0 && coluna < (tamanho-1)) {
					vivas = memoria.contaVivas(linha,coluna);

					// REGRAS DO JOGO DA VIDA:
					if (habtat.getCell(linha,coluna) == 'o' && (vivas < 2 || vivas > 3)) {
						habtat.setCell(' ',linha,coluna);
					}else if(habtat.getCell(linha,coluna) == ' ' && vivas == 3){
						habtat.setCell('o',linha,coluna);
					}else if(habtat.getCell(linha,coluna) == 'o' && (vivas == 2 || vivas == 3)){
						habtat.setCell('o',linha,coluna);
					}
				}
			}
			cout << endl;
		}

		cellVivas = 0;

		for (linha = 0; linha < 40; linha++) {
			for (coluna = 0; coluna < 40; coluna++) {
				if (memoria.getCell(linha, coluna) == 'o'){
					cellVivas++;
				}
			}
		}

		if (cellVivas == 0) {
			cout << endl << "Suas celulas morreram." << endl;
		}

		memoria = habtat;

		usleep(250000);
	}


	return 0;
}
