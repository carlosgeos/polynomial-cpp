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

template<typename VectType, typename ElemType>
class IVect
{
  friend std::ostream& operator<<(std::ostream& os, const VectType& v) {
    v.printVector(os);
    return os;
  }
  virtual void printVector(std::ostream& os) const =0;
public:
  virtual const ElemType& operator[] (std::ptrdiff_t) const = 0;
  virtual ElemType& operator[] (std::ptrdiff_t) = 0;
  virtual VectType operator+(const VectType &other) = 0;
  virtual VectType operator+() = 0;
  virtual VectType operator-(const VectType &other) = 0;
  virtual VectType operator-() = 0;
  virtual ~IVect() = default;

};

// template<typename VectType, typename ElemType>
// std::ostream& operator<<(std::ostream& os, const VectType& v) {
//   // Only valid for the type we are instantiating.
//   v.printVector(os);
//   return os;
// }

#endif /* IVECT_H */
