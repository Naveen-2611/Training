//// ------------------------------------------------------------------------------------------------
//// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
//// Copyright (c) Metamation India.
//// ------------------------------------------------------------------
//// Program.c
//// Naveenkumar s
//// ------------------------------------------------------------------------------------------------
//
//#include <stdio.h>
//#include<math.h>
//
//static void ComplexOperation (Complex c1, Complex c2) {
//   printf (ANSI_COLOR_RESET"First complex no:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (c1);
//   printf (ANSI_COLOR_RESET"Second complex no:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (c2);
//   printf (ANSI_COLOR_RESET"Addition:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (Op_Add (c1, c2));
//   printf (ANSI_COLOR_RESET"Subtraction:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (Op_Sub (c1, c2));
//   printf (ANSI_COLOR_RESET"Multiplication:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (Op_Multi (c1, c2));
//   printf (ANSI_COLOR_RESET"Modulus:"ANSI_COLOR_GREEN"%f\n", Op_Modul (c1));
//   printf (ANSI_COLOR_RESET"Modulus:"ANSI_COLOR_GREEN"%f\n", Op_Modul (c2));
//   printf (ANSI_COLOR_RESET"Conjugate:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (conjugate (c1));
//   printf (ANSI_COLOR_RESET"Conjugate:"ANSI_COLOR_GREEN);
//   PrintComplexNumber (conjugate (c2));
//   printf (ANSI_COLOR_RESET);
//}
//
//static void ComplexTestcase () {
//   printf (ANSI_COLOR_YELLOW"------------------------------------------------------------------"ANSI_COLOR_RESET);
//   printf (ANSI_COLOR_MAGENTA"\n**********TestCase**********\n"ANSI_COLOR_RESET);
//   Complex Number1 = { 10.1f,12.7f }, Number2 = { 15.0f,8.7f };
//   Complex Output1 = Op_Add (Number1, Number2);
//   Complex Output2 = Op_Sub (Number1, Number2);
//   Complex Output3 = Op_Multi (Number1, Number2);
//   double Output4 = Op_Modul (Number1);
//   double Output5 = Op_Modul (Number2);
//   Complex Output6 = conjugate (Number1);
//   Complex Output7 = conjugate (Number2);
//   Complex expOutputAdd = { 25.10f,21.40f }, expOutputSub = { -4.89999962f,4.00f }, expOutputMul = { 41.010002f,278.369995f }, expOutputconj1 = { 10.10f ,-12.70f }, expOutputconj2 = { 15.00f ,-8.70f };
//   double expOutputMod1 = 16.226521124164869, expOutputMod2 = 17.340415290338530;
//   printf (Output1.Imagpart == expOutputAdd.Imagpart && Output1.Realpart == expOutputAdd.Realpart ? "Addition:"ANSI_COLOR_GREEN"Passed\n" ANSI_COLOR_RESET : "Addition:Failed\n");
//   printf (Output2.Imagpart == expOutputSub.Imagpart && Output2.Realpart == expOutputSub.Realpart ? "Subtraction:"ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : "Subtraction:Failed\n");
//   printf (Output3.Imagpart == expOutputMul.Imagpart && Output3.Realpart == expOutputMul.Realpart ? "Multiplication:"ANSI_COLOR_GREEN"passed\n"ANSI_COLOR_RESET : "Multiplication:Failed\n");
//   printf (Output4 == expOutputMod1 && Output5 == expOutputMod2 ? "Modulus:"ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : "Modulus:Failed\n");
//   printf (Output6.Imagpart == expOutputconj1.Imagpart && Output7.Realpart == expOutputconj2.Realpart ? "Conjugate:"ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : "Conjugate:Failed\n");
//}
//
//int main () {
//   ComplexTestcase ();
//   return 0;
//}