#include <iostream>
#include "general_linear.hpp"


int main(int argc, char** argv) {
  // Complex c = mkcomplex(1.05, 1.15);
  // printf("foo %0.2f %0.2f %ld %ld\n", c.re, c.im, 2 * sizeof(double), sizeof(Complex));
  
  GeneralLinear *identity = new GeneralLinear(4);
  identity->print(std::cout);
  return 0;
}
