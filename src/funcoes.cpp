#include <iostream>
#include <stdio.h>
#include "funcoes.hpp"
#include "matriz.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"
#include <string>
#include <stdlib.h>
#include <time.h>


void bordaH(int ger, int tam){
	//Função para as coordenadas, numeração horizontal

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

void bordaV(int i) {
	//Função para as coordenadas, vertical

	if (i < 9) {
		cout << (i+1) << "  ";
	}else{
		cout << (i+1) << " ";
	}
}

int quantVivas(Matriz matriz, int lin, int col){
	//Esta função conta a quantidade de celulas vivas ao redor da celula analizada

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
	// Esta função, a partir da letra da resposta do usuario devolve a matriz escolhida
	Quadrado quadrado;
	Blinker blinker;
	Glider glider;
	GliderGun gun;
	Matriz hab;
	int lin, col, ger, tam;
	char var;
	string nome;

	if (m == 'q') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = quadrado.getCell(lin,col);
				hab.setCell(var,lin,col);
			}
		}
		ger = quadrado.getGeracoes();
		tam = quadrado.getTamanho();
		nome = quadrado.getNome();

	}
	if (m == 'b') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = blinker.getCell(lin,col);
				hab.setCell(var,lin,col);
			}
		}
		ger = blinker.getGeracoes();
		tam = blinker.getTamanho();
		nome = blinker.getNome();

	}else if (m == 'g') {
		for (lin = 0; lin < 20; lin++) {
			for (col = 0; col < 20; col++) {
				var = glider.getCell(lin,col);
				hab.setCell(var,lin,col);
			}
		}
		ger = glider.getGeracoes();
		tam = glider.getTamanho();
		nome = glider.getNome();

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
	// Função para atualizar a memoria

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

Matriz montaMatriz(){
	// Esta função monta uma nova matriz de acordo com as preferencias do usuario

	Matriz nova;
	int geracao, tamanho, linha, coluna, i;
	char celula[40][40];
	char nome[100];

	cout << "Defina os parametros do seu conjunto de celulas:" << endl;
	cout << "Nome do conjunto: ";
	scanf("%s", nome);
	getchar();
	nova.setNome(nome);

	cout << "Quantidade de gerações: ";
	scanf("%d", &geracao);
	nova.setGeracoes(geracao);

	cout << "Tamanho da matriz: ";
	scanf("%d", &tamanho);
	nova.setTamanho(tamanho);

	cout << endl;
	cout << "Escreva seu conjunto " << nome << " da seguinte forma: use 'o' para"
	" celulas vivas e '-' para mortas. "<< endl;
	cout << endl;

	cout << "   ";
	for (i = 0; i < tamanho; i++) {
		if (i< 9) {
			cout << (i+1) << "  ";
		}else{
			cout << (i+1) << " ";
		}
	}
	cout << endl;


	for (linha = 0; linha < tamanho; linha++) {
		if (linha < 9) {
			cout << (linha+1) << "  ";
		}else{
			cout << (linha+1) << " ";
		}

		for (coluna = 0; coluna < tamanho; coluna++) {
			scanf(" %c", &celula[linha][coluna]);
			if (celula[linha][coluna] == '-') {
				celula[linha][coluna] = ' ';
			}else{
				celula[linha][coluna] = 'o';
			}
			nova.setCell(celula[linha][coluna], linha, coluna);
		}
	}

	cout << endl << "Esta é a sua novo conjunto de celulas:"<< endl;

	cout << "Nome: " << nova.getNome() << endl;
	cout << "Tamanho: " << nova.getTamanho() << endl;
	cout << "Gerações: " << nova.getGeracoes() << endl << endl;

	cout << "   ";
	for (i = 0; i < tamanho; i++) {
		cout << (i+1) << " ";
	}
	cout << endl;

	for (linha = 0; linha < tamanho; linha++) {
		cout << (linha + 1) << "  ";

		for (coluna = 0; coluna < tamanho; coluna++) {
			cout << nova.getCell(linha, coluna) << " ";
		}
		cout << endl;
	}
	cout << endl;

	return nova;
}

Matriz montaAleatoria(){
	Matriz aleatoria;
	int lin, col, tamanho, num;

	aleatoria.setNome("Aleatoria");
	aleatoria.setGeracoes(100);

	cout << "Tamanho da matriz: ";
	scanf("%d", &tamanho);
	aleatoria.setTamanho(tamanho);

	for (lin = 1; lin < (tamanho-1); lin++) {
		for (col = 1; col < (tamanho-1); col++) {
			num = ( rand() % 2 );

			if (num < 1) {
				aleatoria.setCell('o', lin, col);
			}else{
				aleatoria.setCell(' ', lin, col);
			}
		}
	}


	return aleatoria;
}
