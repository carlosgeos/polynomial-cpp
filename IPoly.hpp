#ifndef IPOLY_H
#define IPOLY_H

#include <iostream>
#include <cstdlib>

#include "IVect.hpp"

template<typename PolyType, typename TYPE>
class IPoly
{
protected:
  IPoly() = default;
  virtual ~IPoly() = default;
private:
  const PolyType& child() const {return *static_cast<const PolyType*>(this);}
  PolyType& child() {return *static_cast<PolyType*>(this);}
public:
  TYPE operator() (const TYPE& elem) {
    return child().horner(elem);}
  friend PolyType operator*(const PolyType& p1, const PolyType& p2) {
    return p1.mulmul(p2);}

};

#endif /* IPOLY_H */
