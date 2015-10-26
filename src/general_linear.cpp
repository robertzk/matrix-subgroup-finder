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
 * Print the matrix with each entry separated by two spaces.
 * @param stream An output stream, usually `std::cout`.
 * @param annotation An optional string annotation (name of the matrix).
 */
void GeneralLinear::print(std::ostream &stream, char* annotation) const {
  stream << "Matrix " << (annotation == NULL ? "" : annotation)
         << " (size " << this->size << " x " << this->size << ")\n" << std::endl;

  for (unsigned int i = 0; i < this->size; i++) {
    for (unsigned int j = 0; j < this->size; j++) {
      stream << strcomplex(this->entries[i][j]) << "  ";
    }
    stream << std::endl;
  }
}

/**
 * Multiply two matrices and store the results in the former matrix.
 */
GeneralLinear operator*(GeneralLinear a, GeneralLinear b) {
  if (a.size != b.size) {
    throw "Matrix sizes must be equal to multiply.";
  }

  Complex **new_entries = GeneralLinear::identity_matrix(a.size);
  a.entries[0][0] = mkcomplex(0.0, 0.0);
  return a;
}


/**
 * Raise a matrix to some integer power.
 */
GeneralLinear operator^(GeneralLinear a, unsigned int n) {
  if (n == 0) {
    a.entries = GeneralLinear::identity_matrix(a.size);
    return a;
  }

  a.entries[0][0] = mkcomplex(0.0, (double)n);
  return a;
}

/**
 * Create entries for an identity matrix of a given size.
 *
 * @param size The size of the matrix.
 * @return The identity matrix of size `size`.
 */
Complex** GeneralLinear::identity_matrix(unsigned int size) {
  Complex **entries = (Complex**)malloc(size * sizeof(Complex*));

  for (unsigned int i = 0; i < size; i++) {
    entries[i] = (Complex*)malloc(size * sizeof(Complex));
    for (unsigned int j = 0; j < size; j++) {
      entries[i][j] = (i == j ? mkcomplex(1.0, 0.0) : mkcomplex(0.0, 0.0));
    }
  }

  return entries;
}

