#pragma once
// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// complex.h
// Function signatures
// Naveenkumar s
// ------------------------------------------------------------------------------------------------

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
   float Realpart, Imagpart;
}Complex;

/// <summary>Add the two complex numbers</summary>
Complex Op_Add (Complex c1, Complex c2);

/// <summary>Subtract the complex number  </summary>
Complex Op_Sub (Complex c1, Complex c2);

/// <summary>Multiplies the  two complex numbers</summary>
Complex Op_Multi (Complex c1, Complex c2);

/// <summary>Calculates the modulus of a complex number</summary>
double Op_Modul (Complex c);

/// <summary>Calculatez the conjugate of a complex number</summary>
Complex conjugate (Complex c);

/// <summary> To print the complex numbers</summary>
void PrintComplexNumber (Complex c);