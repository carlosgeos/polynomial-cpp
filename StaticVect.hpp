#ifndef STATICVECT_H
#define STATICVECT_H

#include "IVect.hpp"

// Forward declaration
template <typename TYPE>
class DynamicVector;

// size_t is used since that is the result type of sizeof expression
// and is preferred for counting in arrays etc.
template<typename TYPE, size_t SIZE>
class StaticVector : public IVect<StaticVector<TYPE, SIZE>, TYPE>
{
protected:
  // Array declaration and INITIALIZATION
  TYPE _array[SIZE] = {};
public:
  StaticVector() = default;
  explicit StaticVector (const DynamicVector<TYPE>&); // Conversion ctor
  StaticVector& addMe (const StaticVector&);
  StaticVector add (const StaticVector&) const;
  StaticVector& subMe (const StaticVector&);
  StaticVector sub (const StaticVector&) const;
  StaticVector& mulMe (const TYPE&);
  StaticVector& minus ();
  const TYPE get (std::ptrdiff_t) const;
  TYPE& get(std::ptrdiff_t);
  void print (std::ostream&) const;
  void extract(std::istream&);
  ~StaticVector () = default;
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
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::add(const StaticVector& v2) const
{
  StaticVector<TYPE,SIZE> result = *this;
  result += v2;
  return result;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::subMe(const StaticVector<TYPE, SIZE> &other)
{
  for (size_t i = 0; i < SIZE; i++) _array[i] -= other[i];
  return *this;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE> StaticVector<TYPE, SIZE>::sub(const StaticVector& v2) const
{
  StaticVector<TYPE,SIZE> result = *this;
  result.subMe(v2);
  return result;
}

template<typename TYPE, size_t SIZE>
StaticVector<TYPE, SIZE>& StaticVector<TYPE, SIZE>::mulMe(const TYPE& elem)
{
  for (size_t i = 0; i < SIZE; i++) _array[i] *= elem;
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
void StaticVector<TYPE, SIZE>::print(std::ostream& os) const
{
  os << "Vector :" << "\n[ ";
  for (std::size_t i = 0; i < SIZE; ++i)
    os << _array[i] << " " ;
  os << "]\n";
}

template<typename TYPE, size_t SIZE>
void StaticVector<TYPE, SIZE>::extract(std::istream& is)
{
  // Simple solution... Component by component
  for (size_t i = 0; i < SIZE; ++i) is >> _array[i];
}

#endif /* STATICVECT_H */
