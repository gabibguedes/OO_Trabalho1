#include <iostream>
#include "linha.hpp"

using namespace std;

Linha::Linha(){

	setCell('*', 10, 9);
	setCell('*', 10, 10);
	setCell('*', 10, 11);

	setNome("linha");

	setGeracoes(60);
}

Linha::~Linha(){}
