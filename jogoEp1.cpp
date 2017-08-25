#include <iostream>
#include <stdio.h>
#include "matriz.hpp"
#include "glider.hpp"
#include "linha.hpp"

//Função para a estrutura do print, numeração horizontal
void bordaH(int g){
	int l;

	cout << endl << "GERAÇÃO "<< g << endl;
	cout << "   ";
	for (l = 0; l < 20; l++) {
		if (l< 9) {
			cout << (l+1) << "  ";
		}else{
			cout << (l+1) << " ";
		}
	}
	cout << endl;
}

//Função para o print vertical
void bordaV(int i) {
	if (i < 9) {
		cout << (i+1) << "  ";
	}else{
		cout << (i+1) << " ";
	}
}

int quantVivas(char matriz[20][20], int i, int j){
	int vivas = 0;
	if (matriz[i-1][j-1] == '*'){
		vivas++;
	}
	if (matriz[i-1][j] == '*'){
		vivas++;
	}
	if (matriz[i-1][j+1] == '*'){
		vivas++;
	}

	if (matriz[i][j-1] == '*'){
		vivas++;
	}
	if (matriz[i][j+1] == '*'){
		vivas++;
	}

	if (matriz[i+1][j-1] == '*'){
		vivas++;
	}
	if (matriz[i+1][j] == '*'){
		vivas++;
	}
	if (matriz[i+1][j+1] == '*'){
		vivas++;
	}

	return vivas;
}

int main(int argc, char ** argv) {
	Linha l;
	Glider g;
	int linha, coluna, geracao, times = 0, lin, col, vivas;
	char memoria[20][20], hab[20][20], m;

	printf("Qual matriz você gostaria de rodar?\n");
	printf("DIGITE:\n G para a matriz glider\n L para a matriz linha\n");
	scanf("%c", &m);

	if (m < 97) {
		m = m + 32;
	}

	while (m != 'g' && m!= 'l') {
		printf("\nERRO: NÃO ACHAMOS SUA MATRIZ INICIAL.\n\nEscreva novamente: ");
		scanf("%c", &m);
	}

	if (m == 'g') {
		for (linha = 0; linha < 20; linha++) {
			for (coluna = 0; coluna < 20; coluna++) {
				hab[linha][coluna] = g.getCell(linha, coluna);
				memoria[linha][coluna] = g.getCell(linha, coluna);
				geracao = g.getGeracoes();
			}
		}
	}else if (m == 'l') {
		for (linha = 0; linha < 20; linha++) {
			for (coluna = 0; coluna < 20; coluna++) {
				hab[linha][coluna] = l.getCell(linha, coluna);
				memoria[linha][coluna] = l.getCell(linha, coluna);
				geracao = l.getGeracoes();
			}
		}
	}


	//Começa o loop que da a vida
	while (times < geracao) {
		times++;
		bordaH(times);

		//Começando a ler a matriz
		for(linha = 0; linha < 20; linha++){
			bordaV(linha);

			//Entra no 2o for para efetuar a real leitura dos elementos
			for(coluna = 0; coluna < 20; coluna++){

				cout << hab[linha][coluna] << "  ";

				if (linha > 0 && linha < 19 && coluna > 0 && coluna < 19) {

					vivas = quantVivas(memoria, linha,coluna);

					if (hab[linha][coluna] == '*' && (vivas < 2 || vivas > 3)) {
						hab[linha][coluna] = '-';
					}else if(hab[linha][coluna] == '-' && vivas == 3){
						hab[linha][coluna] = '*';
					}else if(hab[linha][coluna] == '*' && (vivas == 2 || vivas == 3)){
						hab[linha][coluna] = '*';
					}
				}
			}
			cout << endl;
		}
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				memoria[lin][col] = hab[lin][col];
			}
		}
	}


	return 0;
}
