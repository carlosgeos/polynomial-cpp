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

  sv2[3] = 1;
  sv2[2] = 2;
  sv2[1] = 3;
  sv2[0] = 4;

  std::cout << "--------------------------" << "\n";
  std::cout << "todo bien" << "\n";

  std::cout << "asdf asdf" << "\n";

  int esa[5] = {1,2,3,4,5};
  int eso[5] = {10,9,8,7,6};

  int ese[5];

  return 0;
}
