#include <iostream>
#include <stdio.h>
#include "matriz.hpp"
#include "glider.hpp"
#include "linha.hpp"
#include "gliderGun.hpp"
#include <string>

//Função para a estrutura do print, numeração horizontal
void bordaH(int ger, int tam){
	int i;

	cout << endl << "GERAÇÃO "<< ger << endl;
	cout << "   ";
	for (i = 0; i < tam; i++) {
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
	if (matriz.getCell(lin-1, col-1) == 'o'){
		vivas++;
	}
	if (matriz.getCell(lin-1, col) == 'o'){
		vivas++;
	}
	if (matriz.getCell(lin-1, col+1) == 'o'){
		vivas++;
	}

	if (matriz.getCell(lin, col-1) == 'o'){
		vivas++;
	}
	if (matriz.getCell(lin, col+1) == 'o'){
		vivas++;
	}

	if (matriz.getCell(lin+1, col-1) == 'o'){
		vivas++;
	}
	if (matriz.getCell(lin+1, col) == 'o'){
		vivas++;
	}
	if (matriz.getCell(lin+1, col+1) == 'o'){
		vivas++;
	}

	return vivas;
}

Matriz escolheMatriz(char m){
	Linha linha;
	Glider glider;
	GliderGun gun;
	Matriz hab;
	int lin, col, ger, tam;
	char var;
	string nome;

	if (m == 'g') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = glider.getCell(lin,col);
				hab.setCell(var,lin,col);
			}
		}
		ger = glider.getGeracoes();
		tam = glider.getTamanho();
		nome = glider.getNome();

	}else if (m == 'l') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = linha.getCell(lin,col);
				hab.setCell(var,lin,col);
			}
		}
		ger = linha.getGeracoes();
		tam = linha.getTamanho();
		nome = linha.getNome();

	}else if (m == 'u') {
		for (lin = 0; lin < 40; lin++) {
			for (col = 0; col < 40; col++) {
				var = gun.getCell(lin,col);
				hab.setCell(var,lin,col);
			}
		}
		ger = gun.getGeracoes();
		tam = gun.getTamanho();
		nome = gun.getNome();
	}

	hab.setGeracoes(ger);
	hab.setTamanho(tam);
	hab.setNome(nome);

	return hab;
}

Matriz f5(Matriz hab){
	int lin,col, tam;
	char var;
	string nome;
	Matriz mem;

	nome = hab.getNome();
	tam = hab.getTamanho();

	mem.setTamanho(tam);
	mem.setNome(nome);

	for (lin = 0; lin < tam; lin++) {
		for (col = 0; col < tam; col++) {
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
	int linha, coluna, geracao, times = 0, lin, col, vivas, tamanho;
	char m;

	printf("Qual matriz você gostaria de rodar?\n");
	printf("DIGITE:\n G para a Glider\n L para a Linha\n U para a Glider Gun\n");
	printf("\n\nOBS.: Caso tenha escolhido a opção Glider Gun, maximize sua tela para"
		"melhor visualização.\n\n");
	scanf("%c", &m);
	printf("\n");

	if (m < 97) {
		m = m + 32;
	}

	while (m != 'g' && m != 'l' && m !='u') {
		printf("\n\nERRO: NÃO ACHAMOS SUA MATRIZ INICIAL.\n\nEscreva novamente: ");
		scanf("%c", &m);
		printf("\n");
	}

	habtat = escolheMatriz(m);
	memoria = f5(habtat);
	tamanho = habtat.getTamanho();

	cout << "Você escolheu: " <<  habtat.getNome() << endl;
	cout << " - É uma matriz "<<habtat.getTamanho()<<"X"<<habtat.getTamanho()<< endl;
	cout << " - Possui " << habtat.getGeracoes() << " gerações" << endl;

	//Começa o loop que da a vida
	while (times < habtat.getGeracoes()) {
		times++;
		bordaH(times, tamanho);

		//Começando a ler a matriz
		for(linha = 0; linha < tamanho; linha++){
			bordaV(linha);

			//Entra no 2o for para efetuar a real leitura dos elementos
			for(coluna = 0; coluna < tamanho; coluna++){

				cout << habtat.getCell(linha, coluna) << "  ";

				if (linha > 0 && linha < (tamanho-1) && coluna > 0 && coluna < (tamanho-1)) {

					vivas = quantVivas(memoria, linha,coluna);

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
		memoria = f5(habtat);
	}


	return 0;
}
