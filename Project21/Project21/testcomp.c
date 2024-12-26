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
   Complex num1 = { 10.1f,12.7f }, num2 = { 15.0f,8.7f };
   Complex Output1 = OpAdd (num1, num2);
   Complex Output2 = OpSub (num1, num2);
   Complex Output3 = OpMulti (num1, num2);
   double Output4 = OpModul (num1);
   double Output5 = OpModul (num2);
   Complex Output6 = Conjugate (num1);
   Complex Output7 = Conjugate (num2);
   Complex expOutputAdd = { 25.10f,21.40f }, expOutputSub = { -4.89999962f,4.00f }, expOutputMul = { 41.010002f,278.369995f }, expOutputconj1 = { 10.10f ,-12.70f }, expOutputconj2 = { 15.00f ,-8.70f };
   double expOutputMod1 = 16.226521124164869, expOutputMod2 = 17.340415290338530;
   printf (Output1.Imagpart == expOutputAdd.Imagpart && Output1.Realpart == expOutputAdd.Realpart ? "Addition:"ANSI_COLOR_GREEN"Passed\n" ANSI_COLOR_RESET : "Addition:Failed\n");
   printf (Output2.Imagpart == expOutputSub.Imagpart && Output2.Realpart == expOutputSub.Realpart ? "Subtraction:"ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : "Subtraction:Failed\n");
   printf (Output3.Imagpart == expOutputMul.Imagpart && Output3.Realpart == expOutputMul.Realpart ? "Multiplication:"ANSI_COLOR_GREEN"passed\n"ANSI_COLOR_RESET : "Multiplication:Failed\n");
   printf (Output4 == expOutputMod1 && Output5 == expOutputMod2 ? "Modulus:"ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : "Modulus:Failed\n");
   printf (Output6.Imagpart == expOutputconj1.Imagpart && Output7.Realpart == expOutputconj2.Realpart ? "Conjugate:"ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : "Conjugate:Failed\n");
}

int main () {
   ComplexTestCase ();
   return 0;
}