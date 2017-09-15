#include <iostream>
#include "blinker.hpp"

Blinker::Blinker(){

	setCelula('o', 10, 9);
	setCelula('o', 10, 10);
	setCelula('o', 10, 11);

	setNome("Blinker");
	setGeracoes(10);
	setTamanho(20);
}

Blinker::~Blinker(){}
