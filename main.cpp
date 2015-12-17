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

  std::cout << sv << "\n";
  sv = (sv + sv2);

  std::cout << sv << "\n";

  // StaticVector<int, 4> sv3;
  // sv3[0] = 1;

  // sv += sv2;
  // sv3 -= sv;


  // std::cout << sv3 << "\n";
  // -sv3;

  // sv3 += sv;

  // std::cout << sv3 << "\n";

  // std::cout << "dyyyyyyyyyyyyyyyyyyyyyyyyyyyyn" << "\n";

  // DynamicVector<int> dv1(4,4);

  // std::cout << dv1 << "\n";

  // int a =5;

  // dv1 = a + dv1;



  // std::cout << dv1 << "\n";

  Poly<int> eso(4, 2);
  std::cout << eso << "\n";
  Poly<int> esa(4, 3);
  esa[2] = -4;
  std::cout << esa << "\n";

  esa[8] = 1;

  Poly<int> sol = esa * eso;

  std::cout << sol << "\n";


  return 0;
}
