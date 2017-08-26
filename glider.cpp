#include <iostream>
#include "glider.hpp"

using namespace std;

Glider::Glider(){

    setCell('o', 1, 2);
    setCell('o', 2, 3);
    setCell('o', 3, 1);
    setCell('o', 3, 2);
    setCell('o', 3, 3);

    setNome("Glider");
    setGeracoes(60);
    setTamanho(20);
}

Glider::~Glider(){}
