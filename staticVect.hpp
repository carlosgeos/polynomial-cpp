#ifndef STATICVECT_H
#define STATICVECT_H

//#include <cstdlib>
//#include <iostream>

#include "IVect.hpp"

// size_t is used since that is the result type of sizeof expression
// and is preferred for counting in arrays etc.
template<typename TYPE, size_t SIZE>
class StaticVector : public IVect<StaticVector<TYPE, SIZE>, TYPE>
// CRTP - Curiously Recurring Template Pattern
{
  // Array declaration and INITIALIZATION
  TYPE _array[SIZE] = {};
public:
  //friend std::ostream& operator<<(std::ostream&, const StaticVector<TYPE, SIZE>&);
  StaticVector() = default;
  virtual ~StaticVector() = default;
  virtual StaticVector operator+(const StaticVector &other) override;
  virtual StaticVector operator-(const StaticVector &other) override;
  virtual StaticVector operator-() override;
  const TYPE& operator[](std::ptrdiff_t) const override;
  TYPE& operator[](std::ptrdiff_t) override;
  void printVector(std::ostream& os) const override;

};

template<typename TYPE, size_t SIZE>
void StaticVector<TYPE, SIZE>::printVector(std::ostream& os) const {
  os << "Vector :" << "\n[ ";
  // i --> 0 to be read as ((i--) > 0)
  for (std::size_t i = SIZE; i --> 0;) {
    os << this -> _array[i] << " " ;
  }
  os << "]\n";

}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator+(const StaticVector<TYPE, SIZE> &other)
{
  StaticVector<TYPE, SIZE> final;
  for (size_t i = 0; i < SIZE; i++) {
    final._array[i] = this -> _array[i] + other._array[i];
  }

  return final;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator-(const StaticVector<TYPE, SIZE> &other)
{
  StaticVector<TYPE, SIZE> final;
  for (size_t i = 0; i < SIZE; i++) {
    final._array[i] = this -> _array[i] - other._array[i];
  }

  return final;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::operator-()
{
  StaticVector<TYPE, SIZE> final;
  for (size_t i = 0; i < SIZE; i++) {
    final._array[i] = -(this -> _array[i]);
  }

  return final;
}


template <typename TYPE, std::size_t SIZE>
const TYPE& StaticVector<TYPE, SIZE>::operator[] (std::ptrdiff_t i) const {
  if (std::size_t(i) >= SIZE)
    throw std::out_of_range("Vector index out of range");
  return _array[i];
}

template <typename TYPE, std::size_t SIZE>
TYPE& StaticVector<TYPE, SIZE>::operator[] (std::ptrdiff_t i) {
  if (std::size_t(i) >= SIZE)
    throw std::out_of_range("Vector index out of range");
  return _array[i];
}

// template<typename TYPE, size_t SIZE>
// StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator=(const StaticVector<TYPE, SIZE> &rhs)
// {
//   // Check for self-assignment!
//   if (this == &rhs)
//     return *this;
//   for (size_t i = 0; i < SIZE; i++) {
//     std::cout << "esaaa" << "\n";
//     this -> _array[i] = rhs._array[i];
//   }

//   return *this;
// }

#endif /* STATICVECT_H */
