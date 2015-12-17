/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>

#include "StaticVect.hpp"
#include "DynamicVect.hpp"
#include "Poly.hpp"

int main() {

  StaticVector<int, 4> sv;
  sv[1] = 17;
  sv[2] = 3;
  sv[3] = -23;
  StaticVector<int, 4> sv2;
  sv2[1] = 7;
  StaticVector<int, 4> sv3;
  sv3[0] = 1;

  sv += sv2;
  sv3 -= sv;


  std::cout << sv3 << "\n";
  -sv3;

  sv3 += sv;

  std::cout << sv3 << "\n";

  std::cout << "dyyyyyyyyyyyyyyyyyyyyyyyyyyyyn" << "\n";

  DynamicVector<int> dv1(4,4);

  std::cout << dv1 << "\n";

  Poly<int> eso(7,7);
  Poly<int> esa(2,3);
  std::cout << eso << "\n";

  esa += eso;

  std::cout << esa << "\n";



  return 0;
}
