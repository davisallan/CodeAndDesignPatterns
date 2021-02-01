/*
 * Main program file.
 *
 * ENSF 619 2020 Lab 2 Exercise E
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab2exe_E.h"

double read_double_only(void);
/*
 *  Read a double, then skip to the end of a line of input.
 *
 *  REQUIRES
 *     User has been prompted to enter a double.
 *  PROMISES
 *     If user enters bad input, exit is called with an arg of 1.
 *     Otherwise:
 *        Characters following the int are discarded up to
 *        end-of-line or end-of-file, whichever is first.
 *        Return value is the double that was read.
 */

int main(void)
{
  struct cplx w, z;			/* entered by user */
  struct cplx sum;			/* sum of w and z */

  struct cplx subtract, multiply; //structs for storing the results
  struct cplx *ptr, *w_ptr, *z_ptr; //pointers for function calls

  printf("This programs needs values for complex numbers w and z.\n");

  printf("  Please enter the real part of w     : ");
  w.real = read_double_only();
  printf("  Please enter the imaginary part of w: ");
  w.imag = read_double_only();

  printf("  Please enter the real part of z     : ");
  z.real = read_double_only();
  printf("  Please enter the imaginary part of z: ");
  z.imag = read_double_only();

  printf("\nw is (%f) + j(%f)\n", w.real, w.imag);
  printf("z is (%f) + j(%f)\n", z.real, z.imag);

  sum = cplx_add(w, z);

  printf("\nsum is (%f) + j(%f)\n", sum.real, sum.imag);

  ptr = &subtract;
  cplx_subtract(w, z, ptr);
  
  printf("\nsubtraction is (%f) + j(%f)\n", subtract.real, subtract.imag);

  ptr = &multiply;
  w_ptr = &w;
  z_ptr = &z;
  cplx_multiply(w_ptr, z_ptr, ptr);

  printf("\nmultiplication is (%f) + (%f)\n", multiply.real, multiply.imag);

  return 0;
}


double read_double_only(void)
{
  double value_read;
  int char_code;
 
  if (scanf("%lf", &value_read) != 1) {
    printf("Error trying to read in a double.  Program terminated.\n");
    exit(1);
  }
 
  char_code = getchar();
  while (char_code != '\n' && char_code != EOF)
    char_code = getchar();
 
  return value_read;
}
