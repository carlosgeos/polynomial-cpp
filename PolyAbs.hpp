#ifndef POLYABS_H
#define POLYABS_H

#include "IVect.hpp"

template<typename TYPE>
class PolyAbs: public virtual IVect<TYPE>
{
    template <typename T>
    friend std::ostream& operator<<(std::ostream&, const PolyAbs<T>&);

    template <typename T>
    friend std::istream& operator>>(std::istream&, PolyAbs<T>&);

    int _degree;

public:
    PolyAbs() = default;
    explicit PolyAbs(int deg) : _degree(deg) {}
    virtual PolyAbs& operator*=(const PolyAbs&) = 0;

    int getDeg() const {return _degree;};
    void updateDegree(int deg) {_degree = deg;};
    virtual TYPE operator()(const TYPE eval) const;

    virtual ~PolyAbs() = default;
};

template <typename TYPE>
TYPE PolyAbs<TYPE>::operator()(const TYPE eval) const {
    TYPE total = 0;
    TYPE x = 1;

    for(size_t i = 0; i <= size_t(getDeg()); ++i) {
	total += (*this)[i] * x;
	x *= eval;
    }
    return total;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const PolyAbs<T>& poly) {

    std::cout << "Polynomial (degree " << poly.getDeg() << "): ";

    for(int i = poly.getDeg(); i >= 0; --i) {
	if(poly[i] != 0) {
	    if(i != poly.getDeg() && poly[i] > 0) out << "+"; 	// last number or negative
	    out << poly[i];
	    if(i > 0) {
		out << "x";
		if(i > 1) {
		    out << "^" << i << " ";
		} else out << " ";
	    }
	}
    }
    return out;
}


template <typename T>
std::istream& operator>>(std::istream& in, PolyAbs<T>& poly){
    for(int i = poly.getDeg(); i >= 0; --i) {
        std::cout << "x^" << i << ": ";
        in >> poly[i];
    }
    return in;
}


#endif /* POLYABS_H */
