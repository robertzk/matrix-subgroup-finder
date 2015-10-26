#include "complex.hpp"
#include <iostream>

Complex mkcomplex(double re, double im) {
  Complex c;
  c.re = re;
  c.im = im;
  return c;
}

int main(int argc, char** argv) {
  Complex c = mkcomplex(1.05, 1.15);
  printf("foo %0.2f %0.2f\n", c.re, c.im);
  return 0;
}

