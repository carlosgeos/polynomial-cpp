#ifndef DYNAMICVECT_H
#define DYNAMICVECT_H

#include "IVect.hpp"

// Forward declaration
template<typename TYPE, size_t SIZE>
class StaticVector;


template <typename TYPE>
class DynamicVector : public IVect<DynamicVector<TYPE>, TYPE> {
  std::size_t _size;
  TYPE* _val;
public:
  explicit DynamicVector (std::size_t size = 0): _size(size), _val(new TYPE[size]()) {} // 0-initialized with '()'
  DynamicVector (std::size_t, const TYPE&); // TYPE& elem - initilized
  DynamicVector (const DynamicVector&);
  template<size_t S>  // Conversion from all sorts of static vectors.
  explicit DynamicVector (const StaticVector<TYPE, S>&);
  DynamicVector (DynamicVector&&);
  virtual ~DynamicVector () {delete[] _val;}
  virtual DynamicVector& operator+=(const DynamicVector&) override;
  virtual DynamicVector operator+() override;
  virtual DynamicVector& operator-=(const DynamicVector&) override;
  virtual DynamicVector operator-() override;
  inline const TYPE& operator[] (std::ptrdiff_t) const override;
  inline TYPE& operator[] (std::ptrdiff_t) override;
  std::size_t getSize () const {return _size;}
  DynamicVector& operator= (const DynamicVector&);              // opérateur d'assignation
  DynamicVector& operator= (DynamicVector&&);                   // opérateur de transfert
  virtual void printVector(std::ostream&) const override;

};

template<typename TYPE>
template<size_t S>
DynamicVector<TYPE>::DynamicVector(const StaticVector<TYPE, S>& sv) : _size(S), _val(new TYPE[S])
{
  for (std::size_t i = 0; i < S; ++i) _val[i] = sv[i];
}

template<typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::operator+=(const DynamicVector<TYPE> &other)
{
  for (size_t i = 0; i < _size; ++i) _val[i] += other._val[i];
  return *this;
}

template<typename TYPE>
DynamicVector<TYPE> DynamicVector<TYPE>::operator+()
{
  return *this;
}

template<typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::operator-=(const DynamicVector<TYPE> &other)
{
  return *this;
}


template<typename TYPE>
DynamicVector<TYPE> DynamicVector<TYPE>::operator-()
{
  return *this;
}


template <typename TYPE>
const TYPE& DynamicVector<TYPE>::operator[] (std::ptrdiff_t i) const {
  if (std::size_t(i) >= _size)
    throw std::out_of_range("DynamicVector : Index out of range");
  return _val[i];
}

template <typename TYPE>
TYPE& DynamicVector<TYPE>::operator[] (std::ptrdiff_t i) {
  if (std::size_t(i) >= _size) {
    std::cout << "Increasing size of vector" << "\n";
    DynamicVector<TYPE> tempVect(i + 5, 0);
    for (std::size_t i = 0; i < _size; ++i) tempVect[i] = _val[i];
    *this = tempVect;
    return _val[i];
  }

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

template<typename TYPE>
void DynamicVector<TYPE>::printVector(std::ostream& os) const {
  os << "Vector :" << "\n[ ";
  for (std::size_t i = 0; i < _size; ++i)
    os << _val[i] << ' ';
  os << "]\n";

}

#endif /* DYNAMICVECT_H */
