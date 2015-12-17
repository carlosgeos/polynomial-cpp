#ifndef STATICVECT_H
#define STATICVECT_H

#include "IVect.hpp"

// Forward declaration
template <typename TYPE>
class DynamicVector;

// size_t is used since that is the result type of sizeof expression
// and is preferred for counting in arrays etc.
template<typename TYPE, size_t SIZE>
class StaticVector : public IVect<StaticVector<TYPE, SIZE>>
{
  // Array declaration and INITIALIZATION
  TYPE _array[SIZE] = {};
public:
  StaticVector() = default;
  ~StaticVector () = default;		      // Default ctor
  explicit StaticVector (const DynamicVector<TYPE>&); // Conversion ctor
  StaticVector& addMe (const StaticVector &other);
  StaticVector& subMe (const StaticVector &other);
  StaticVector& minus ();
  const TYPE get (std::ptrdiff_t) const;
  TYPE& get(std::ptrdiff_t);
  void printVector (std::ostream& os) const;

};

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>::StaticVector(const DynamicVector<TYPE>& dv) {
  for (size_t i = 0; i < SIZE; ++i) {
    if (dv.getSize() > i) {
      _array[i] = dv[i];
    }
  }
}


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::addMe(const StaticVector<TYPE, SIZE> &other)
{
  for (size_t i = 0; i < SIZE; i++) _array[i] += other[i];
  return *this;
}


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::subMe(const StaticVector<TYPE, SIZE> &other)
{
  for (size_t i = 0; i < SIZE; i++) _array[i] -= other[i];
  return *this;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::minus()
{
  for (size_t i = 0; i < SIZE; i++) _array[i] = -(_array[i]);
  return *this;
}


template <typename TYPE, std::size_t SIZE>
const TYPE StaticVector<TYPE, SIZE>::get(std::ptrdiff_t i) const
{
  if (std::size_t(i) >= SIZE)
    throw std::out_of_range("Vector index out of range");
  return _array[i];
}

template <typename TYPE, std::size_t SIZE>
TYPE& StaticVector<TYPE, SIZE>::get (std::ptrdiff_t i)
{
  if (std::size_t(i) >= SIZE)
    throw std::out_of_range("Vector index out of range");
  return _array[i];
}


template<typename TYPE, size_t SIZE>
void StaticVector<TYPE, SIZE>::printVector(std::ostream& os) const
{
  os << "Vector :" << "\n[ ";
  for (std::size_t i = 0; i < SIZE; ++i)
    os << _array[i] << " " ;
  os << "]\n";

}

#endif /* STATICVECT_H */
