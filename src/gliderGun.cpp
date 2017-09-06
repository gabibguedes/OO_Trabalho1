#include <iostream>
#include "gliderGun.hpp"

GliderGun::GliderGun(){

    setCell('o',1, 25);
    setCell('o',2, 23);
    setCell('o',2, 25);
    setCell('o',3, 13);
    setCell('o',3, 14);
    setCell('o',3, 21);
    setCell('o',3, 22);
    setCell('o',3, 35);
    setCell('o',3, 36);
    setCell('o',4, 12);
    setCell('o',4, 16);
    setCell('o',4, 21);
    setCell('o',4, 22);
    setCell('o',4, 35);
    setCell('o',4, 36);
    setCell('o',5, 1);
    setCell('o',5, 2);
    setCell('o',5, 11);
    setCell('o',5, 17);
    setCell('o',5, 21);
    setCell('o',5, 22);
    setCell('o',6, 1);
    setCell('o',6, 2);
    setCell('o',6, 11);
    setCell('o',6, 15);
    setCell('o',6, 17);
    setCell('o',6, 18);
    setCell('o',6, 23);
    setCell('o',6, 25);
    setCell('o',7, 11);
    setCell('o',7, 17);
    setCell('o',7, 25);
    setCell('o',8, 12);
    setCell('o',8, 16);
    setCell('o',9, 13);
    setCell('o',9, 14);

    setNome("Glider Gun");
    setGeracoes(150);
    setTamanho(40);

}

GliderGun::~GliderGun(){}
