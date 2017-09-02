#include <iostream>
#include "blinker.hpp"

using namespace std;

Blinker::Blinker(){

	setCell('o', 10, 9);
	setCell('o', 10, 10);
	setCell('o', 10, 11);

	setNome("Blinker");
	setGeracoes(10);
	setTamanho(20);
}

Blinker::~Blinker(){}
