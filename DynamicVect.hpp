#ifndef DYNAMICVECT_H
#define DYNAMICVECT_H

#include "IVect.hpp"

// Forward declaration
template<typename TYPE, size_t SIZE>
class StaticVector;


template <typename TYPE>
class DynamicVector : public IVect<DynamicVector<TYPE>, TYPE> {
 protected:
  std::size_t _size;
  TYPE* _val;
public:
  explicit DynamicVector (size_t size = 0): _size(size), _val(new TYPE[size]()) {} // 0-initialized with '()'
  DynamicVector (size_t, const TYPE&); // TYPE& elem - initilized
  DynamicVector (const DynamicVector&);
  DynamicVector (const TYPE&);
  template<size_t S>  // Conversion from all sorts of static vectors.
  explicit DynamicVector (const StaticVector<TYPE, S>&);
  DynamicVector (DynamicVector&&);
  std::size_t getSize () const {return _size;}
  DynamicVector& addMe(const DynamicVector&);
  DynamicVector add (const DynamicVector&) const;
  DynamicVector& subMe(const DynamicVector&);
  DynamicVector sub (const DynamicVector&) const;
  DynamicVector& mulMe (const TYPE& other);
  DynamicVector& minus();
  const TYPE& get(std::ptrdiff_t) const;
  TYPE& get(std::ptrdiff_t);
  virtual void print(std::ostream&) const;
  virtual ~DynamicVector () {delete[] _val;}
  DynamicVector& operator=(const DynamicVector&);
  DynamicVector& operator=(DynamicVector&&);
};

template<typename TYPE>
template<size_t S>
DynamicVector<TYPE>::DynamicVector(const StaticVector<TYPE, S>& sv) : _size(S), _val(new TYPE[S])
{
  for (std::size_t i = 0; i < S; ++i) _val[i] = sv[i];
}

template<typename TYPE>
DynamicVector<TYPE>::DynamicVector(const TYPE& elem) : _size(1), _val(new TYPE[1])
{
  _val[0] = elem;
}


template<typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::addMe(const DynamicVector<TYPE> &other)
{
  size_t end = other._size;
  if (_size < end) {
    (*this)[end - 1];		// adjusting size
  }
  for (size_t i = 0; i < end; ++i) {
    _val[i] += other[i];
  }
  return *this;
}

template<typename TYPE>
DynamicVector<TYPE> DynamicVector<TYPE>::add(const DynamicVector<TYPE> &other) const
{
  DynamicVector<TYPE> result = *this;
  result += other;
  return result;
}

template<typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::mulMe(const TYPE& elem)
{
  for (size_t i = 0; i < _size; i++) _val[i] *= elem;
  return *this;
}

template<typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::subMe(const DynamicVector<TYPE> &other)
{
  size_t end = other._size;
  if (_size < end) {
    (*this)[end - 1];		// adjusting size
  }
  for (size_t i = 0; i < end; ++i) _val[i] -= other[i];
  return *this;
}

template<typename TYPE>
DynamicVector<TYPE> DynamicVector<TYPE>::sub(const DynamicVector<TYPE> &other) const
{
  DynamicVector<TYPE> result = *this;
  result -= other;
  return result;
}


template<typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::minus()
{
  for (size_t i = 0; i < _size; ++i) _val[i] = -(_val[i]);
  return *this;
}


template <typename TYPE>
const TYPE& DynamicVector<TYPE>::get(std::ptrdiff_t i) const {
  if (std::size_t(i) >= _size)
    throw std::out_of_range("DynamicVector : Index out of range");
  return _val[i];
}

template <typename TYPE>
TYPE& DynamicVector<TYPE>::get(std::ptrdiff_t i) {
  if (std::size_t(i) >= _size) {
    DynamicVector<TYPE> tempVect(i + 1, 0);
    for (std::size_t i = 0; i < _size; ++i) tempVect[i] = _val[i];
    *this = tempVect;
    return _val[i];
  }

  return _val[i];
}

// Ctors

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

// Assignment

template <typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::operator=(const DynamicVector& v) {
  if (this != &v) {
    delete[] _val; _size = v._size; _val = new TYPE[v._size];
    for (std::size_t i = 0; i < v._size; ++i) _val[i] = v[i];
  }
  return *this;
}

template <typename TYPE>
DynamicVector<TYPE>& DynamicVector<TYPE>::operator=(DynamicVector&& v) {
  if (this != &v) {
    delete[] _val; _size = v._size; _val = v._val;
    v._size = 0; v._val = nullptr;
  }
  return *this;
}

template<typename TYPE>
void DynamicVector<TYPE>::print(std::ostream& os) const {
  os << "Vector :" << "\n[ ";
  for (std::size_t i = 0; i < _size; ++i)
    os << _val[i] << ' ';
  os << "]\n";

}

#endif /* DYNAMICVECT_H */
