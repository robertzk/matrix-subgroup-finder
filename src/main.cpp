#include <iostream>
#include <math.h>
#include "general_linear.hpp"

int main(int argc, char** argv) {
  GeneralLinear *identity = new GeneralLinear(4u);
  identity->print("identity");
  GeneralLinear *identity2 = new GeneralLinear(identity);
  identity2->print("identity2");
  (*identity) * (*identity2);
  identity->print("identity");
  (*identity) ^ 2u;
  identity->print("identity");
  identity2->print("identity2");
  GeneralLinear *identity3 = new GeneralLinear(4u, GeneralLinear::identity_matrix(4u));
  identity3->print("identity3");
  identity3->entries[0][0] = mkcomplex(5.0, 0.0);
  ((*identity3) ^ 2u).print("identity3");
  GeneralLinear *b = new GeneralLinear(4u);
  b->entries[0][1] = mkcomplex(0.0, 2.0);
  (*b ^ 2u).print("b ^ 2");
  // http://www.wolframalpha.com/input/?i=%5B%5B1%2C2i%2C3%2C4i%5D%2C%5B5%2C6i%2C7%2C8i%5D%2C%5B9%2C10i%2C11%2C12i%5D%2C%5B13%2C14i%2C15%2C16i%5D%5D+%5E+2
  for (unsigned int i = 0; i < 4; i++) {
    for (unsigned int j = 0; j < 4; j++) {
      unsigned int val = (1 + (i * 4) + j);
      if (val % 2 == 0) {
        b->entries[i][j] = mkcomplex(0.0, (double)val);
      } else {
        b->entries[i][j] = mkcomplex((double)val, 0.0);
      }
    }
  }
  b->print("non trivial example b");
  (*b ^ 2u).print("b ^ 2");

  GeneralLinear *c = new GeneralLinear(4u);
  // http://www.wolframalpha.com/input/?i=%5B%5B1%2C2i%2C3%2C4i%5D%2C%5B5%2C6i%2C7%2C8i%5D%2C%5B9%2C10i%2C11%2C12i%5D%2C%5B13%2C14i%2C15%2C16i%5D%5D+*+%5B%5B5%2C6i%2C7%2C8i%5D%2C%5B9%2C10i%2C11%2C12i%5D%2C%5B13%2C14i%2C15%2C16i%5D%2C+%5B1%2C2i%2C3%2C4i%5D%5D+
  for (unsigned int i = 1; i <= 4; i++) {
    for (unsigned int j = 0; j < 4; j++) {
      unsigned int val = (1 + ((i % 4) * 4) + j);
      if (val % 2 == 0) {
        c->entries[i - 1][j] = mkcomplex(0.0, (double)val);
      } else {
        c->entries[i - 1][j] = mkcomplex((double)val, 0.0);
      }
    }
  }
  b->print("b");
  c->print("c");

  ((*b) * (*c)).print("b * c");

  // w := (-1 + i * 3^(1/2)) / 2;
  Complex w = mkcomplex(-0.5, 0.5 * sqrt(3.0));
  // x := GL4 ! [ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, w, 0, 0, 0, 0, w^2 ];
  GL *x = new GL(4u);
  x->entries[2][2] = w;
  x->entries[3][3] = multcomplex(w, w);
  x->print("x");
  ((*x) * (*x) * (*x)).print("x ^ 3");

  return 0;
}
