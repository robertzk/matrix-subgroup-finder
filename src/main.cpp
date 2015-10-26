#include <iostream>
#include "general_linear.hpp"


int main(int argc, char** argv) {
  GeneralLinear *identity = new GeneralLinear(4);
  identity->print(std::cout);
  GeneralLinear *identity2 = new GeneralLinear(identity);
  identity2->print(std::cout);
  (*identity) * (*identity2);
  identity->print(std::cout);
  (*identity) ^ 2;
  identity->print(std::cout);
  identity2->print(std::cout);
  return 0;
}
