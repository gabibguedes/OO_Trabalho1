#include <iostream>
#include "matriz.hpp"

using namespace std;

Matriz::Matriz(){
	int i, j;
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			cell[i][j] = '-';
		}
	}
}

Matriz::~Matriz(){
}

char Matriz::getCell(int i, int j){
	return cell[i][j];
}

void Matriz::setCell(char cell, int i, int j){
	this->cell[i][j] = cell;
}
