#ifndef POLYCON_H
#define POLYCON_H

#include "dynamicVect.hpp"
#include "PolyAbs.hpp"

// Concrete Polynomial
template<typename TYPE>
class PolyCon : public DynamicVector<TYPE>, public PolyAbs<TYPE>
{
public:
    PolyCon() = default;

    virtual ~PolyCon() = default;
};


#endif /* POLYCON_H */
