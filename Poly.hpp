#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <cstdlib>

#include "IPoly.hpp"
#include "DynamicVect.hpp"

template<typename TYPE>
class Poly :
  public DynamicVector<TYPE>,
  public IPoly<Poly<TYPE>>
{
public:
  Poly() = default;
  Poly(size_t size, const TYPE& elem) : DynamicVector<TYPE>(size, elem) {};
  void printVector(std::ostream& os) const {
    os << "YEAHHHH";
  }
  ~Poly() = default;
};



#endif /* POLY_H */
