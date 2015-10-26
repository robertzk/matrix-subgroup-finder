#include <stdlib.h> 
#include <stdio.h>
#include "complex.hpp"

Complex mkcomplex(double re, double im) {
  Complex c;
  c.re = re;
  c.im = im;
  return c;
}

char* strcomplex(Complex c) {
  char* buf = (char*)malloc(30 * sizeof(char));
  snprintf(buf, 30, "%0.10f + %0.10fi", c.re, c.im);
  return buf;
}

