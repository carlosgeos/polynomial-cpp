#ifndef POLYMOD_H
#define POLYMOD_H


#include <iostream>
#include <cstdlib>
#include "staticVect.hpp"

template<typename TYPE, typename div, size_t DEG>
class PolyMod :
  public StaticVector<TYPE, DEG>
{
  TYPE _array[DEG] = {};
public:
  PolyMod() {
    _array[2] = 3.5;
  };
  void printVector(std::ostream& os) const override
  {
    os << "YEAHHHH" << "\n";
    os << "Vector :" << "\n[ ";
    for (std::size_t i = 0; i < DEG; ++i)
      os << _array[i] << " " ;
    os << "]\n";
  }

  virtual ~PolyMod() = default;
};

#endif /* POLYMOD_H */
