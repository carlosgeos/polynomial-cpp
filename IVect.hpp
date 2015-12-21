#ifndef IVECT_H
#define IVECT_H


#include <cstdlib>
#include <iostream>

// Interface for vectors. All static
template<typename VectType, typename TYPE>
class IVect
{
protected:
  IVect() = default;
  ~IVect() = default;
private:
  const VectType& child() const {return *static_cast<const VectType*>(this);}
  VectType& child() {return *static_cast<VectType*>(this);}
public:
  friend std::ostream& operator<<(std::ostream& os, const VectType& v) {
    v.print(os); return os;}
  friend std::istream& operator>>(std::istream& is, VectType& v) {
    v.extract(is); return is;}
  friend VectType operator+(const VectType& v1, const VectType& v2) {
    return v1.add(v2);}
  friend VectType operator-(const VectType& v1, const VectType& v2) {
    return v1.sub(v2);}
  const TYPE operator[] (std::ptrdiff_t i) const {
    return child().get(i);}
  TYPE& operator[] (std::ptrdiff_t i) {
    return child().get(i);}
  void operator+=(const VectType &other) {
    child().addMe(other);}
  void operator*=(const TYPE &elem) {
    child().mulMe(elem);}
  void operator-=(const VectType &other) {
    child().subMe(other);}
  void operator-() {
    child().minus();}

};

#endif /* IVECT_H */
