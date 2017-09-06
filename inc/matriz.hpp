#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <string>

using namespace std;

class Matriz {
	private:
		char cell[100][100];
		string nome;
		int geracoes;
		int tamanho;

	public:
		Matriz();
		Matriz(string nome, int tamanho, int geracoes);
		~Matriz();

		char getCell(int linha, int coluna);
		void setCell(char cell, int linha, int coluna);

		string getNome();
		void setNome(string nome);

		int getGeracoes();
		void setGeracoes(int geracoes);

		int getTamanho();
		void setTamanho(int tamanho);

		void montaMatriz();
		void montaAleatoria();

		void printBordaHorizontal(int ger);
		void printBordaHorizontal();
		void printBordaVertical(int linha);

		int contaVivas(int linha, int coluna);
		int contaVivas();

};

#endif
