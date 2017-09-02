#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include "matriz.hpp"
#include "quadrado.hpp"
#include "blinker.hpp"
#include "glider.hpp"
#include "gliderGun.hpp"


    void bordaH(int ger, int tam);
    void bordaV(int i);
    int quantVivas(Matriz matriz, int lin, int col);
    Matriz escolheMatriz(char m);
    Matriz f5(Matriz hab);
    Matriz montaMatriz();

#endif
