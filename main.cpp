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
  StaticVector<int, 4> sv3;
  StaticVector<int, 4> sv4;
  sv[3] = 7;
  sv[2] = 1;
  sv[1] = 4;
  sv[0] = 10;

  sv2[3] = 1;
  sv2[2] = 2;
  sv2[1] = 3;
  sv2[0] = 4;

  // sv3[3] = 1;
  // sv3[2] = 2;
  // sv3[1] = 3;
  // sv3[0] = 4;

  sv3 = sv + sv2;

  sv4 = sv3 - sv;

  std::cout << sv3 << "\n";
  std::cout << sv4 << "\n";

  std::cout << "SV es:" << "\n";
  std::cout << sv << "\n";
  std::cout << "SV2 es:" << "\n";
  std::cout << sv2 << "\n";

  std::cout << "--------------------------" << "\n";
  std::cout << "todo bien" << "\n";

  return 0;
}
