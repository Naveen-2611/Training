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
#include<stdio.h>

Complex Op_Add (Complex c1, Complex c2) {
   Complex output = { 0.0,0.0 };
   output.Realpart = c1.Realpart + c2.Realpart;
   output.Imagpart = c1.Imagpart + c2.Imagpart;
   return output;
}

Complex Op_Sub (Complex c1, Complex c2) {
   Complex output = { 0.0,0.0 };
   output.Realpart = c1.Realpart - c2.Realpart;
   output.Imagpart = c1.Imagpart - c2.Imagpart;
   return output;
}

Complex Op_Multi (Complex c1, Complex c2) {
   Complex output = { 0.0,0.0 };
   output.Realpart = c1.Realpart * c2.Realpart - c1.Imagpart * c2.Imagpart;
   output.Imagpart = c1.Realpart * c2.Imagpart + c1.Imagpart * c2.Realpart;
   return output;
}

double Op_Modul (Complex c) {
   return sqrt (c.Realpart * c.Realpart + c.Imagpart * c.Imagpart);
}

Complex conjugate (Complex c) {
   Complex output = { 0.0,0.0 };
   output.Realpart = c.Realpart;
   output.Imagpart = -c.Imagpart;
   return output;
}

void PrintComplexNumber (Complex c) {
   if (c.Imagpart >= 0) printf ("%f + %fi\n", c.Realpart, c.Imagpart);
   else printf ("%f - %fi\n", c.Realpart, -c.Imagpart);
}