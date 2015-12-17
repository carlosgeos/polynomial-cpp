#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <cstdlib>

#include "IPoly.hpp"
#include "DynamicVect.hpp"

template<typename TYPE>
class Poly :
  public DynamicVector<TYPE>,
  public IPoly<Poly<TYPE>, TYPE>
{
public:
  using DynamicVector<TYPE>::DynamicVector;
  int deg() const {return static_cast<int>(this -> getSize() - 1);} // getter
  void print(std::ostream& os) const override;
  TYPE horner(const TYPE&) const; // operator(), evaluation
  Poly mulmul(const Poly&) const; // polynomial multiplication
};

template<typename TYPE>
void Poly<TYPE>::print(std::ostream& os) const {
  os << "Polynomial :\n";
  for (std::size_t i = this -> _size; i --> 0;) {
    if (this -> _val[i]) {
      if (this -> _val[i] >= 0) os << " +";
      os << this -> _val[i];
      if (i) os << "x^" << i;
      os << " ";
    }
  }
  os << "\n";
}

template<typename TYPE>
TYPE Poly<TYPE>::horner(const TYPE& elem) const
{
  TYPE res = (*this)[deg()];
  for (int i = deg() - 1; i >= 0; i--) {
    res = (res * elem) + (*this)[i];
  }
  return res;
}

template<typename TYPE>
Poly<TYPE> Poly<TYPE>::mulmul(const Poly& p2) const
{
  Poly<TYPE> p3;
  if (deg() < 0 || p2.deg() < 0) {;} // NOP
  else {
    p3[deg() + p2.deg()];		// adjust size
    for (size_t j = 0; j <= static_cast<size_t>(p2.deg()); ++j)
      p3[j] = (*this)[0] * p2[j];
    for (size_t i = 1; i <= static_cast<size_t>(deg()); ++i) {
      for (size_t j = 0; j < static_cast<size_t>(p2.deg()); ++j)
	p3[i+j] += (*this)[i] * p2[j];
      p3[i + p2.deg()] = (*this)[i] * p2[p2.deg()];
    }
  }
  return p3;
}



#endif /* POLY_H */
