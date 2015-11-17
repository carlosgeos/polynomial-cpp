#ifndef STATICVECT_H
#define STATICVECT_H

//#include <cstdlib>
//#include <iostream>

#include "IVect.hpp"


// size_t is used since that is the result type of sizeof expression
// and is preferred for counting in arrays etc.
template<typename TYPE, size_t SIZE>
class StaticVector : virtual public IVect
{
  // Array declaration and INITIALIZATION
  TYPE _array[SIZE] = {};
public:
  StaticVector() = default;
  virtual ~StaticVector() = default;

  virtual void printVect(std::ostream& os) const override {
    // This function should not change anything in the object,
    // therefore const.
    os << "Vector :" << "\n[ ";
    // i --> 0 to be read as ((i--) > 0)
    for (std::size_t i = SIZE; i --> 0;) {
      os << this -> _array[i] << " " ;
    }
    os << "]\n";
  };

  virtual IVect& operator+(const IVect &other) override {
    StaticVector<TYPE, SIZE> result = *this;

    for (size_t i = 0; i < SIZE; i++) {
      this -> _array[i] += other.getArray(i);
    }

    return result;
  }
  inline const TYPE& operator[] (std::ptrdiff_t) const;
  inline TYPE& operator[] (std::ptrdiff_t);
  //inline IVect<TYPE, SIZE>& operator+=(const StaticVector<TYPE, SIZE>&);
  inline StaticVector <TYPE, SIZE>& operator=(const StaticVector<TYPE, SIZE>&);

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
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator=(const StaticVector<TYPE, SIZE> &rhs)
{
  // Check for self-assignment!
  if (this == &rhs)
    return *this;
  for (size_t i = 0; i < SIZE; i++) {
    std::cout << "esaaa" << "\n";
    this -> _array[i] = rhs._array[i];
  }

  return *this;
}

// template<typename TYPE, size_t SIZE>
// IVect<TYPE, SIZE>& StaticVector<TYPE, SIZE>::operator+=(const StaticVector<TYPE, SIZE> &other)
// {
//   for (size_t i = 0; i < SIZE; i++) {
//     this -> _array[i] += other._array[i];
//   }

//   return *this;
// }

//-------------------



#endif /* STATICVECT_H */
