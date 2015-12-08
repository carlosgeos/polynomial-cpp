#ifndef STATICVECT_H
#define STATICVECT_H

#include "IVect.hpp"

// size_t is used since that is the result type of sizeof expression
// and is preferred for counting in arrays etc.
template<typename TYPE, size_t SIZE>
class StaticVector : public IVect<StaticVector<TYPE, SIZE>, TYPE>
{
  // Array declaration and INITIALIZATION
public:
  TYPE _array[SIZE] = {};
  StaticVector() = default;
  virtual ~StaticVector() = default;
  virtual StaticVector& operator+=(const StaticVector &other) override;
  virtual StaticVector operator+() override;
  virtual StaticVector operator-(const StaticVector &other) override;
  virtual StaticVector operator-() override;
  const TYPE& operator[](std::ptrdiff_t) const override;
  TYPE& operator[](std::ptrdiff_t) override;
  void printVector(std::ostream& os) const override;

};


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator+=(const StaticVector<TYPE, SIZE> &other)
{
  for (size_t i = 0; i < SIZE; i++) _array[i] += other._array[i];
  return *this;
}


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator+()
{
  return *this;
}


template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator-(const StaticVector<TYPE, SIZE> &other)
{
  StaticVector<TYPE, SIZE> final = *this;
  for (size_t i = 0; i < SIZE; i++) {
    final._array[i] = _array[i] - other._array[i];
  }

  return final;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator-()
{
  for (size_t i = 0; i < SIZE; i++) {
    _array[i] = -(_array[i]);
  }

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


template<typename TYPE, size_t SIZE>
void StaticVector<TYPE, SIZE>::printVector(std::ostream& os) const
{
  os << "Vector :" << "\n[ ";
  for (std::size_t i = 0; i < SIZE; ++i)
    os << _array[i] << " " ;
  os << "]\n";

}

#endif /* STATICVECT_H */
