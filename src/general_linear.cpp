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
void GeneralLinear::print(char* annotation, std::ostream *stream) const {
  (*stream) << "\nMatrix " << (annotation == NULL ? "" : annotation)
            << " (size " << this->size << " x " << this->size << ")" << std::endl;

  for (unsigned int i = 0; i < this->size; i++) {
    for (unsigned int j = 0; j < this->size; j++) {
      (*stream) << strcomplex(this->entries[i][j]) << "  ";
    }
    (*stream) << std::endl;
  }
}

/**
 * Multiply two matrices and store the results in the former matrix.
 */
GeneralLinear operator*(GeneralLinear a, GeneralLinear b) {
  if (a.size != b.size) {
    throw "Matrix sizes must be equal to multiply.";
  }
  unsigned int n = a.size;

  Complex **new_entries = GeneralLinear::identity_matrix(n);

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      Complex new_entry = mkcomplex(0.0, 0.0);
      for (unsigned int k = 0; k < n; k++) {
        addcomplex2(new_entry, multcomplex(a.entries[i][k], b.entries[k][j]));
      }
      new_entries[i][j] = new_entry;
    }
  }

  return GeneralLinear(n, new_entries);
}


/**
 * Raise a matrix to some integer power.
 */
GeneralLinear operator^(GeneralLinear a, unsigned int n) {
  if (n == 0) {
    a.entries = GeneralLinear::identity_matrix(a.size);
    return a;
  } else if (n == 1) {
    return a;
  } else {
    GeneralLinear *a_ = new GeneralLinear(&a);
    for (unsigned int i = 1; i < n; i++, a = a * (*a_));
    return a;
  }
}

/**
 * Test two matrices for entry-wise equality.
 */
bool operator==(GeneralLinear a, GeneralLinear b) {
  if (a.size != b.size) {
    return false;
  }

  for (unsigned int i = 0; i < a.size; i++) {
    for (unsigned int j = 0; j < a.size; j++) {
      if (!eqcomplex(a.entries[i][j], b.entries[i][j])) {
        // std::cout << "Comparing " << strcomplex(a.entries[i][j]) 
        //          << ", " << strcomplex(b.entries[i][j]) << ": "
        //          << (eqcomplex(a.entries[i][j], b.entries[i][j]) ? "true" : "false") << "\n";
        return false;
      }
    }
  }
  return true;
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

