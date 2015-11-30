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
  DynamicVector<int> dv(5);

  dv[3] = 3;
  dv[0] = 14;

  std::cout << "dv" << dv << "\n";


  StaticVector<int, 4> sv;
  sv[3] = 7;
  sv[2] = 1;
  sv[1] = 4;
  sv[0] = 10;

  //DynamicVector<int> dv2(sv);

  StaticVector<int, 4> sv2;
  sv2[3] = 1;
  sv2[2] = 2;
  sv2[1] = 3;
  sv2[0] = 4;

  StaticVector<int, 4> sv3;
  StaticVector<int, 4> sv4;


  StaticVector<double, 4> d_sv1;
  StaticVector<double, 5> d_sv2;
  StaticVector<double, 6> d_sv5;
  StaticVector<double, 7> d_sv3;


  d_sv1[3] = 1.12;
  d_sv1[2] = 2.65;
  d_sv1[1] = 3.987;
  d_sv1[0] = 4.2;

  // sv3[3] = 1;
  // sv3[2] = 2;
  // sv3[1] = 3;
  // sv3[0] = 4;

  sv3 = sv + sv2;
  sv4 = sv + sv2;
  sv4 = -sv4;

  std::cout << +sv << "\n";
  std::cout << sv2 << "\n";
  std::cout << sv3 << "\n";
  std::cout << sv4 << "\n";

  std::cout << d_sv1 << "\n";

  std::cout << "--------------------------" << "\n";
  std::cout << "todo bien" << "\n";

  return 0;
}
