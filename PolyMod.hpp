#ifndef POLYMOD_H
#define POLYMOD_H

#include "PolyCon.hpp"
#include "staticVect.hpp"

template<typename TYPE, const PolyCon<TYPE>& div, int deg>
class PolyMod : public PolyAbs<TYPE>, public StaticVector<TYPE, deg>
{
public:
    PolyMod() : PolyAbs<TYPE>(deg - 1), StaticVector<TYPE, deg>() {};
    explicit PolyMod(int d) : PolyAbs<TYPE>(d), StaticVector<TYPE, deg>() {};

    PolyMod& operator*=(const PolyAbs<TYPE>& poly) override;

    virtual ~PolyMod() = default;
};

template<typename TYPE, const PolyCon<TYPE>& div, int deg>
PolyMod<TYPE, div, deg>& PolyMod<TYPE, div, deg>::operator*=(const PolyAbs<TYPE>& poly)
{
    const int da = (*this).getDeg();
    const int db = poly.getDeg();
    int dc = da < 0 || db < 0 ? -1 : da + db;
    PolyMod<TYPE, div, deg> c(dc);
    const int n = deg;

    for (int i = 0; i < deg; ++i) {
	int ci = 0;
	for (int j = (db < i ? i - db : 0); j <= i && j <= da; ++j)
	    ci += (*this)[j] * poly[i - j];
	c[i] = ci;
    }

    for (int i = n; i <= dc; ++i) {
	int ci = 0, m = 0;
	for (int j = i - db; j <= da; ++j) ci += (*this)[j] * poly[i - j];
	for (int j = i - n; j < n; ++j) c[j] += ci*div[m++];
	for (int j = 0; j < i - n; ++j) c[j] += ci*div[m++];
    }

    // Adjust degree
    if (dc < n) for (int i = dc + 1; i < n; ++i) c[i] = 0;
    else for (dc = n - 1; dc >= 0 && c[dc] == 0; --dc);
    c.updateDegree(dc);

    (*this) = c;
    return *this;
}


#endif /* POLYMOD_H */
