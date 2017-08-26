#include <iostream>
#include <stdio.h>
#include "matriz.hpp"
#include "glider.hpp"
#include "linha.hpp"

//Função para a estrutura do print, numeração horizontal
void bordaH(int ger){
	int i;

	cout << endl << "GERAÇÃO "<< ger << endl;
	cout << "   ";
	for (i = 0; i < 20; i++) {
		if (i< 9) {
			cout << (i+1) << "  ";
		}else{
			cout << (i+1) << " ";
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

int quantVivas(Matriz matriz, int lin, int col){
	int vivas = 0;
	if (matriz.getCell(lin-1, col-1) == '*'){
		vivas++;
	}
	if (matriz.getCell(lin-1, col) == '*'){
		vivas++;
	}
	if (matriz.getCell(lin-1, col+1) == '*'){
		vivas++;
	}

	if (matriz.getCell(lin, col-1) == '*'){
		vivas++;
	}
	if (matriz.getCell(lin, col+1) == '*'){
		vivas++;
	}

	if (matriz.getCell(lin+1, col-1) == '*'){
		vivas++;
	}
	if (matriz.getCell(lin+1, col) == '*'){
		vivas++;
	}
	if (matriz.getCell(lin+1, col+1) == '*'){
		vivas++;
	}

	return vivas;
}

Matriz escolheMatriz(char m){
	Linha linha;
	Glider glider;
	Matriz hab;
	int lin, col, ger;
	char var;

	if (m == 'g') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = glider.getCell(lin,col);
				ger = glider.getGeracoes();
				hab.setCell(var,lin,col);
				hab.setGeracoes(ger);
			}
		}
	}else if (m == 'l') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = linha.getCell(lin,col);
				ger = linha.getGeracoes();
				hab.setCell(var,lin,col);
				hab.setGeracoes(ger);
			}
		}
	}
	return hab;
}

Matriz f5(Matriz hab){
	int lin,col;
	char var;
	Matriz mem;

	for (lin = 0; lin < 20; lin++) {
		for (col = 0; col < 20; col++) {
			var = hab.getCell(lin,col);
			mem.setCell(var, lin, col);
		}
	}
	return mem;
}


int main(int argc, char ** argv) {
	Linha l;
	Glider g;
	Matriz habtat, memoria;
	int linha, coluna, geracao, times = 0, lin, col, vivas;
	char m;

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


	habtat = escolheMatriz(m);
	memoria = f5(habtat);

	//Começa o loop que da a vida
	while (times < habtat.getGeracoes()) {
		times++;
		bordaH(times);

		//Começando a ler a matriz
		for(linha = 0; linha < 20; linha++){
			bordaV(linha);

			//Entra no 2o for para efetuar a real leitura dos elementos
			for(coluna = 0; coluna < 20; coluna++){

				cout << habtat.getCell(linha, coluna) << "  ";

				if (linha > 0 && linha < 19 && coluna > 0 && coluna < 19) {

					vivas = quantVivas(memoria, linha,coluna);

					if (habtat.getCell(linha,coluna) == '*' && (vivas < 2 || vivas > 3)) {
						habtat.setCell('-',linha,coluna);
					}else if(habtat.getCell(linha,coluna) == '-' && vivas == 3){
						habtat.setCell('*',linha,coluna);
					}else if(habtat.getCell(linha,coluna) == '*' && (vivas == 2 || vivas == 3)){
						habtat.setCell('*',linha,coluna);
					}
				}
			}
			cout << endl;
		}
		memoria = f5(habtat);
	}


	return 0;
}
