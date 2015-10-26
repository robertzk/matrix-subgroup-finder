#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex {
  double re;
  double im;
};

Complex mkcomplex(double re, double im);
char* strcomplex(Complex c);
Complex addcomplex(Complex a, Complex b);
void addcomplex2(Complex &a, Complex b);
Complex multcomplex(Complex a, Complex b);

#endif

