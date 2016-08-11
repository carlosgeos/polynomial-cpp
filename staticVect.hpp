#ifndef STATICVECT_H
#define STATICVECT_H

#include "IVect.hpp"

// Formward declaration
template <typename TYPE>
class DynamicVector;

template<typename TYPE, size_t SIZE>
class StaticVector : public IVect<TYPE>
{
    // Array declaration and INITIALIZATION
    TYPE _array[SIZE] = {};
public:
    StaticVector() = default;
    virtual ~StaticVector () = default;
    explicit StaticVector (const DynamicVector<TYPE>&); // Conversion ctor

    inline size_t siz() const override {return SIZE;}

    // Sum
    virtual StaticVector& operator+= (const IVect<TYPE> &other) override;
    //virtual StaticVector& operator++ ();

    // Substraction
    virtual StaticVector& operator-= (const IVect<TYPE> &other) override;
    virtual StaticVector& operator-- () override;

    // Access
    const TYPE& operator[] (std::ptrdiff_t) const override;
    TYPE& operator[] (std::ptrdiff_t) override;

};

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>::StaticVector(const DynamicVector<TYPE>& dv)
{
    for (size_t i = 0; i < SIZE; ++i) {
	if (dv.getSize() > i) {
	    _array[i] = dv[i];
	}
    }
}


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator+=(const IVect<TYPE> &other)
{
    for (size_t i = 0; i < SIZE; i++) _array[i] += other[i];
    return *this;
}


//template<typename TYPE, size_t SIZE>
//StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator++()
//{
//    ;
//}


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator-=(const IVect<TYPE> &other)
{
    for (size_t i = 0; i < SIZE; i++) _array[i] -= other[i];
    return *this;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator--()
{
    for (size_t i = 0; i < SIZE; i++) _array[i] += 1;
    return *this;
}


template <typename TYPE, std::size_t SIZE>
const TYPE& StaticVector<TYPE, SIZE>::operator[] (std::ptrdiff_t i) const
{
    if (std::size_t(i) >= SIZE)
	throw std::out_of_range("Vector index out of range");
    return _array[i];
}

template <typename TYPE, std::size_t SIZE>
TYPE& StaticVector<TYPE, SIZE>::operator[] (std::ptrdiff_t i)
{
    if (std::size_t(i) >= SIZE)
	throw std::out_of_range("Vector index out of range");
    return _array[i];
}

#endif /* STATICVECT_H */
