#include <iostream>
#include "glider.hpp"

using namespace std;

Glider::Glider(){

    setCell('*', 1, 2);
    setCell('*', 2, 3);
    setCell('*', 3, 1);
    setCell('*', 3, 2);
    setCell('*', 3, 3);

    setNome("glider");

    setGeracoes(60);
}

Glider::~Glider(){}
