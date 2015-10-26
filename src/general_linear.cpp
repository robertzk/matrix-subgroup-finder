#include <stdio.h>
#include "general_linear.hpp"

/**
 * Construct an identity matrix.
 */
GeneralLinear::GeneralLinear(const unsigned int _size) : size(_size) {
  this->entries = (Complex**)malloc(_size * sizeof(Complex*));

  for (unsigned int i = 0; i < _size; i++) {
    this->entries[i] = (Complex*)malloc(_size * sizeof(Complex));
    for (unsigned int j = 0; j < _size; j++) {
      this->entries[i][j] = (i == j ? mkcomplex(1.0, 0.0) : mkcomplex(0.0, 0.0));
    }
  }
}

/**
 * Copy constructor for `GeneralLinear` matrices.
 *
 * @param matrix The template matrix.
 * @return A GeneralLinear matrix that is a copy of `matrix`.
 */
GeneralLinear::GeneralLinear(GeneralLinear *matrix) {
  unsigned int size = matrix->size;
  this->entries = (Complex**)malloc(size * sizeof(Complex*));

  for (unsigned int i = 0; i < size; i++) {
    this->entries[i] = (Complex*)malloc(size * sizeof(Complex));
    for (unsigned int j = 0; j < size; j++) {
      this->entries[i][j] = matrix->entries[i][j];
    }
  }
  this->size = size;
}

/**
 * Multiply two matrices and store the results in the former matrix.
 */
GeneralLinear operator*(GeneralLinear a, GeneralLinear b) {
  return a;
}

