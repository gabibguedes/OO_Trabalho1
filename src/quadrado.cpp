#include <iostream>
#include "quadrado.hpp"

Quadrado::Quadrado(){
    
    setNome("Quadrado");
    setGeracoes(5);
    setTamanho(20);

    // Definições das coordenadas das celulas vivas do Quadrado:
    setCelula('o', 10, 10);
    setCelula('o', 10, 11);
    setCelula('o', 11, 10);
    setCelula('o', 11, 11);
}

Quadrado::~Quadrado(){}
