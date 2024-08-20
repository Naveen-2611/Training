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

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct LinkedList {
	bool deleted;
	struct Node* head;
}LinkedList;

LinkedList* Create ();
int Add (LinkedList* list, int data);
int Count (LinkedList* list);
int Delete (LinkedList* list);
int Remove (LinkedList* list, int data);
int RemoveAt (LinkedList* list, int index);
int Get (LinkedList* list, int index);
int Insert (LinkedList* list, int data, int index);
Node* CreateNode (int data);