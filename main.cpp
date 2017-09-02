#include <iostream>
#include <stdio.h>
#include "matriz.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"
#include <string>
#include <unistd.h>


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

int quantVivasBORDA(Matriz matriz, int linha, int coluna, int tamanho){
	//Esta função conta a quantidade de celulas vivas ao redor da celula analizada
	int vivas = 0, i;
	char vizinhas[3][3];

	vizinhas[1][1] = matriz.getCell(linha, coluna);

	if (linha == 0) {
		for (i = 0; i < 3; i++) {
			vizinhas[0][i] = ' ';
		}
	}
	if (linha == (tamanho - 1)) {
		for (i = 0; i < 3; i++) {
			vizinhas[2][i] = ' ';
		}
	}
	if (coluna == 0) {
		for (i = 0; i < 3; i++) {
			vizinhas[i][0] = ' ';
		}
	}
	if (coluna == (tamanho - 1)) {
		for (i = 0; i < 3; i++) {
			vizinhas[i][2] = ' ';
		}
	}

	for (linha = 0; linha < 3; linha++) {
		for (coluna = 0; coluna < 3; coluna++) {
			if ((linha !=1 || coluna !=1) && vizinhas[linha][coluna] == 'o') {
				vivas++;
			}
		}
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
	char celula[40][40], resposta = 's';
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


int main(int argc, char ** argv) {
	Matriz habtat, memoria;
	int linha, coluna, geracao, times = 0, vivas, tamanho;
	char resposta, m;

	// Menu inicial:
	cout << "Qual conjunto de celulas você gostaria de rodar?" << endl;
	printf("DIGITE:\n Q para Quadrado\n B para Blinker\n G para Glider\n"
		" U para Glider Gun\n M para montar seu conjunto de celulas\n\n");
	scanf("%c", &m);
	cout << endl;

	if (m < 97) {
		m = m + 32;
	}

	while (m != 'g' && m != 'b' && m !='u' && m != 'm' && m!= 'q') {
		cout << "\n\nERRO: NÃO ACHAMOS SEU CONJUNTO INICIAL.\n\nEscreva novamente: ";
		scanf("%c", &m);
		cout << endl;
	}

	if (m == 'm') {
		habtat = montaMatriz();
	}else{
		habtat = escolheMatriz(m);
	}

	if (m == 'u') {
		printf("\n\nOBS.: Maximize sua tela para melhor visualização.\n\n");
	}

	memoria = f5(habtat);
	tamanho = habtat.getTamanho();

	cout << endl;
	cout << "Você escolheu: " <<  habtat.getNome() << endl;
	cout << " - É uma matriz "<<habtat.getTamanho()<<"X"<<habtat.getTamanho()<< endl;
	cout << " - Possui " << habtat.getGeracoes() << " gerações" << endl;

	cout << "\nDeseja alterar a quantidade de gerações das suas celulas? (S/N) ";
	scanf(" %c", &resposta);
	printf("\n");

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




	//Começa o loop do jogo
	while (times < habtat.getGeracoes()) {
		times++;
		bordaH(times, tamanho);

		//Começando a ler a matriz
		for(linha = 0; linha < tamanho; linha++){
			bordaV(linha);

			//Entra no 2o for para efetuar a real leitura e print dos elementos
			for(coluna = 0; coluna < tamanho; coluna++){

				cout << habtat.getCell(linha, coluna) << "  ";

				if (linha > 0 && linha < (tamanho-1) && coluna > 0 && coluna < (tamanho-1)) {
					vivas = quantVivas(memoria, linha,coluna);
				}else{
					vivas = quantVivasBORDA(memoria, linha, coluna, tamanho);
				}

				// REGRAS DO JOGO DA VIDA:
				if (habtat.getCell(linha,coluna) == 'o' && (vivas < 2 || vivas > 3)) {
					habtat.setCell(' ',linha,coluna);
				}else if(habtat.getCell(linha,coluna) == ' ' && vivas == 3){
					habtat.setCell('o',linha,coluna);
				}else if(habtat.getCell(linha,coluna) == 'o' && (vivas == 2 || vivas == 3)){
					habtat.setCell('o',linha,coluna);
				}
			}
			cout << endl;
		}
		memoria = f5(habtat);
		usleep(250000);
	}


	return 0;
}
