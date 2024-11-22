// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<string.h>
struct operation {
   int add;
   int sub;
   int multiply;
   int modulus;
};

int main () {
   struct operation operation1;
   operation1.add = 10 + 10;
   operation1.sub = 20 - 10;
   operation1.multiply = 10 * 10;
   operation1.modulus = 20 % 5;

   printf ("addition:%d\n", operation1.add);
   printf ("subraction:%d\n", operation1.sub);
   printf ("multiply:%d\n", operation1.multiply);
   printf ("modulus:%d\n", operation1.modulus);
   return 0;
}