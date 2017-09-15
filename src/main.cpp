#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "matriz.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"

Matriz escolheMatriz(char letra){
	// Esta função, a partir da letra da resposta do usuario, devolve a matriz escolhida
	Quadrado quadrado;
	Blinker blinker;
	Glider glider;
	GliderGun gun;

	if (letra == 'q') {
		return quadrado;
	}else if (letra == 'b') {
		return blinker;
	}else if (letra == 'g') {
		return glider;
	}else{
		return gun;
	}
}

int main(int argc, char ** argv) {
	Matriz habtat, memoria;
	int linha, coluna, geracao, contador = 0, vivas, tamanho, celulasVivas = 1;
	char resposta;

	// Menu inicial:
	cout << "Qual conjunto de celulas você gostaria de rodar?" << endl;

	cout << "DIGITE:\n Q para Quadrado\n B para Blinker\n G para Glider\n";
	cout << " U para Glider Gun\n D para desenhar seu conjunto de celulas\n A ";
	cout << "para um conjunto aleatorio\n M para montar seu próprio conjunto\n"
	<< endl;

	cin >> resposta;
	cout << endl;

	if (resposta < 97) {
		resposta = resposta + 32;
	}

	while (resposta != 'd' && resposta != 'g' && resposta != 'b' && resposta !='u'
	&& resposta != 'm' && resposta!= 'q' && resposta!= 'a') {
		cout << "\n\nERRO: SEU CONJUNTO INICIAL NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
		cin >> resposta;
		cout << endl;
	}

	if (resposta == 'd') {
		habtat.montaMatriz();
	}else if (resposta == 'a'){
		habtat.montaAleatoria();
	}else if(resposta == 'm'){
		habtat.juntaMatriz();
	}else{
		habtat = escolheMatriz(resposta);
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
		cout << "GERAÇÕES: ";
		cin >> geracao;
		habtat.setGeracoes(geracao);
	}

	if (tamanho > 20) {
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

				cout << habtat.getCelula(linha, coluna) << "  ";

				if (linha > 0 && linha < (tamanho-1) && coluna > 0 && coluna < (tamanho-1)) {
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
			}
			cout << endl;
		}

		celulasVivas = memoria.contaVivas();

		if (celulasVivas == 0) {
			cout << endl << "Suas celulas morreram." << endl;
		}

		memoria = habtat;

		usleep(250000);
	}

	return 0;
}
