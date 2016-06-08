#ifndef IVECT_H
#define IVECT_H

#include <cstdlib>
#include <iostream>

// Vector interface
template<typename Elem>
class IVect
{
    // I/O
    template<class T>
    friend std::ostream& operator<<(std::ostream& os, const IVect<T>& v);
    template<class T>
    friend std::istream& operator>>(std::istream& is, IVect<T>& v);
protected:
    IVect() = default;
    virtual ~IVect() = default;
public:
    virtual std::size_t siz() const = 0;

    template<class VectType>
    friend VectType operator+(const VectType& v1, const VectType& v2);
    template<class VectType>
    friend VectType operator-(const VectType& v1, const VectType& v2);

    // Access to the vector
    virtual const Elem& operator[] (std::ptrdiff_t) const = 0;
    virtual Elem& operator[](std::ptrdiff_t i) = 0;

    // Addition
    virtual IVect& operator+=(const IVect<Elem>&);
    //virtual IVect operator*=(const TYPE&);

    // Product
    //virtual IVect<Elem> operator*(const Elem*) const;
    virtual IVect& operator*=(const Elem&);

    // Substraction
    virtual IVect& operator-=(const IVect<Elem>&) = 0;
    virtual IVect& operator--();

};

#endif /* IVECT_H */
