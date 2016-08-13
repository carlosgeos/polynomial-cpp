/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>


#include "PolyCon.hpp"
#include "PolyMod.hpp"

PolyCon<int> pc1(3);


int main() {

    pc1[3] = 1;
    //pc1[2] = 0;
    pc1[0] = 1;


    std::cout << pc1 << "\n";

    PolyMod<int, pc1, 3> pm1(2);

    PolyMod<int, pc1, 3> pm2(2);

    pm1[2] = 2;
    pm1[1] = -1;
    pm1[0] = 6;

    pm2[1] = 4;

    std::cout << pm1 << "\n";
    std::cout << pm2 << "\n";

    pm1 *= pm2;

    std::cout << pm1 << "\n";
    // pm1[1] = 3;
    // pm2[2] = 2;

    // pm1 *= pm2;

    // std::cout << pm1 << "\n";
    return 0;
}
