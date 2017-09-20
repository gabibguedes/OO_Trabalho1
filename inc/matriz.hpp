#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <string>

using namespace std;

class Matriz {
	private:
		char celula[100][100];
		string nome;
		int geracoes;
		int tamanho;

	public:
		Matriz();
		~Matriz();

		// Métodos de acesso aos atributos
		char getCelula(int linha, int coluna);
		void setCelula(char celula, int linha, int coluna);
		string getNome();
		void setNome(string nome);
		int getGeracoes();
		void setGeracoes(int geracoes);
		int getTamanho();
		void setTamanho(int tamanho);

		// Métodos para diversas formas de montar a matriz
		void escolheNome();
		void escreveMatriz();
		void montaAleatoria();
		void juntaMatriz();
		void adicionaElemento(char letra, int x, int y);
		void adicionaElemento(Matriz * m2);

		// Métodos para a impressão
		void printBordaHorizontal(int ger);
		void printBordaHorizontal();
		void printBordaVertical(int linha);
		void printJogo();

		// Métodos para contar as células vivas
		int contaVivas(int linha, int coluna);
		int contaVivas();
};

#endif
