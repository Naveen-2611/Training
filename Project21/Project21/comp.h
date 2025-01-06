#pragma once
// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// complex.h
// Function signatures
// Naveenkumar s
// ------------------------------------------------------------------------------------------------

#include<stdbool.h>

typedef struct {
   float RealPart, ImagPart;
}Complex;

/// <summary>Add the two complex numbers</summary>
Complex OpAdd (Complex c1, Complex c2);

/// <summary>Subtract the complex number  </summary>
Complex OpSub (Complex c1, Complex c2);

/// <summary>Multiplies the  two complex numbers</summary>
Complex OpMulti (Complex c1, Complex c2);

/// <summary>Calculates the modulus of a complex number</summary>
double OpModul (Complex c);

/// <summary>Calculatez the conjugate of a complex number</summary>
Complex Conjugate (Complex c);

/// <summary> Functions to compare the two complex numbers</summary>
bool IsEqual (Complex a, Complex b);