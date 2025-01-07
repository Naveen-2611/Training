// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// complex.c
// Functions performing on the complex numbers
// Naveenkumar s
// ------------------------------------------------------------------------------------------------

#include"comp.h"
#include<math.h>
#include<stdbool.h>

#define EPSILON 1e-9

Complex OpAdd (Complex c1, Complex c2) {
   Complex output = { c1.RealPart + c2.RealPart, c1.ImagPart + c2.ImagPart };
   return output;
}

Complex OpSub (Complex c1, Complex c2) {
   Complex output = { c1.RealPart - c2.RealPart, c1.ImagPart - c2.ImagPart };
   return output;
}

Complex OpMulti (Complex c1, Complex c2) {
   Complex output = { c1.RealPart * c2.RealPart - c1.ImagPart * c2.ImagPart, c1.RealPart * c2.ImagPart + c1.ImagPart * c2.RealPart };
   return output;
}

double OpModul (Complex c) {
   return sqrt (c.RealPart * c.RealPart + c.ImagPart * c.ImagPart);
}

Complex Conjugate (Complex c) {
   Complex output = { c.RealPart, -c.ImagPart };
   return output;
}

bool IsEqual (Complex a, Complex b) {
   return (fabs (a.ImagPart - b.ImagPart) < EPSILON) && (fabs (a.RealPart - b.RealPart) < EPSILON);
}