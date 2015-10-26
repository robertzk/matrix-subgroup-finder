#include <stdio.h>
#include "general_linear.hpp"

/**
 * Construct an identity matrix.
 */
GeneralLinear::GeneralLinear(unsigned int _size) : size(_size) {
  this->entries = (Complex**)malloc(_size * sizeof(Complex*));

  for (unsigned int i = 0; i < _size; i++) {
    this->entries[i] = (Complex*)malloc(_size * sizeof(Complex));
    for (unsigned int j = 0; j < _size; j++) {
      this->entries[i][j] = (i == j ? mkcomplex(1.0, 0.0) : mkcomplex(0.0, 0.0));
    }
  }
}

