#ifndef GENERAL_LINEAR_H
#define GENERAL_LINEAR_H
#include <iostream>
#include "complex.hpp"

/**
 * This class represents a matrix group of size n x n
 * with complex values as coefficients.
 */

// We use un unsigned integer type parameter to represent the dimension:
// http://stackoverflow.com/questions/499106/what-does-template-unsigned-int-n-mean
class GeneralLinear {
public:
  Complex **entries;
  unsigned int size;

  /**
   * Construct an identity matrix.
   *
   * @param _size The size of the square matrix.
   * @return A GeneralLinear matrix with coefficients given by `entries`.
   */
  GeneralLinear(unsigned int _size = 4);

  /**
   * Construct a matrix from a 2-array of `entries`.
   * 
   * @param _size The size of the square matrix.
   * @param _entries The entries in the matrix, with entries[0][1] representing
   *    the second column of the first row (i.e., column-rowwise).
   * @return A GeneralLinear matrix with coefficients given by `entries`.
   */
  GeneralLinear(unsigned int _size, Complex **_entries): entries(_entries), size(_size) { };

  /**
   * Clean up the matrix.
   */
  ~GeneralLinear() { };

  /**
   * Print the matrix with each entry separated by two spaces.
   * @param stream An output stream, usually `std::cout`.
   */
  void print(std::ostream &stream) {
    stream << "Matrix of size " << this->size << " x " << this->size << std::endl;
    for (unsigned int i = 0; i < this->size; i++) {
      for (unsigned int j = 0; j < this->size; j++) {
        stream << strcomplex(this->entries[i][j]) << "  ";
      }
      stream << std::endl;
    }
  }
};

#endif

