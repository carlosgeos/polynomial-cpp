#ifndef STATICVECT_H
#define STATICVECT_H

//#include <cstdlib>
//#include <iostream>

#include "IVect.hpp"


// size_t is used since that is the result type of sizeof expression
// and is preferred for counting in arrays etc.
template<typename TYPE, size_t SIZE>
class StaticVector : virtual public IVect<TYPE, SIZE>
{
  // Array declaration and INITIALIZATION. Otherwise random values
  // appear.
  TYPE _array[SIZE] = {};
public:
  StaticVector() = default;
  virtual ~StaticVector() = default;

  template<typename T, size_t dim>
  friend std::ostream& operator<< (std::ostream&, const StaticVector<T, dim>&);
  inline const TYPE& operator[] (std::ptrdiff_t) const override;
  inline TYPE& operator[] (std::ptrdiff_t) override;
  inline IVect<TYPE, SIZE>& operator+=(const StaticVector<TYPE, SIZE>&);

  StaticVector<TYPE, SIZE>& operator=(const StaticVector<TYPE, SIZE> &rhs)
  {
    // Check for self-assignment!
    if (this == &rhs)
      return *this;

    return *this;
  }


};

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

template<typename TYPE, size_t SIZE>
IVect<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator+=(const StaticVector<TYPE, SIZE> &other)
{
  for (size_t i = 0; i < SIZE; i++) {
    this -> _array[i] += other._array[i];
  }

  return *this;
}

//-------------------

template<typename TYPE, size_t SIZE>
std::ostream& operator<< (std::ostream& out, const StaticVector<TYPE, SIZE>& v) {
  out << "Vector :" << "\n[ ";
  // i --> 0 to be read as ((i--) > 0)
  for (std::size_t i = SIZE; i --> 0;) {
    out << v._array[i] << " " ;
  }
  out << "]\n";
  return out;
}


#endif /* STATICVECT_H */
