/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>

//#include "staticVect.hpp"
//#include "dynamicVect.hpp"
#include "staticVect.hpp"

int main() {

    StaticVector<int, 5> v1;
    v1[2] = 2;
    StaticVector<int, 5> v2;
    v2[3] = 2;

    StaticVector<int, 5> v3;
    v1 += v2;
    std::cout << v1 << "\n";
    std::cout << "testing" << "\n";

    return 0;
}
