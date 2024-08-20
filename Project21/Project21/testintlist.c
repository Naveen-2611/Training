// ------------------------------------------------------------------------------------------------
// Assignment2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Testcases for the implementation of functions in Linked list
// ------------------------------------------------------------------------------------------------
#include<stdio.h>
#include "intlist.h"

int main () {

	//Testcases for LinkedList
	//case1: Create the Linked List, add 3 values and print count
	printf ("\nCase 1:\n");
	LinkedList* headPtr = Create ();
	Add (headPtr, 11);
	Add (headPtr, 12);
	Add (headPtr, 13);
	printf ("Expected: 3\n");
	printf ("Output: %d\n", Count (headPtr));
	Delete (headPtr);

	//case2: Create the Linked List, add values,get count and remove values based on index
	printf ("\nCase 2:\n");
	LinkedList* headPtr1 = Create ();
	Add (headPtr1, 10);
	Add (headPtr1, 20);
	Add (headPtr1, 30);
	printf ("Expected: 0\n");
	int length = Count (headPtr1);
	for (int i = 0; i < length; i++) {
		RemoveAt (headPtr1, 0);
	}
	printf ("Output: %d\n", Count (headPtr1));
	Delete (headPtr1);

	//case3: Create the Linked List, delete list 2 times
	printf ("\nCase 3:\n");
	LinkedList* headPtr2 = Create ();
	int n = Delete (headPtr2);
	printf ("Expected: 0\n");
	printf ("Output1: ");
	printf ("%d\n", n);
	printf ("Expected: -3\n");
	int m = Delete (headPtr2);
	printf ("Output2: ");
	printf ("%d\n", m);

	//case4: create the Linked List, delete list and try to insert, add values to list
	printf ("\nCase 4:\n");
	LinkedList* headPtr3 = Create ();
	Delete (headPtr3);
	printf ("Expected: -3\n");
	int j = Add (headPtr3, 20);
	printf ("Output1: ");
	printf ("%d\n", j);
	printf ("Expected: -3\n");
	int k = Insert (headPtr3, 20, 0);
	printf ("Output2: ");
	printf ("%d\n", k);


	//case5: create the Linked List, add values and remove values based on value itself
	printf ("\nCase 5:\n");
	LinkedList* headPtr4 = Create ();
	Add (headPtr4, 11);
	Add (headPtr4, 12);
	Add (headPtr4, 13);
	Remove (headPtr4, 12);
	printf ("Expected: 2\n");
	printf ("Output: %d\n", Count (headPtr4));
	Delete (headPtr4);

	//case6: create the Linked List and insert values based on index
	printf ("\nCase 6:\n");
	LinkedList* headPtr5 = Create ();
	for (int i = 0; i < 5; i++) {
		Insert (headPtr5, i, 0);
	}
	printf ("Expected: 5\n");
	printf ("Output: %d\n", Count (headPtr5));
	Delete (headPtr5);

	//case7: create the Linked List and get values based on index
	printf ("\nCase 7:\n");
	LinkedList* headPtr6 = Create ();
	Add (headPtr6, 10);
	Add (headPtr6, 20);
	Add (headPtr6, 30);
	printf ("Expected: 20\n");
	int a = Get (headPtr6, 1);
	printf ("Output: %d\n", a);
	Delete (headPtr6);


	//case8: create an empty Linked List and try to get values based on index
	printf ("\nCase 8:\n");
	LinkedList* headPtr7 = Create ();
	printf ("Expected: -2\n");
	int b = Get (headPtr7, 1);
	printf ("Output: %d\n", b);
	Delete (headPtr7);


	//case9: create a Linked List and try to get values exceeding index range
	printf ("\nCase 9:\n");
	LinkedList* headPtr8 = Create ();
	Add (headPtr8, 11);
	Add (headPtr8, 12);
	Add (headPtr8, 13);
	printf ("Expected: -1\n");
	int c = Get (headPtr8, 3);
	printf ("Output: %d\n", c);
	Delete (headPtr8);

	//case10: create a Linked List, add same values and remove the first occurence
	printf ("\nCase 10:\n");
	LinkedList* headPtr9 = Create ();
	Add (headPtr9, 11);
	Add (headPtr9, 11);
	Add (headPtr9, 11);
	printf ("Expected: 2\n");
	Remove (headPtr9, 11);
	printf ("Output: %d\n", Count (headPtr9));
	Delete (headPtr9);

	//case11: create a Linked List and try giving negative values as index
	printf ("\nCase 11:\n");
	LinkedList* headPtr10 = Create ();
	Add (headPtr10, 11);
	Add (headPtr10, 11);
	Add (headPtr10, 11);
	printf ("Expected: -1\n");
	int d = Insert (headPtr10, 10, -2);
	printf ("Output: %d\n", d);
	Delete (headPtr10);

}