#ifndef DYNAMICVECT_H
#define DYNAMICVECT_H

#include <cstddef>     // nullptr_t, ptrdiff_t, size_t
#include <iostream>    // cin, cout...
//#include <exception>
//#include <stdexcept>   // standard errors

#include "IVect.hpp"

template <typename TYPE>
class DynamicVector final : IVect {     // final car destructeur non vituel
  template <typename T>
    friend std::ostream& operator<< (std::ostream&, const DynamicVector<T>&);
  std::size_t _size;
  TYPE* _val;
 public:
  std::size_t getSize () const {return _size;}
  explicit DynamicVector(std::size_t size = 0): _size(size), _val(new TYPE[size]) {}
  DynamicVector (std::size_t, const TYPE&);            // constructeur initialisant
  DynamicVector (const DynamicVector&);                         // constructeur de copie
  DynamicVector (DynamicVector&&);                              // constructeur de transfert
  ~DynamicVector () {delete[] _val;}                   // destructeur

  inline const TYPE& operator[] (std::ptrdiff_t) const;
  inline TYPE& operator[] (std::ptrdiff_t);
  DynamicVector& operator= (const DynamicVector&);              // opérateur d'assignation
  DynamicVector& operator= (DynamicVector&&);                   // opérateur de transfert

};

//----------------------------------------------------------------------------

template <typename TYPE>
const TYPE& DynamicVector<TYPE>::operator[] (std::ptrdiff_t i) const {
  if (std::size_t(i) >= _size)
    throw std::out_of_range("DynamicVector : Index out of range");
  return _val[i];
}

template <typename TYPE>
TYPE& DynamicVector<TYPE>::operator[] (std::ptrdiff_t i) {
  if (std::size_t(i) >= _size)
    throw std::out_of_range("DynamicVector : Index out of range");
  return _val[i];
}

//----------------------------------------------------------------------------

template <typename TYPE>
DynamicVector<TYPE>::DynamicVector (std::size_t size, const TYPE& elem):
  _size(size), _val(new TYPE[size]) {
  for (std::size_t i = 0; i < size; ++i) _val[i] = elem;
}

template <typename TYPE>
DynamicVector<TYPE>::DynamicVector (const DynamicVector& v): _size(v._size), _val(new TYPE[v._size]) {
  for (std::size_t i = 0; i < v._size; ++i) _val[i] = v._val[i];
}

template <typename TYPE>
DynamicVector<TYPE>::DynamicVector (DynamicVector&& v): _size(v._size), _val(v._val) {
  v._size = 0; v._val = nullptr;
}

template <typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::operator= (const DynamicVector& v) {
  if (this != &v) {
    delete[] _val; _size = v._size; _val = new TYPE[v._size];
    for (std::size_t i = 0; i < v._size; ++i) _val[i] = v._val[i];
  }
  return *this;
}

template <typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::operator= (DynamicVector&& v) {
  if (this != &v) {
    delete[] _val; _size = v._size; _val = v._val;
    v._size = 0; v._val = nullptr;
  }
  return *this;
}

//----------------------------------------------------------------------------

template <typename TYPE>
std::ostream& operator<< (std::ostream& out, const DynamicVector<TYPE>& v) {
  out << v._size << ": [";
  for (std::size_t i = 0; i < v._size; ++i) out << ' ' << v._val[i];
  out << " ] "<< std::endl;
  return out;
}


#endif /* DYNAMICVECT_H */
