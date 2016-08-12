/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>


//#include "staticVect.hpp"
#include "dynamicVect.hpp"
#include "staticVect.hpp"
#include "PolyCon.hpp"
#include "PolyMod.hpp"

PolyCon<int> pc1(5);


int main() {

    StaticVector<int, 5> v1;
    v1[2] = 2;
    StaticVector<int, 5> v2;
    v2[3] = 2;

    StaticVector<int, 5> v3;
    ++v1;
    ++v1;

    DynamicVector<int> v4(5);

    v4[3] = 4;


    PolyCon<int> pc2(6);

    pc1[3] = 4;
    pc2[2] = -3;
    pc2[0] = 15;

    pc1 += pc2;

    std::cout << pc2(0) << "\n";

    PolyMod<int, pc1, 5> pm1(3);
    PolyMod<int, pc1, 5> pm2(3);

    pm1[2] = 2;
    pm2[2] = 2;

    pm1 *= pm2;

    std::cout << pm1 << "\n";
    return 0;
}
