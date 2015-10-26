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
  GeneralLinear(const unsigned int _size = 4);

  /**
   * Copy constructor for `GeneralLinear` matrices.
   *
   * @param matrix The template matrix.
   * @return A GeneralLinear matrix that is a copy of `matrix`.
   */
  GeneralLinear(GeneralLinear *matrix);

  /**
   * Construct a matrix from a 2-array of `entries`.
   * 
   * @param _size The size of the square matrix.
   * @param _entries The entries in the matrix, with entries[0][1] representing
   *    the second column of the first row (i.e., column-rowwise).
   * @return A GeneralLinear matrix with coefficients given by `entries`.
   */
  GeneralLinear(const unsigned int _size, Complex **_entries): entries(_entries), size(_size) { };

  /**
   * Clean up the matrix.
   */
  ~GeneralLinear() { };

  /**
   * Print the matrix with each entry separated by two spaces.
   * @param stream An output stream, usually `std::cout`.
   * @param annotation An optional string annotation (name of the matrix).
   */
  void print(std::ostream &stream, char* annotation = NULL) const;

  /**
   * Multiply two matrices.
   */
  friend GeneralLinear operator*(GeneralLinear a, GeneralLinear b);

  /**
   * Raise a matrix to some integer power.
   */
  friend GeneralLinear operator^(GeneralLinear a, unsigned int n);

  /**
   * Create entries for an identity matrix of a given size.
   *
   * @param size The size of the matrix.
   * @return The identity matrix of size `size`.
   */
  static Complex** identity_matrix(unsigned int size);
};


#endif

