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
    // Access
    virtual const TYPE& operator[] (std::ptrdiff_t) const = 0;
    virtual TYPE& operator[] (std::ptrdiff_t) = 0;

    // Sum
    virtual IVect& operator+=(const IVect &other) = 0;
    virtual IVect& operator++() = 0;
    // OPERATOR + is non-member

    // Substraction
    virtual IVect& operator-=(const IVect &other) = 0;
    virtual IVect& operator--() = 0;
    // OPERATOR - is non-member

    virtual ~IVect() = default;

};

template<typename TYPE>
IVect<TYPE> operator+(const IVect<TYPE> &other1, const IVect<TYPE> &other2)
{
    return other1 += other2;
}

#endif /* IVECT_H */
