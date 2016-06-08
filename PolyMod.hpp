#ifndef POLYMOD_H
#define POLYMOD_H


#include <iostream>
#include <cstdlib>

#include "Poly.hpp"

template<typename TYPE, int DEG, const StaticVector<TYPE, DEG-1>& div>
class PolyMod : public Poly<TYPE>
{
public:
  using Poly<TYPE>::Poly;
  int deg() const {return static_cast<int>(this -> getSize() - 1);} // getter
  void print(std::ostream&) const override;
  PolyMod mulPol(const PolyMod&) const override; // polynomial multiplication
};

template<typename TYPE, int DEG, const StaticVector<TYPE, DEG-1>& div>
void PolyMod<TYPE, DEG, div>::print(std::ostream& os) const {
  os << "Polynomial :\n";
  for (std::size_t i = DEG + 1; i --> 0;) {
    if ((*this)[i]) {
      if ((*this)[i] >= 0) os << " +";
      os << (*this)[i];
      if (i) os << "x^" << i;
      os << " ";
    }
  }

  os << "\n";
  os << "Mod ";
  os << div;
}

template<typename TYPE, int DEG, const StaticVector<TYPE, DEG-1>& div>
PolyMod<TYPE, DEG, div> PolyMod<TYPE, DEG, div>::mulPol(const PolyMod& p2) const
{
  PolyMod<TYPE, DEG, div> p3;
  int new_degree = deg() < 0 || p2.deg() < 0 ? -1 : deg() + p2.deg();
  p3[new_degree];		// adjust size
  for (int i = 0; i < DEG && i <= new_degree; ++i) {
    int ci = 0;
    for (int j = (p2.deg() < i ? i - p2.deg() : 0); j <= i && j <= deg(); ++j)
      ci += (*this)[j] * p2[i - j];
    p3[i] = ci;
  }
  for (int i = DEG; i <= new_degree; ++i) {
    int ci = 0, m = 0;
    for (int j = i - p2.deg(); j <= deg(); ++j) ci += (*this)[j] * p2[i - j];
    for (int j = i - DEG; j < DEG; ++j) p3[j] += ci*div[m++];
    for (int j = 0; j < i - DEG; ++j) p3[j] += ci*div[m++];
  }
  if (new_degree < DEG)
    for (int i = new_degree + 1; i < DEG; ++i) p3[i] = 0;
  else
    for (new_degree = DEG - 1; new_degree >= 0 && p3[new_degree] == 0; --new_degree);
  p3[new_degree];		// adjust
}

#endif /* POLYMOD_H */
