#include <iostream>
#include "matriz.hpp"

using namespace std;

Matriz::Matriz(){
	int i, j;
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			elemento[i][j] = '-';
		}
	}
}

char Matriz::getElemento(int linha, int coluna){
	return elemento[linha][coluna];
}

void Matriz::setElemento(char elemento, int linha, int coluna){
	this->elemento[linha][coluna] = elemento;
}


Linha::Linha(){
	this->elemento[10][10] = setElemento('*', 10, 10);
	this->elemento[10][11] = setElemento('*', 10, 11);
	this->elemento[10][9] = setElemento('*', 10, 9);

}


