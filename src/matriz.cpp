#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "matriz.hpp"

using namespace std;

Matriz::Matriz(){
	int lin, col;
	nome = "Celulas mortas";
	geracoes = 100;
	tamanho = 20;
	for(lin = 0; lin < 100; lin++){
		for(col = 0; col < 100; col++){
			cell[lin][col] = ' ';
		}
	}
}

Matriz::Matriz(string nome, int tamanho, int geracoes){
	int lin, col;

	this->nome = nome;
	this->tamanho = tamanho;
	this->geracoes = geracoes;

	for(lin = 0; lin < 100; lin++){
		for(col = 0; col < 100; col++){
			cell[lin][col] = ' ';
		}
	}
}

Matriz::~Matriz(){
}

char Matriz::getCell(int lin, int col){
	return cell[lin][col];
}

void Matriz::setCell(char cell, int lin, int col){
	this->cell[lin][col] = cell;
}

string Matriz::getNome(){
	return nome;
}

void Matriz::setNome(string nome){
	this->nome = nome;
}

int Matriz::getGeracoes(){
	return geracoes;
}

void Matriz::setGeracoes(int geracoes) {
	this->geracoes = geracoes;
}

int Matriz::getTamanho(){
	return tamanho;
}

void Matriz::setTamanho(int tamanho){
	this->tamanho = tamanho;
}

void Matriz::montaMatriz(){
	// Esta função monta uma nova matriz de acordo com as preferencias do usuario

	int tamanho, linha, coluna;
	char cell[40][40];
	char nome[100];

	cout << "Defina os parametros do seu conjunto de celulas:" << endl;
	cout << "Nome do conjunto: ";
	scanf("%s", nome);
	getchar();
	this->nome = nome;

	cout << "Tamanho da matriz: ";
	scanf("%d", &tamanho);
	this->tamanho = tamanho;
	geracoes = 10;

	cout << endl;
	cout << "Escreva seu conjunto " << nome << " da seguinte forma: use 'o' para"
	" celulas vivas e '-' para mortas. Separe as celulas com 2 espaços."<< endl;
	cout << endl;

	printBordaHorizontal();
	for (linha = 0; linha < tamanho; linha++) {
		printBordaVertical(linha);
		for (coluna = 0; coluna < tamanho; coluna++) {
			scanf(" %c", &cell[linha][coluna]);
			if (cell[linha][coluna] == '-') {
				cell[linha][coluna] = ' ';
			}else{
				cell[linha][coluna] = 'o';
			}
			this->cell[linha][coluna] = cell[linha][coluna];
		}
	}

	cout << endl << "Este é o seu novo conjunto de celulas:"<< endl;

	printBordaHorizontal();
	for (linha = 0; linha < tamanho; linha++) {
		printBordaVertical(linha);
		for (coluna = 0; coluna < tamanho; coluna++) {
			cout << cell[linha][coluna] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matriz::montaAleatoria(){
	int lin, col, tamanho, num;

	cout << "Tamanho da matriz: ";
	scanf("%d", &tamanho);
	this->tamanho = tamanho;
	nome = "Aleatoria";

	for (lin = 1; lin < (tamanho-1); lin++) {
		for (col = 1; col < (tamanho-1); col++) {
			num = ( rand() % 2 );

			if (num < 1) {
				cell[lin][col] = 'o';
			}
		}
	}

}

void Matriz::printBordaHorizontal(int ger){
	//Função para as coordenadas, numeração horizontal
	int i;

	cout << endl << "GERAÇÃO "<< ger << endl;
	cout << "   ";

	for (i = 0; i < tamanho; i++) {
		if (i< 9) {
			cout << (i+1) << "  ";
		}else{
			cout << (i+1) << " ";
		}
	}
	cout << endl;
}

void Matriz::printBordaHorizontal(){
	//Função para as coordenadas, numeração horizontal
	int i;
	cout << "   ";

	for (i = 0; i < tamanho; i++) {
		if (i< 9) {
			cout << (i+1) << "  ";
		}else{
			cout << (i+1) << " ";
		}
	}
	cout << endl;
}

void Matriz::printBordaVertical(int linha) {
	//Função para as coordenadas, vertical

	if (linha < 9) {
		cout << (linha+1) << "  ";
	}else{
		cout << (linha+1) << " ";
	}
}

int Matriz::contaVivas(int lin, int col){
	//Esta função conta a quantidade de celulas vivas ao redor da celula analizada

	int vivas = 0;
	if (cell[lin-1][col-1] == 'o'){
		vivas++;
	}
	if (cell[lin-1][col] == 'o'){
		vivas++;
	}
	if (cell[lin-1][col+1] == 'o'){
		vivas++;
	}

	if (cell[lin][col-1]  == 'o'){
		vivas++;
	}
	if (cell[lin][col+1] == 'o'){
		vivas++;
	}

	if (cell[lin+1][col-1] == 'o'){
		vivas++;
	}
	if (cell[lin+1][col] == 'o'){
		vivas++;
	}
	if (cell[lin+1][col+1] == 'o'){
		vivas++;
	}

	return vivas;
}

int Matriz::contaVivas(){
	//Esta função conta a quantidade de celulas vivas ao redor da celula analizada

	int vivas = 0, linha, coluna;

	for (linha = 0; linha < 40; linha++) {
		for (coluna = 0; coluna < 40; coluna++) {
			if (getCell(linha, coluna) == 'o'){
				vivas++;
			}
		}
	}

	return vivas;
}
