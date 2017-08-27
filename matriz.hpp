#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <string>

using namespace std;

class Matriz {
	private:
		char cell[40][40];
		string nome;
		int geracoes;
		int tamanho;
	public:
		Matriz();
		~Matriz();
		char getCell(int linha, int coluna);
		void setCell(char cell, int linha, int coluna);
		string getNome();
		void setNome(string nome);
		int getGeracoes();
		void setGeracoes(int geracoes);
		int getTamanho();
		void setTamanho(int tamanho);
};

#endif
