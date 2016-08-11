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

int main() {

    StaticVector<int, 5> v1;
    v1[2] = 2;
    StaticVector<int, 5> v2;
    v2[3] = 2;

    StaticVector<int, 5> v3;
    ++v1;
    ++v1;

    DynamicVector<int> v4;
    DynamicVector<int> v5;
    v4[5] = 5;
    v5[4] = 5;

    PolyCon<int> p1();


    return 0;
}
