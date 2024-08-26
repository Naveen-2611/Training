// ------------------------------------------------------------------------------------------------
// Assignment 2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.h
// c file for creating a linked list
// ------------------------------------------------------------------------------------------------
#pragma once
#include <stdbool.h>

#define E_INDEX_OUT_OF_RANGE  -1
#define E_EMPTY_LIST -2
#define E_LIST_DOES_NOT_EXIST -3
#define E_VALUE_NOT_FOUND -4
#define E_LIST_NOT_FOUND -5
#define E_NODE_NOT_FOUND -6

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct LinkedList {
	bool deleted;
	int count;
	struct Node* head;
}LinkedList;

/// <summary> Creates an empty linked list</summary>
LinkedList* Create ();
/// <summary>Creates a node </summary>
Node* CreateNode (int data);
/// <summary>Adds element to the end of the list</summary>
int Add (LinkedList* list, int data);
/// <summary>Return the number of elements in list</summary>
int Count (LinkedList* list);
/// <summary>Delete the entire list</summary>
int Delete (LinkedList* list);
/// <summary>Removes the first occurrence of specified value in list</summary>
int Remove (LinkedList* list, int data);
/// <summary>Removes the value at a specified index</summary>
int RemoveAt (LinkedList* list, int index);
/// <summary>Stores the value at a specified index if such an index exists in a pointer</summary>
int Get (LinkedList* list, int index,int* data);
/// <summary>Inserts the value at a specified index</summary>
int Insert (LinkedList* list, int data, int index);