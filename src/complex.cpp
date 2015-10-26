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

Complex addcomplex(Complex a, Complex b) {
  return mkcomplex(a.re + b.re, a.im + b.im);
}

void addcomplex2(Complex &a, Complex b) {
  a.re = a.re + b.re;
  a.im = a.im + b.im;
}

Complex multcomplex(Complex a, Complex b) {
  return mkcomplex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}


