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

// Interface for vectors. All static
template<typename VectType>
class IVect
{
  const VectType& child() const {return *static_cast<const VectType*>(this);}
  VectType& child() {return *static_cast<VectType*>(this);}
  friend std::ostream& operator<<(std::ostream& os, const VectType& v) {
    v.printVector(os);
    return os;
  }
public:
  const auto operator[] (std::ptrdiff_t i) const {
    return child().get(i);}
  auto& operator[] (std::ptrdiff_t i) {
    return child().get(i);}
  void operator+=(const VectType &other) {
    child().addMe(other);}
  void operator-=(const VectType &other) {
    child().subMe(other);}
  void operator-() {
    child().minus();}

  ~IVect() = default;

};



// template<typename VectType, typename TYPE>
// std::ostream& operator<<(std::ostream& os, const VectType& v) {
//   // Only valid for the type we are instantiating.
//   v.printVector(os);
//   return os;
// }

#endif /* IVECT_H */
