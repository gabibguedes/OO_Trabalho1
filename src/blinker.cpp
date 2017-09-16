#include <iostream>
#include "blinker.hpp"

Blinker::Blinker(){

	setNome("Blinker");
	setGeracoes(10);
	setTamanho(20);

	// Definições das coordenadas das celulas vivas do Blinker:
	setCelula('o', 10, 9);
	setCelula('o', 10, 10);
	setCelula('o', 10, 11);
}

Blinker::~Blinker(){}
