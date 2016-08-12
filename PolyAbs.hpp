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

    //inline void adjustDegree();
public:
    PolyAbs() = default;
    explicit PolyAbs(int deg) : _degree(deg) {}
    virtual PolyAbs& operator*=(const PolyAbs&) {};
    //virtual PolyAbs operator*(const PolyAbs&) {};

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
std::ostream& operator<<(std::ostream& out, const PolyAbs<T>& pol) {

    std::cout << "Polynomial: ";

    for(int i = pol.getDeg(); i >= 0; --i) {
	//std::cout << "asking for i: " << i << "\n";
	if(pol[i] != 0) {
	    if(i != pol.getDeg() && pol[i] > 0) out << "+"; 	// last number or negative
	    out << pol[i];
	    if(i > 0) {
		out << "x";
		if(i > 1) {
		    out << "^" << i << " ";
		}
	    }
	}
    }
    return out;
}


template <typename T>
std::istream& operator>>(std::istream& in, PolyAbs<T>& pol){
    for(int i = pol.getDeg(); i >= 0; --i) {
        std::cout << "x^" << i << ": ";
        in >> pol[i];
    }
    return in;
}


#endif /* POLYABS_H */
