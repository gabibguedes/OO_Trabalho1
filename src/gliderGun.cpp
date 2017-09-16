#include <iostream>
#include "gliderGun.hpp"

GliderGun::GliderGun(){

    setNome("Glider Gun");
    setGeracoes(150);
    setTamanho(40);

    // Definições das coordenadas das celulas vivas da Glider Gun:
    setCelula('o',1, 25);
    setCelula('o',2, 23);
    setCelula('o',2, 25);
    setCelula('o',3, 13);
    setCelula('o',3, 14);
    setCelula('o',3, 21);
    setCelula('o',3, 22);
    setCelula('o',3, 35);
    setCelula('o',3, 36);
    setCelula('o',4, 12);
    setCelula('o',4, 16);
    setCelula('o',4, 21);
    setCelula('o',4, 22);
    setCelula('o',4, 35);
    setCelula('o',4, 36);
    setCelula('o',5, 1);
    setCelula('o',5, 2);
    setCelula('o',5, 11);
    setCelula('o',5, 17);
    setCelula('o',5, 21);
    setCelula('o',5, 22);
    setCelula('o',6, 1);
    setCelula('o',6, 2);
    setCelula('o',6, 11);
    setCelula('o',6, 15);
    setCelula('o',6, 17);
    setCelula('o',6, 18);
    setCelula('o',6, 23);
    setCelula('o',6, 25);
    setCelula('o',7, 11);
    setCelula('o',7, 17);
    setCelula('o',7, 25);
    setCelula('o',8, 12);
    setCelula('o',8, 16);
    setCelula('o',9, 13);
    setCelula('o',9, 14);
}

GliderGun::~GliderGun(){}
