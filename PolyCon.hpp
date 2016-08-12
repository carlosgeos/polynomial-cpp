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
    explicit PolyCon(int deg);

    virtual ~PolyCon() = default;
};

template<typename TYPE>
PolyCon<TYPE>::PolyCon(int deg) :
    DynamicVector<TYPE>(deg + 1),
    PolyAbs<TYPE>(deg)
{

}

#endif /* POLYCON_H */
