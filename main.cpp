/**
 * Projet C++	: Polynômes modulaires
 * Matricule	: 410031
 * Nom		: Requena López
 * Prénom	: Carlos
 * Année	: 2015-2016
 */

#include <iostream>


#include "PolyCon.hpp"
#include "PolyMod.hpp"

PolyCon<int> divi(3); 		// DIV


int main() {
    std::cout << "STATIC VECTOR TEST" << "\n";
    std::cout << "------------------" << "\n";
    StaticVector<int, 4> sv1;
    StaticVector<int, 4> sv2;
    ++sv1;
    sv1[2] = 3;
    sv1[0] = -2;
    sv2[3] = 1;
    sv2[1] = 5;
    sv2[3] = 2;

    std::cout << "sv1 - Static " << sv1 << "\n";
    std::cout << "sv2 - Static " << sv2 << "\n";

    std::cout << "sv1 + sv2 : " << sv1 + sv2;
    std::cout << "sv1 - sv2 : " << sv1 - sv2;
    std::cout << "sv1 * sv2 : " << sv1 * sv2 << " (dot product)\n";
    std::cout << "++sv1     : " << ++sv1;
    std::cout << "--sv2     : " << --sv2 << "\n";

    DynamicVector<int> csv1(sv1);
    std::cout << "Conversion static -> dynamic: " << csv1 << "\n";



    std::cout << "\nDYNAMIC VECTOR TEST" << "\n";
    std::cout << "-------------------" << "\n";
    DynamicVector<double> dv1(3);
    DynamicVector<double> dv2(3);
    dv1[1] = -1; dv1[2] = 2; dv1[0] = 5;
    dv2[1] = 3; dv2[2] = 1; dv2[0] = -2;

    std::cout << "dv1 - Dynamic" << dv1 << "\n";
    std::cout << "dv2 - Dynamic" << dv2 << "\n";

    std::cout << "dv1 + dv2 : " << dv1 + dv2;
    std::cout << "dv1 - dv2 : " << dv1 - dv2;
    std::cout << "dv1 * dv2 : " << dv1 * dv2 << " (dot product)\n";
    std::cout << "++dv1     : " << ++dv1;
    std::cout << "--dv2     : " << --dv2 << "\n";

    StaticVector<double, 5> cdv1(dv1);
    std::cout << "Conversion dynamic -> static: " << cdv1 << "\n";

    std::cout << "\nNORMAL POLYNOMIAL TEST" << "\n";
    std::cout << "----------------------" << "\n";
    PolyCon<double> pc1(2);
    PolyCon<double> pc2(2);
    pc1[0] = 3; pc1[1] = 2; pc1[2] = 1;
    pc2[0] = -2; pc2[1] = 1; pc2[2] = 4;
    std::cout << pc1 << "\n";
    std::cout << pc2 << "\n\n";

    pc1 *= pc2;
    std::cout << "pc1 * pc2 (MulPod)   : " << pc1 << "\n";
    std::cout << "Eval pc2(1) - Horner : " << pc2(1) << "\n";


    std::cout << "\nMOD POLYNOMIAL TEST" << "\n";
    std::cout << "-------------------" << "\n";
    PolyMod<int, divi, 3> pm1;
    PolyMod<int, divi, 3> pm2;
    divi[0] = 1; divi[1] = 0; divi[2] = 0;
    pm1[0] = 2; pm1[1] = 4; pm1[2] = 3;
    pm2[0] = -3; pm2[1] = 1; pm2[2] = 2;
    std::cout << "DIV " << divi << "\n";
    std::cout << "WHICH IS EQUAL TO x^3 - 1 | (d1(x) = x^n - d(x))" << "\n";
    std::cout << "MOD - pm1 - " << pm1 << "\n";
    std::cout << "MOD - pm2 - " << pm2 << "\n";

    pm1 *= pm2;
    std::cout << "\npm1 *= pm2 mod DIV" << "\n";
    std::cout << "RESULT: " << pm1 << "\n";
    std::cout << "Eval pm1(0) : " << pm1(0) << "\n";

    return 0;
}
