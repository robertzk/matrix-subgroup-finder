#include <stdlib.h> 
#include <stdio.h>
#include "complex.hpp"

#define abs(x) ((x)<0 ? -(x) : (x))

Complex mkcomplex(double re, double im) {
  Complex c;
  c.re = re;
  c.im = im;
  return c;
}

char* strcomplex(Complex c) {
  char* buf = (char*)malloc(30 * sizeof(char));
  if (c.im >= 0) {
    snprintf(buf, 30, "%0.10f + %0.10fi", c.re, c.im);
  } else {
    snprintf(buf, 30, "%0.10f - %0.10fi", c.re, -c.im);
  }
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

bool eqcomplex(Complex a, Complex b) {
  return abs(a.re - b.re) < 0.00000000001 && abs(a.im - b.im) < 0.00000000001;
}


