/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>

#include "staticVect.hpp"
#include "dynamicVect.hpp"

int main() {

  DynamicVector<int> dv(6);
  std::cout << "Six zeroes" << "\n";
  std::cout << dv << "\n";

  StaticVector<int, 4> sv;
  sv[0] = 10;
  sv[1] = 4;
  sv[2] = 1;
  sv[3] = 7;
  std::cout << "Next 2 should be [ 10 4 1 7 ]" << "\n";
  std::cout << sv << "\n";
  DynamicVector<int> dv2(sv); 	// Conversion
  std::cout << dv2 << "\n";

  return 0;
}
