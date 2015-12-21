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
#include "PolyMod.hpp"




int main() {


  StaticVector<int, 5> static_vector1;
  static_vector1[2] = 2;
  static_vector1[1] = 3;
  std::cout << static_vector1 << "\n"; // [ 0 3 2 0 0 ]

  DynamicVector<double> dyn_vector1(5, 3); // [ 3 3 3 3 3 ]
  DynamicVector<double> dyn_vector2(5, 2); // [ 2 2 2 2 2 ]

  std::cout << dyn_vector1 << "\n";
  std::cout << dyn_vector2 << "\n";

  dyn_vector1 =  2 - dyn_vector2; // With implicit conversion
  dyn_vector1[3] = 3.5;
  dyn_vector1 *= 3.2;

  std::cout << dyn_vector1 << "\n"; // [ 0 -6.4 -6.4 11.2 -6.4 ]

  Poly<double> poly1(size_t(5)); // Avoid calling conversion ctor

  poly1[0] = 5; poly1[2] = 3; poly1[3] = 1; poly1[4] = -2;
  std::cout << poly1 << "\n";	// -2x^4 + 1x^3 + 3x^2 + 5
  poly1 += 5;			// -2x^4 + 1x^3 + 3x^2 + 10

  Poly<double> poly2(size_t(3));
  poly2[0] = 3; poly2[1] = 2; poly2[2] = -1;
  std::cout << poly2 << "\n"; 	// -1x^2 + 2x^1 + 3

  poly1 = poly1 * poly2;
  std::cout << poly1 << "\n";	// +2x^6 -5x^5 -7x^4  +9x^3 -1x^2  +20x^1  +30

  -poly1;			// -2x^6 +5x^5 +7x^4  -9x^3 +1x^2  -20x^1  -30

  std::cout << poly1(2) << "\n"; // 6

  // constexpr as non type parameter for template.
  // PolyMod<int, static_vector1, 4> polymod1;


  return 0;
}
