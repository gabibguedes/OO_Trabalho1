#include <iostream>
#include "linha.hpp"

using namespace std;

Linha::Linha(){
	int i, j;
	for(i = 0; i<20; i++){
		for(j = 0; j<20; j++){
			cell[i][j] = '-';
		}
	}

	cell[10][9] = '*';
	cell[10][10] = '*';
	cell[10][11] = '*';
}

Linha::~Linha(){
}

char Linha::getCell(int i, int j){
	return cell[i][j];
}

void Linha::setCell(char cell, int i, int j){
	this->cell[i][j] = cell;
}


