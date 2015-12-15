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

int main() {

  DynamicVector<int> dv3(6,3);

  dv3[2] = 1;

  std::cout << dv3 << "\n";

  StaticVector<int, 8> svconv(dv3);

  std::cout << svconv << "\n";
  return 0;
}
