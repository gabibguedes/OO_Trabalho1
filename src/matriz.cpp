#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "matriz.hpp"
#include "glider.hpp"
#include "block.hpp"
#include "blinker.hpp"

Matriz::Matriz(){
	// Toda matriz inicia com todas as células mortas
	int linha, coluna;

	nome = "Células mortas";
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

	if (geracoes < 1 || geracoes == '\0') {
		throw(1);
	}
}

int Matriz::getTamanho(){
	return tamanho;
}

void Matriz::setTamanho(int tamanho){
	this->tamanho = tamanho;
}

void Matriz::escolheNome(){
	// Este método permite ao usuario escolher o nome do conjunto. A função
	//cin.getline foi utilizada para que o nome da matriz possa ser composto.
	char nome[100];

	cout << "Nome do conjunto: ";
	getchar();
	cin.getline(nome, 100);
	setNome(nome);
}

void Matriz::escolheTamanho(){
	// Este método permite ao usuario escolher o tamanho do conjunto
	int tamanho;

	cout << "(OBS : Escreva somente 1 número para o TAMANHO, pois a matriz é"
	<< " quadrada, tem o mesmo número para linhas e colunas)"<< endl;
	cout << "Tamanho da matriz: ";
	cin >> tamanho;
	setTamanho(tamanho);

	if(getTamanho() < 1 || tamanho > 100){
		cout << "ERRO: O JOGO NÃO SUPORTA UMA MATRIZ DESTE TAMANHO." << endl;
		throw(1);
	}
}

void Matriz::escreveMatriz(){
	// Este método ajuda o usuario a escrever sua própria matriz do zero,
	//determinando, uma a uma quais células estão vivas e quais estão mortas

	int linha, coluna;
	char celula;

	// Definições iniciais do conjunto:
	escolheNome();
	escolheTamanho();
	setGeracoes(10);

	cout << endl;
	cout << "Escreva seu conjunto " << getNome() << " da seguinte forma: use 'o' para"
		<<" celulas vivas e '-' para mortas. Separe as celulas com 2 espaços."<< endl;
	cout << endl;

	//Determinando células vivas e mortas:
	printBordaHorizontal();
	for (linha = 4; linha < getTamanho() + 4; linha++) {
		printBordaVertical(linha);
		for (coluna = 4; coluna < getTamanho() + 4; coluna++) {
			cin >> celula;
			if (celula == '-') {
				setCelula(' ', linha, coluna);

			}else{
				setCelula('o', linha, coluna);
			}
		}
	}

	cout << endl << "Este é o seu novo conjunto de células:"<< endl;

	printBordaHorizontal();
	printJogo();
	cout << endl;
}

void Matriz::montaAleatoria(){
	// Neste método, as células vivas e mortas são escolhidas aleatoriamente,
	//utilizando a função rand, números aleatórios são escolhidos e dependendo
	//do número, a celula é dada como viva ou morta.
	int linha, coluna, numero;

	// Definição inicial da matriz:
	escolheTamanho();
	nome = "Aleatoria";

	for (linha = 4; linha < (getTamanho() + 4); linha++) {
		for (coluna = 4; coluna < (getTamanho() + 4); coluna++) {
			// Um número de 0 a 3 é escolhido aleatoriamente
			numero = ( rand() % 4 );
			if (numero == 0) {
				// Quando o número é zero a celula é dada como viva
				setCelula('o', linha, coluna);
			}
		}
	}

}
void Matriz::juntaMatriz() {
	// Esse método utiliza de alguns conjuntos de celulas já definidos para juntar
	//eles em um só jogo, onde a posição e a quantidade de cada um deles é definida
	//pelo usuario.
	char resposta = 'a';
	int posicaoX, posicaoY;

	//Definição inicial da matriz
	escolheNome();
	escolheTamanho();
	setGeracoes(60);

	while (resposta != 't') {
		// Neste loop o usuario escolhe seus conjuntos a serem colocados, o loop
		//roda até que o usuario o pare.
		cout << endl;
		cout << "Escolha o conjunto que você deseja adicionar: "<< endl;
		cout << "DIGITE:\n B para Blinker\n K para Block\n G para Glider\n"
		" T para Terminar\n" << endl;
		cin >> resposta;

		if (resposta < 97) {
			resposta = resposta + 32;
		}

		while (resposta != 'g' && resposta != 'b' && resposta!= 'k' && resposta!= 't') {
			cout << "\n\nERRO: O CONJUNTO NÃO FOI ENCONTRADO.\n\nEscreva novamente: ";
			cin >> resposta;
			cout << endl;
		}

		if (resposta != 't') {
			// É escolhida a posição
			cout << "\nDigite a posição:" << endl;
			cout << " Linha: ";
			cin >> posicaoX;
			if(posicaoX > tamanho || posicaoX < 0 || posicaoX == '\0') {
				cout << "ERRO: A POSIÇÃO NÃO PERTENCE A MATRIZ DO JOGO." << endl;
				throw(1);
			}
			cout << " Coluna: ";
			cin >> posicaoY;
			if (posicaoY > tamanho || posicaoY < 0 || posicaoY == '\0') {
				cout << "ERRO: A POSIÇÃO NÃO PERTENCE A MATRIZ DO JOGO." << endl;
				throw(1);
			}
			cout << endl;

			adicionaElemento(resposta, posicaoX + 3, posicaoY + 3);

			// O jogo é impresso com o novo elemento adicionado
			printBordaHorizontal();
			printJogo();
			cout << endl;
		}
	}
}

void Matriz::adicionaElemento(char letra, int x, int y){
	// Este método adiciona os elementos escolhidos a matriz

	Blinker * blinker = new Blinker(x, y);
	Block * block = new Block(x, y);
	Glider * glider = new Glider(x, y);

	if (letra == 'k') {
		adicionaElemento(block);
	}else if(letra == 'b'){
		adicionaElemento(blinker);
	}else if(letra == 'g'){
		adicionaElemento(glider);
	}
}

void Matriz::adicionaElemento(Matriz * m2){
	// Nesse método, as células vivas da outra matriz são adicionadas

	int linha, coluna;

	for (linha = 0; linha < 100; linha++) {
		for (coluna = 0; coluna < 100; coluna++) {
			if (m2->getCelula(linha, coluna) == 'o') {
				setCelula('o', linha, coluna);
			}
		}
	}
}

void Matriz::printBordaHorizontal(int ger){
	// Método para a impressão das coordenadas das colunas da matriz. Nessa
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

	if ((linha - 3) < 10) {
		cout << (linha - 3) << "  ";
	}else{
		cout << (linha - 3) << " ";
	}
}

int Matriz::contaVivas(int linha, int coluna){
	// Este método conta a quantidade de células vivas ao redor da célula analizada
	//de forma em que, cada célula viva encontrada é adicionada a variavel "vivas".

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
	// Este método, assim como o anterior, conta as células vivas, a diferença
	//é que neste, as células contadas são da matriz inteira.

	int vivas = 0, linha, coluna;

	for (linha = 4; linha < getTamanho() + 4; linha++) {
		for (coluna = 4; coluna < getTamanho() + 4; coluna++) {
			if (getCelula(linha, coluna) == 'o'){
				vivas++;
			}
		}
	}

	return vivas;
}

void Matriz::printJogo() {
	// Método para a impressão do jogo

	int linha, coluna;
	// OBS.: Foi deixado um espaço de quatro celulas nas bordas q não será impresso.
	//Essa borda foi deixada para que as regras funcionem nos limites do jogo.
	for (linha = 4; linha < tamanho + 4; linha++) {
		printBordaVertical(linha);
		for (coluna = 4; coluna < tamanho+4; coluna++) {
			cout << getCelula(linha, coluna) << "  ";
		}
		cout << endl;
	}
}
