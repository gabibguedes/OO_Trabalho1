#include <iostream>
#include "quadrado.hpp"

using namespace std;

Quadrado::Quadrado(){

    setCell('o', 10, 10);
    setCell('o', 10, 11);
    setCell('o', 11, 10);
    setCell('o', 11, 11);

    setNome("Quadrado");
    setGeracoes(5);
    setTamanho(20);

}

Quadrado::~Quadrado(){}
