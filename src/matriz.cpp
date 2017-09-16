#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "matriz.hpp"
#include "glider.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"

Matriz::Matriz(){
	// Toda matriz inicia com todas as celulas mortas
	int linha, coluna;

	nome = "Celulas mortas";
	geracoes = 100;
	tamanho = 20;

	for(linha = 0; linha < 100; linha++){
		for(coluna = 0; coluna < 100; coluna++){
			celula[linha][coluna] = ' ';
		}
	}
}

Matriz::~Matriz(){
}

char Matriz::getCelula(int linha, int coluna){
	return celula[linha][coluna];
}

void Matriz::setCelula(char celula, int linha, int coluna){
	this->celula[linha][coluna] = celula;
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

void Matriz::escreveMatriz(){
	// Este método ajuda o usuario a escrever sua própria matriz do zero,
	//determinando, uma a uma quais celulas estão vivas e quais estão mortas

	int tamanho, linha, coluna;
	char celula;
	char nome[100];

	// Definições iniciais do conjunto:
	cout << "Defina os parametros do seu conjunto de celula:" << endl;
	cout << "Nome do conjunto: ";
	getchar();
	cin.getline(nome, 100);
	setNome(nome);

	cout << "Tamanho da matriz: ";
	cin >> tamanho;
	setTamanho(tamanho);
	setGeracoes(10);

	cout << endl;
	cout << "Escreva seu conjunto " << nome << " da seguinte forma: use 'o' para"
	" celula vivas e '-' para mortas. Separe as celulas com 2 espaços."<< endl;
	cout << endl;

	//Determinando celulas vivas e mortas:
	printBordaHorizontal();
	for (linha = 0; linha < tamanho; linha++) {
		printBordaVertical(linha);
		for (coluna = 0; coluna < tamanho; coluna++) {
			cin >> celula;
			if (celula == '-') {
				celula = ' ';
			}else{
				celula = 'o';
			}
			setCelula(celula, linha, coluna);
		}
	}

	cout << endl << "Este é o seu novo conjunto de celulas:"<< endl;

	printBordaHorizontal();
	for (linha = 0; linha < tamanho; linha++) {
		printBordaVertical(linha);
		for (coluna = 0; coluna < tamanho; coluna++) {
			cout << getCelula(linha, coluna) << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matriz::montaAleatoria(){
	// Neste método, as celulas vivas e mortas são escolhidas aleatoriamente,
	//utilizando a função rand, números aleatórios são escolhidos e dependendo
	//do número, a celula é dada como viva ou morta.
	int linha, coluna, tamanho, numero;

	// Definição inicial da matriz:
	cout << "Tamanho da matriz: ";
	cin >> tamanho;
	setTamanho(tamanho);
	nome = "Aleatoria";

	for (linha = 1; linha < (tamanho-1); linha++) {
		for (coluna = 1; coluna < (tamanho-1); coluna++) {
			// Um número de 0 a 4 é escolhido aleatoriamente
			numero = ( rand() % 4 );

			if (numero == 0) {
				// Quando o número é zero a celula é viva
				setCelula('o', linha, coluna);
			}
		}
	}

}
void Matriz::juntaMatriz() {
	// Esse método utiliza de alguns conjuntos de celulas ja definidos para juntar
	//eles em um só jogo, onde a posição e a quantidade de cada um deles é definida
	//pelo usuario.
	char resposta = 'a', nome[100];
	int tamanho, quantidade, i, posicaoX, posicaoY, linha, coluna;

	//Definição inicial da matriz
	cout << "Dados da Matriz:\n NOME: ";
	getchar();
	cin.getline(nome, 100);
	setNome(nome);

	cout << " TAMANHO: ";
	cin >> tamanho;
	setTamanho(tamanho);
	setGeracoes(60);

	while (resposta != 't') {
		// Neste loop o usuario escolhe seus conjuntos a serem colocados, o loop
		//roda até que o usuario o pare.
		cout << endl;
		cout << "Escolha o conjunto que você deseja adicionar: "<< endl;
		cout << "DIGITE:\n Q para Quadrado\n B para Blinker\n G para Glider\n"
		" T para Terminar\n" << endl;
		cin >> resposta;

		if (resposta < 97) {
			resposta = resposta + 32;
		}

		while (resposta != 'g' && resposta != 'b' && resposta!= 'q' && resposta!= 't') {
			cout << "\n\nERRO: OS CONJUNTO NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
			cin >> resposta;
			cout << endl;
		}

		if (resposta != 't') {
			// É escolhida a quantidade
			cout << "\nQuantos? ";
			cin >> quantidade;

			for (i = 0; i < quantidade; i++) {
				// É escolhida a posição
				cout << "\nDigite a posição:" << endl;
				cout << " Linha: ";
				cin >> posicaoX;
				cout << " Coluna: ";
				cin >> posicaoY;
				cout << endl;

				while (posicaoX > tamanho || posicaoX < 0 || posicaoY > tamanho || posicaoY < 0) {
					cout << "ERRO: A POSIÇÃO NÃO PERTENCE A MATRIZ DO JOGO." << endl;
					cout << "Escreva novamente:" << endl;
					cout << " Linha: ";
					cin >> posicaoX;
					cout << " Coluna: ";
					cin >> posicaoY;
					cout << endl;
				}

				adicionaElemento(resposta, posicaoX - 1, posicaoY - 1);

				// O jogo é impresso com o novo elemento adicionado
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
	// Este método adiciona os elementos escolhidos a matriz

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
	// Metodo para a impressão das coordenadas das colunas da matriz. Nessa
	//impressão, é adicionada, ao topo, a geração em que a matriz está.

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
	// Método para impressão da coordenadas das colunas da matriz
	//(não imprime a geração).

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
	// Método para impressão das coordenadas das linhas da matriz.

	if (linha < 9) {
		cout << (linha+1) << "  ";
	}else{
		cout << (linha+1) << " ";
	}
}

int Matriz::contaVivas(int linha, int coluna){
	// Este método conta a quantidade de celula vivas ao redor da celula analizada
	//de forma em que, cada celula viva encontrada é adicionada a variavel "vivas".

	int vivas = 0;
	if (celula[linha-1][coluna-1] == 'o'){
		vivas++;
	}
	if (celula[linha-1][coluna] == 'o'){
		vivas++;
	}
	if (celula[linha-1][coluna+1] == 'o'){
		vivas++;
	}

	if (celula[linha][coluna-1]  == 'o'){
		vivas++;
	}
	if (celula[linha][coluna+1] == 'o'){
		vivas++;
	}

	if (celula[linha+1][coluna-1] == 'o'){
		vivas++;
	}
	if (celula[linha+1][coluna] == 'o'){
		vivas++;
	}
	if (celula[linha+1][coluna+1] == 'o'){
		vivas++;
	}

	return vivas;
}

int Matriz::contaVivas(){
	// Este método, assim como o anterior, conta as celulas vivas, a diferença
	//é que neste, as celulas contadas são da matriz inteira.

	int vivas = 0, linha, coluna;

	for (linha = 0; linha < getTamanho(); linha++) {
		for (coluna = 0; coluna < getTamanho(); coluna++) {
			if (getCelula(linha, coluna) == 'o'){
				vivas++;
			}
		}
	}

	return vivas;
}
