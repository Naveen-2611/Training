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

/// <summary> To Run the  testcases for various arithmetic operations</summary>
static void ComplexTestCase () {
   printf (ANSI_COLOR_YELLOW"------------------------------------------------------------------"ANSI_COLOR_RESET);
   printf (ANSI_COLOR_MAGENTA"\n**********TestCase**********\n"ANSI_COLOR_RESET);
   Complex A = { 10.1f,12.7f }, B = { 15.0f,8.7f };
   Complex Output1 = OpAdd (A, B);
   Complex Output2 = OpSub (A, B);
   Complex Output3 = OpMulti (A, B);
   double Output4 = OpModul (A);
   double Output5 = OpModul (B);
   Complex Output6 = Conjugate (A);
   Complex Output7 = Conjugate (B);
   Complex expOutputAdd = { 25.10f,21.40f }, expOutputSub = { -4.89999962f,4.00f }, expOutputMul = { 41.010002f,278.369995f }, expOutputconj1 = { 10.10f ,-12.70f }, expOutputconj2 = { 15.00f ,-8.70f };
   double expOutputMod1 = 16.226521124164869, expOutputMod2 = 17.340415290338530;

   if (Output1.ImagPart != expOutputAdd.ImagPart || Output1.RealPart != expOutputAdd.RealPart) {
      printf ("Addition:Failed\n");
      return;
   }
   if (Output2.ImagPart != expOutputSub.ImagPart || Output2.RealPart != expOutputSub.RealPart) {
      printf ("Subtraction:Failed\n");
      return;
   }
   if (Output3.ImagPart != expOutputMul.ImagPart || Output3.RealPart != expOutputMul.RealPart) {
      printf ("Multiplication:Failed\n");
      return;
   }
   if (Output4 != expOutputMod1 || Output5 != expOutputMod2) {
      printf ("Modulus:Failed\n");
      return;
   }
   if (Output6.ImagPart != expOutputconj1.ImagPart || Output7.RealPart != expOutputconj2.RealPart) {
      printf ("Conjugate:Failed\n");
      return;
   }
   printf (ANSI_COLOR_GREEN"Passed"ANSI_COLOR_RESET);
}

int main () {
   ComplexTestCase ();
   return 0;
}