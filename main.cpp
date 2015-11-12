/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>

#include "staticVect.hpp"
//#include "dynamicVect.hpp"

int main() {
  StaticVector<int, 4> sv;
  StaticVector<int, 4> sv2;
  sv[3] = 7;
  sv[2] = 1;
  sv[1] = 4;
  sv[0] = 10;

  sv2[3] = 7;
  sv2[2] = 1;
  sv2[1] = 4;
  sv2[0] = 10;
  StaticVector<int, 4> sv3;

  sv += sv2;
  std::cout << sv << "\n";
  std::cout << sv2 << "\n";
  std::cout << "--------------------------" << "\n";
  std::cout << "todo bien" << "\n";
  return 0;
}
