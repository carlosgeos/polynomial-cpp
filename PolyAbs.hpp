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
    //virtual size_t siz() const {return 4;};
    inline void adjustDegree();
public:
    PolyAbs() = default;
    virtual PolyAbs& operator*=(const PolyAbs&) {};
    //virtual PolyAbs operator*(const PolyAbs&) {};

    int getDeg() const {return _degree;};
    virtual TYPE operator()(const TYPE eval) const;

    virtual ~PolyAbs() = default;
};

template <typename TYPE>
TYPE PolyAbs<TYPE>::operator()(const TYPE eval) const {
    TYPE total = 0;
    TYPE valeurX = 1;
    int degre = this -> getDeg();

    if(degre > 0) {
        for(std::size_t i = 0; i <= size_t(getDeg()); ++i) {
            total += (*this)[i]*valeurX;
            valeurX *= eval;
        }
    }
    return total;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const PolyAbs<T>& pol) {
    const int degre = pol.degre();

    if(degre < 0) {
        out << 0;
    } else {
        for(int i = degre; i >= 0; --i) {
            if(pol[i] != 0) {
                if(i != degre) {
                    out << " + ";
                }

                out << pol[i];
                if(i > 0) {
                    out << "X";
                    if(i > 1) {
                        out << "^" << i;
                    }
                }
            }
        }
    }
    return out;
}


template <typename T>
std::istream& operator>>(std::istream& in, PolyAbs<T>& pol){
    pol._degre = -1;
    for(int i = int(pol.siz())-1; i >= 0; --i) {
        std::cout << "X^" << i << ": ";
        in >> pol[i];

        if(pol._degre == -1 && pol[i] != 0) {
            pol._degre = int(i);
        }
    }

    return in;
}


#endif /* POLYABS_H */
