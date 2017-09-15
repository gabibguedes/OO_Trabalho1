#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "matriz.hpp"
#include "glider.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"

Matriz::Matriz(){
	int lin, col;
	nome = "Celulas mortas";
	geracoes = 100;
	tamanho = 20;

	for(lin = 0; lin < 100; lin++){
		for(col = 0; col < 100; col++){
			celula[lin][col] = ' ';
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
			celula[lin][col] = ' ';
		}
	}
}

Matriz::~Matriz(){
}

char Matriz::getCelula(int lin, int col){
	return celula[lin][col];
}

void Matriz::setCelula(char celula, int lin, int col){
	this->celula[lin][col] = celula;
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
	char celula[40][40];
	char nome[100];

	cout << "Defina os parametros do seu conjunto de celula:" << endl;
	cout << "Nome do conjunto: ";
	getchar();
	cin.getline(nome, 100);
	this->nome = nome;

	cout << "Tamanho da matriz: ";
	cin >> tamanho;
	this->tamanho = tamanho;
	geracoes = 10;

	cout << endl;
	cout << "Escreva seu conjunto " << nome << " da seguinte forma: use 'o' para"
	" celula vivas e '-' para mortas. Separe as celulas com 2 espaços."<< endl;
	cout << endl;

	printBordaHorizontal();
	for (linha = 0; linha < tamanho; linha++) {
		printBordaVertical(linha);
		for (coluna = 0; coluna < tamanho; coluna++) {
			cin >> celula[linha][coluna];
			if (celula[linha][coluna] == '-') {
				celula[linha][coluna] = ' ';
			}else{
				celula[linha][coluna] = 'o';
			}
			this->celula[linha][coluna] = celula[linha][coluna];
		}
	}

	cout << endl << "Este é o seu novo conjunto de celulas:"<< endl;

	printBordaHorizontal();
	for (linha = 0; linha < tamanho; linha++) {
		printBordaVertical(linha);
		for (coluna = 0; coluna < tamanho; coluna++) {
			cout << celula[linha][coluna] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matriz::montaAleatoria(){
	int lin, col, tamanho, num;

	cout << "Tamanho da matriz: ";
	cin >> tamanho;
	this->tamanho = tamanho;
	nome = "Aleatoria";

	for (lin = 1; lin < (tamanho-1); lin++) {
		for (col = 1; col < (tamanho-1); col++) {
			num = ( rand() % 2 );

			if (num < 1) {
				celula[lin][col] = 'o';
			}
		}
	}

}
void Matriz::juntaMatriz() {
	char resposta = 'a', nome[100];
	int tamanho, quantidade, i, posicaoX, posicaoY, linha, coluna;

	cout << "Dados da Matriz:\n NOME: ";
	cin >> nome;
	setNome(nome);

	cout << " TAMANHO: ";
	cin >> tamanho;
	setTamanho(tamanho);
	setGeracoes(100);

	while (resposta != 't') {

		cout << "Escolha os conjuntos que você deseja adicionar: "<< endl;
		cout << "DIGITE:\n Q para Quadrado\n B para Blinker\n G para glider\n"
		" T para terminar\n" << endl;
		cin >> resposta;

		if (resposta < 97) {
			resposta = resposta + 32;
		}

		while (resposta != 'g' && resposta != 'b' && resposta!= 'q' && resposta!= 't') {
			cout << "\n\nERRO: SEU CONJUNTO NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
			cin >> resposta;
			cout << endl;
		}

		if (resposta != 't') {
			cout << "\nQuantos? ";
			cin >> quantidade;

			for (i = 0; i < quantidade; i++) {
				cout << "\nDigite a posição:"<<endl;
				cout << " Linha: ";
				cin >> posicaoX;
				cout << " Coluna: ";
				cin >> posicaoY;
				cout << endl;

				adicionaElemento(resposta, posicaoX - 1, posicaoY - 1);

				printBordaHorizontal();
				for (linha = 0; linha < tamanho; linha++) {
					printBordaVertical(linha);
					for (coluna = 0; coluna < tamanho; coluna++) {
						cout << getCelula(linha, coluna) << "  ";
					}
					cout << endl;
				}
			}
		}
	}
}

void Matriz::adicionaElemento(char letra, int x, int y){
	Quadrado quadrado;
	Blinker blinker;
	Glider glider;

	if (letra == 'q') {
		setCelula('o', x, y);
		setCelula('o', x, y+1);
		setCelula('o', x+1, y);
		setCelula('o', x+1, y+1);

	}else if(letra == 'b'){
		setCelula('o', x, y);
		setCelula('o', x, y+1);
		setCelula('o', x, y+2);

	}else if(letra == 'g'){
		setCelula('o', x, y);
	    setCelula('o', x+1, y+1);
	    setCelula('o', x+2, y-1);
	    setCelula('o', x+2, y);
	    setCelula('o', x+2, y+1);

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
	//Esta função conta a quantidade de celula vivas ao redor da celula analizada

	int vivas = 0;
	if (celula[lin-1][col-1] == 'o'){
		vivas++;
	}
	if (celula[lin-1][col] == 'o'){
		vivas++;
	}
	if (celula[lin-1][col+1] == 'o'){
		vivas++;
	}

	if (celula[lin][col-1]  == 'o'){
		vivas++;
	}
	if (celula[lin][col+1] == 'o'){
		vivas++;
	}

	if (celula[lin+1][col-1] == 'o'){
		vivas++;
	}
	if (celula[lin+1][col] == 'o'){
		vivas++;
	}
	if (celula[lin+1][col+1] == 'o'){
		vivas++;
	}

	return vivas;
}

int Matriz::contaVivas(){
	//Esta função conta a quantidade de celulas vivas ao redor da celula analizada

	int vivas = 0, linha, coluna;

	for (linha = 0; linha < 40; linha++) {
		for (coluna = 0; coluna < 40; coluna++) {
			if (getCelula(linha, coluna) == 'o'){
				vivas++;
			}
		}
	}

	return vivas;
}
