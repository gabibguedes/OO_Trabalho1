#include <iostream>
#include "linha.hpp"

using namespace std;

Linha::Linha(){

	setCell('o', 10, 9);
	setCell('o', 10, 10);
	setCell('o', 10, 11);

	setNome("Linha");
	setGeracoes(10);
	setTamanho(20);
}

Linha::~Linha(){}
