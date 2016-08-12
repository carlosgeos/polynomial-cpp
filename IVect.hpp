#ifndef IVECT_H
#define IVECT_H


#include <cstdlib>
#include <iostream>

template<typename TYPE>
class IVect
{
    // Input
    template<typename ANY>
    friend std::istream& operator>>(std::istream&, const IVect<ANY>&);

    // Output
    template<typename ANY>
    friend std::ostream& operator<<(std::ostream&, const IVect<ANY>&);
public:
    virtual size_t siz() const = 0;
    // Access
    virtual const TYPE& operator[] (std::ptrdiff_t) const = 0;
    virtual TYPE& operator[] (std::ptrdiff_t) = 0;

    virtual IVect& operator=(const IVect<TYPE>&) = default;

    // Sum
    virtual IVect& operator+=(const IVect &other) = 0;
    virtual IVect& operator++();
    // OPERATOR + is non-member

    // Substraction
    virtual IVect& operator-=(const IVect &other) = 0;
    virtual IVect& operator--();

    virtual ~IVect() = default;

};

template<typename TYPE>
std::ostream& operator<<(std::ostream& os, const IVect<TYPE>& c)
{
    os << "Vector :" << "\n[ ";
    for (std::size_t i = 0; i < c.siz(); ++i)
	os << c[i] << " " ;
    os << "]\n";
    return os;
}

template<typename TYPE>
std::istream& operator>>(std::istream& is, const IVect<TYPE>& c)
{
    for (size_t i = 0; i < c.siz(); ++i) is >> c[i];
    return is;
}


template<typename TYPE>
IVect<TYPE>& operator+(IVect<TYPE>& v1, IVect<TYPE>& v2)
{
    v1 += v2;
    return v1;
}


template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator++()
{
    for (size_t i = 0; i < this -> siz(); ++i) (*this)[i] += 1;
    return *this;
}

template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator--()
{
    for (size_t i = 0; i < this -> siz(); ++i) (*this)[i] -= 1;
    return *this;
}


#endif /* IVECT_H */
