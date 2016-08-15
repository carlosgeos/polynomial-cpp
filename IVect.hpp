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

    virtual IVect& operator=(const IVect&) = default;

    // Sum
    virtual IVect& operator+=(const IVect&);
    virtual IVect& operator++();

    // Substraction
    virtual IVect& operator-=(const IVect&);
    virtual IVect& operator--();

    // TYPE product
    virtual IVect& operator*=(const TYPE);

    // Dot product
    virtual TYPE operator*(const IVect&) final;

    virtual ~IVect() = default;

};


template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator+=(const IVect<TYPE> &rhs)
{
    for (size_t i = 0; i < (*this).siz(); ++i) (*this)[i] += rhs[i];
    return *this;
}

template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator-=(const IVect<TYPE> &rhs)
{
    for (size_t i = 0; i < (*this).siz(); ++i) (*this)[i] -= rhs[i];
    return *this;
}

template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator++()
{
    for (size_t i = 0; i < (*this).siz(); ++i) (*this)[i] += 1;
    return *this;
}

template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator--()
{
    for (size_t i = 0; i < (*this).siz(); ++i) (*this)[i] -= 1;
    return *this;
}

template<typename TYPE>
IVect<TYPE>& IVect<TYPE>::operator*=(TYPE value)
{
    for (size_t i = 0; i < (*this).siz(); ++i) (*this)[i] *= value;
    return *this;
}

template<typename TYPE>
TYPE IVect<TYPE>::operator*(const IVect<TYPE> &rhs)
{
    TYPE res = 0;
    for (size_t i = 0; i < (*this).siz(); ++i)
	res += (*this)[i] * rhs[i];
    return res;
}

// Non-member -------------------------

template<typename TYPE>
std::ostream& operator<<(std::ostream& os, const IVect<TYPE>& c)
{
    os << "Vector : " << "[ ";
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

#endif /* IVECT_H */
