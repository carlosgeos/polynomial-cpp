#ifndef STATICVECT_H
#define STATICVECT_H

#include "IVect.hpp"

// Forward declaration
template <typename TYPE>
class DynamicVector;

template<typename TYPE, size_t SIZE>
class StaticVector : public virtual IVect<TYPE>
{
    // Array declaration and INITIALIZATION
    TYPE _array[SIZE] = {};
public:
    StaticVector() = default;
    virtual ~StaticVector () = default;
    explicit StaticVector (const DynamicVector<TYPE>&); // Conversion ctor

    inline size_t siz() const override {return SIZE;}
    StaticVector operator+(const StaticVector &);
    StaticVector operator-(const StaticVector &);

    // Access
    const TYPE& operator[] (std::ptrdiff_t) const override;
    TYPE& operator[] (std::ptrdiff_t) override;

};

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>::StaticVector(const DynamicVector<TYPE>& dv)
{
    for (size_t i = 0; i < SIZE; ++i) {
	if (dv.siz() > i) {
	    _array[i] = dv[i];
	}
    }
}

template <typename TYPE, size_t SIZE>
const TYPE& StaticVector<TYPE, SIZE>::operator[] (std::ptrdiff_t i) const
{
    if (std::size_t(i) >= SIZE)
	throw std::out_of_range("Vector index out of range");
    return _array[i];
}

template <typename TYPE, size_t SIZE>
TYPE& StaticVector<TYPE, SIZE>::operator[] (std::ptrdiff_t i)
{
    if (std::size_t(i) >= SIZE)
	throw std::out_of_range("Vector index out of range");
    return _array[i];
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator+(const StaticVector<TYPE, SIZE>& other) {
    StaticVector result = *this;
    result += other;
    return result;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator-(const StaticVector<TYPE, SIZE>& other) {
    StaticVector result = *this;
    result -= other;
    return result;
}

#endif /* STATICVECT_H */
