// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testcomplex.c
// performing operations on complex numbers
// Naveenkumar s
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include"comp.h"

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void PrintComplexNumber (Complex c) {
   if (c.ImagPart >= 0) printf ("%f + %fi\n", c.RealPart, c.ImagPart);
   else printf ("%f - %fi\n", c.RealPart, -c.ImagPart);
}

/// <summary> To Run the  testcases for various arithmetic operations</summary>
static void ComplexTestCase () {
   printf (ANSI_COLOR_YELLOW"------------------------------------------------------------------"ANSI_COLOR_RESET);
   printf (ANSI_COLOR_MAGENTA"\n**********TestCase**********\n"ANSI_COLOR_RESET);
   Complex num1[] = { {10.1f,12.7f },{15.0f,8.7f},{20,30},{-5,760},{-5,80} ,{75,30} };
   Complex expOutputAdd[] = { { 25,21 },{15 , 790},{70 , 110} },
      expOutputSub[] = { { -4.89999962f,4 } ,{25 ,-730 },{-80 , 50} },
      expOutputMul[] = { { 41.0100021f , 278.369995f },{-22900 , 15050}, { -2775, 5850 } },
      expOutputconj1[] = { { 10.1000004f, -12.6999998f },{20, -30},{-5, -80} };
   double expOutputMod1[] = { 16.226521124164869 ,36.055512754639892,80.156097709406993 };
   int j = 0;
   for (int i = 0; i < 5; i += 2) {
      Complex add = OpAdd (num1[i], num1[i + 1]);
      Complex sub = OpSub (num1[i], num1[i + 1]);
      Complex multi = OpMulti (num1[i], num1[i + 1]);
      double mod1 = OpModul (num1[i]);
      Complex con1 = Conjugate (num1[i]);
      if (!IsEqual (add, expOutputAdd[j])) {
         printf ("Addition:Failed\n");
         return;
      }
      if (!IsEqual (sub, expOutputSub[j])) {
         printf ("Subtraction:Failed\n");
         return;
      }
      if (!IsEqual (multi, expOutputMul[j])) {
         printf ("Multiplication:Failed\n");
         return;
      }
      if (mod1 != expOutputMod1[j]) {
         printf ("Modulus:Failed\n");
         return;
      }
      if (con1.ImagPart != expOutputconj1[j].ImagPart) {
         printf ("Conjugate:Failed\n");
         return;
      }
      j++;
   }
   printf (ANSI_COLOR_GREEN"Passed"ANSI_COLOR_RESET);
}

int main () {
   ComplexTestCase ();
   return 0;
}