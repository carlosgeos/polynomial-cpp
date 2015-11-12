#ifndef POLY_H
#define POLY_H



template<typename TYPE>
class Polynomial
{
  signed int degree;
  DynamicVector<TYPE> coeffs;
public:
  Polynomial();
  // operators...
  virtual ~Polynomial();
};


#endif /* POLY_H */
