#include <iostream>
#include "general_linear.hpp"


int main(int argc, char** argv) {
  GeneralLinear *identity = new GeneralLinear(4u);
  identity->print(std::cout, "identity");
  GeneralLinear *identity2 = new GeneralLinear(identity);
  identity2->print(std::cout, "identity2");
  (*identity) * (*identity2);
  identity->print(std::cout, "identity");
  (*identity) ^ 2u;
  identity->print(std::cout, "identity");
  identity2->print(std::cout, "identity2");
  GeneralLinear *identity3 = new GeneralLinear(4u, GeneralLinear::identity_matrix(4u));
  identity3->print(std::cout, "identity3");
  identity3->entries[0][0] = mkcomplex(5.0, 0.0);
  ((*identity3) ^ 2u).print(std::cout, "identity3");
  //identity3 ^ 0u;
  //identity3->print(std::cout, "identity3");
  return 0;
}
