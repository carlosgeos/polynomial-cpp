#ifndef IVECT_H
#define IVECT_H


#include <cstdlib>
#include <iostream>

// Superscripts for polynomial expressions. Works if encoding UTF-8
char const *super[] = {"\u2070", "\u00B9",
		       "\u00B2", "\u00B3",
		       "\u2074", "\u2075",
		       "\u2076", "\u2077",
		       "\u2078", "\u2079"};


template<typename TYPE, size_t SIZE>
class IVect
{
public:
  virtual ~IVect() = default;

  template<typename T, size_t dim>
  friend std::ostream& operator<< (std::ostream&, const IVect<T, dim>&);
  template<typename T, size_t dim>
  friend std::istream& operator>>(std::istream&, const IVect<T, dim>&);

  virtual const TYPE& operator[] (std::ptrdiff_t) const = 0;
  virtual TYPE& operator[] (std::ptrdiff_t) = 0;
  //virtual IVect<TYPE>& operator+=(const IVect &) = 0;
  //virtual IVect<TYPE, SIZE>& operator+=(const IVect<TYPE, SIZE> &) = 0;
  //  virtual IVect<TYPE, SIZE> operator+(const IVect<TYPE, SIZE>&);
  //virtual IVect<TYPE, SIZE> operator=(const IVect<TYPE, SIZE>&);
};

// template <typename TYPE>
// const TYPE& IVect<TYPE>::operator[] (std::ptrdiff_t i) const {
//   if (std::size_t(i) >= _size)
//     throw std::out_of_range("DynamicVector : Index out of range");
//   return _val[i];
// }

// template <typename TYPE>
// TYPE& IVect<TYPE>::operator[] (std::ptrdiff_t i) {
//   if (std::size_t(i) >= _size)
//     throw std::out_of_range("DynamicVector : Index out of range");
//   return _val[i];
// }


// template<typename TYPE, size_t SIZE = 0>
// std::ostream& operator<< (std::ostream& out, const IVect<TYPE, SIZE>& v) {
//   out << "Vector :" << "\n[ ";
//   // i --> 0 to be read as ((i--) > 0)

//   for (std::size_t i = SIZE; i --> 0;) {
//     out << v._array[i] << " " ;
//   }
//   out << "]\n";
//   return out;
// }

#endif /* IVECT_H */
