#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

// Define states of the Mealy machine
typedef enum {
   Q0,  // Initial state
   Q1,  // After '0'
   Q2,  // After '01'
   Q3,  // After '011'
   P3,
   P2,
   P1
} State;

void Mealy (char inpPath[], char outPath[]);
State NextMealyState (State currentState, int input, int* output);

void main (int argc, char* argv[]) {
   char inpFilePath[MAX_PATH], outFilePath[MAX_PATH];
   strcpy (inpFilePath, argv[1]);
   strcpy (outFilePath, argv[2]);
   Mealy (inpFilePath, outFilePath);
}

// Function to open input file and create a new file and store the result
void Mealy (char inpPath[], char outPath[]) {
   char ch;
   FILE* inpTestFile = fopen (inpPath, "r"),
      * outTestFile = fopen (outPath, "w");
   if (!inpTestFile || !outTestFile) {
      printf ("Error opening file");
      return;
   }
   State currentState = Q0;
   int output = 0;
   while ((ch = fgetc (inpTestFile)) != EOF) {
      currentState = NextMealyState (currentState, ch - '0', &output);
      fprintf (outTestFile, "%d", output);
   }
   fclose (inpTestFile);
   fclose (outTestFile);
}

// Function to get the next state and output based on the current state and input
State NextMealyState (State currentState, int input, int* output) {
   *output = 0;
   switch (currentState) {
   case Q0:
      // Transition to S1 after '0'
      // Stay in S0 if input is '1'
      return input == 0 ? Q1 :P3;
   case Q1:
      // Transition to S2 after '01'
      // Stay in S1 if input is '0'
      return input == 1 ?  Q2 :Q1;
   case Q2:
      return input == 1 ?  Q3 :Q1;
      // Output '1' upon seeing '011'    
      // Move to S3 after recognizing '011'
      // Return to S1 if input is '0'
   case Q3:
      // Reset to S0 after recognizing '011'
      // Return to S1 if input is '0'
      if (input == 0) {
         *output = 1;
         return P1;
      }
      return P2;
   case P3:
      return input == 1 ? P2 :Q1;
   case P2:
      return input == 0 ? P1 :P2;
   case P1:
      if (input == 1) {
         *output = 1;
         return Q2;
      }
      return Q1;
   default:
      // Default return to initial state
      return Q0;
   }
}