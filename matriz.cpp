#include <iostream>
#include "matriz.hpp"

using namespace std;

Matriz::Matriz(){
	int lin, col;
	for(lin = 0; lin < 40; lin++){
		for(col = 0; col < 40; col++){
			cell[lin][col] = ' ';
		}
	}
}

Matriz::~Matriz(){
}

char Matriz::getCell(int lin, int col){
	return cell[lin][col];
}

void Matriz::setCell(char cell, int lin, int col){
	this->cell[lin][col] = cell;
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
