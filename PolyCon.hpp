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

    virtual PolyCon& operator*=(const PolyAbs<TYPE>&) override;
    virtual ~PolyCon() = default;
};

template<typename TYPE>
PolyCon<TYPE>::PolyCon(int deg) :
    DynamicVector<TYPE>(deg + 1),
    PolyAbs<TYPE>(deg)
{

}

template<typename TYPE>
PolyCon<TYPE>& PolyCon<TYPE>::operator*=(const PolyAbs<TYPE>& poly)
{
    const int da = (*this).getDeg();
    const int db = poly.getDeg();
    int dc;
    if (da < 0 || db < 0) {
	dc = -1;
	PolyCon<TYPE> c(1);
	c[0] = 0;
	(*this) = c;
    } else {
	// Non-null product
	dc = da + db;
	PolyCon<TYPE> c(dc);
	for (int j = 0; j <= db; ++j) c[j] = (*this)[0] * poly[j];
	for (int i = 1; i <= da; ++i) {
	    for (int j = 0; j < db; ++j) c[i + j] += (*this)[i] * poly[j];
	    c[i + db] = (*this)[i] * poly[db];
	}
	(*this) = c;
    }
    return *this;
}

#endif /* POLYCON_H */
