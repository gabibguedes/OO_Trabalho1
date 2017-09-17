#include <iostream>
#include "gliderGun.hpp"

GliderGun::GliderGun(){

    setNome("Gosper Glider Gun");
    setGeracoes(150);
    setTamanho(40);

    // Definições das coordenadas das células vivas da Gosper Glider Gun:
    setCelula('o',5, 29);
    setCelula('o',6, 27);
    setCelula('o',6, 29);
    setCelula('o',7, 17);
    setCelula('o',7, 18);
    setCelula('o',7, 25);
    setCelula('o',7, 26);
    setCelula('o',7, 39);
    setCelula('o',7, 40);
    setCelula('o',8, 16);
    setCelula('o',8, 20);
    setCelula('o',8, 25);
    setCelula('o',8, 26);
    setCelula('o',8, 39);
    setCelula('o',8, 40);
    setCelula('o',9, 5);
    setCelula('o',9, 6);
    setCelula('o',9, 15);
    setCelula('o',9, 21);
    setCelula('o',9, 25);
    setCelula('o',9, 26);
    setCelula('o',10, 5);
    setCelula('o',10, 6);
    setCelula('o',10, 15);
    setCelula('o',10, 19);
    setCelula('o',10, 21);
    setCelula('o',10, 22);
    setCelula('o',10, 27);
    setCelula('o',10, 29);
    setCelula('o',11, 15);
    setCelula('o',11, 21);
    setCelula('o',11, 29);
    setCelula('o',12, 16);
    setCelula('o',12, 20);
    setCelula('o',13, 17);
    setCelula('o',13, 18);
}

GliderGun::~GliderGun(){}
