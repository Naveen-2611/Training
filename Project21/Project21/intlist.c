// ------------------------------------------------------------------------------------------------
// Assignment 2 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// c file for creating a linked list
// ------------------------------------------------------------------------------------------------
#include"intlist.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <malloc.h>

bool deleted;// Boolean varaible to keep track of deleted list 

/// <summary>Creates a new LinkedList to hold integers</summary>
/// <returns>pointer to linked list</returns>
LinkedList* Create () {
   LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList));
   if (list != NULL) {
      list->head = NULL;
      list->deleted = false;
   }
   return list;
}

Node* CreateNode (int data) { //creates a new node with specified value
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode != NULL) {
      newNode->data = data;
      newNode->next = NULL;
   }
   return newNode;
}

/// <summary>Adds element to the end of the list</summary>
/// <param name="data"></param>
/// <returns>Error code (if any)</returns>
int Add (LinkedList* list, int data) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //checks if the list is empty
   Node* newNode = CreateNode (data);
   if (list->head == NULL) {
      list->head = newNode;
      return 0;
   }
   // if the list is not empty, it iterates to the desired position
   Node* current = list->head;
   while (current->next != NULL)
      current = current->next;

   current->next = newNode;
   return 0;
}



/// <summary>Return the number of elements in list</summary>
/// <param name="head"></param>
/// <returns>Error code (if any)</returns>
int Count (LinkedList* list) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //if the list is not deleted, it iterates to get count
   int count = 0;
   Node* current = list->head;
   while (current != NULL) {
      count++;/// Increment count by 1
      current = current->next;
   }
   return count;///Return the count of nodes
}


/// <summary>Delete the entire list</summary>
/// <param name="head"></param>
/// <returns>Error code (if any)</returns>
int Delete (LinkedList* list) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //Checks if the list is empty and deletes list
   Node* current = list->head;
   Node* next = NULL;
   if (current == NULL) {
      list->deleted = true;
      return 0;
   }
   //if the list is not empty, it iterates to the end and deletes all nodes
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
   list->head = NULL;
   list->deleted = true;
   return 0;
}

/// <summary>Removes the first occurrence of specified value in list</summary>
/// <param name="head"></param>
/// <param name="data"></param>
/// <returns>Error code (if any)</returns>
int Remove (LinkedList* list, int data) {
   // checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //Checks if the list is empty
   Node* temp = list->head;
   Node* pre = NULL;
   if (temp == NULL) return E_EMPTY_LIST;
   //Check if the data in head(1st node) is to be removed
   if (temp != NULL && temp->data == data) {
      list->head = temp->next;
      free (temp);
      return 0;
   }
   //if the list is not empty, it iterates to remove the data at spec.index
   while (temp != NULL && temp->data != data) {//if the list is not empty, it iterates to remove the data at spec. index
      pre = temp;
      temp = temp->next;
   }
   //checks if index exceeds list count
   if (temp != NULL) {
      pre->next = temp->next;
      free (temp);
      return 0;
   }
   else {
      return E_VALUE_NOT_FOUND;
   }
}
/// <summary>Removes the value at a specified index</summary>
/// <param name="head"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int RemoveAt (LinkedList* list, int index) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //Checks if the list is empty
   Node* temp = list->head;
   Node* pre = NULL;
   if (temp == NULL) return E_EMPTY_LIST;
   //Check if the data in head(1st node) is to be removed
   if (index == 0) {
      list->head = temp->next;
      free (temp);
      return 0;
   }
   //if the list is not empty, it iterates to remove the data at spec. index
   for (int i = 0; temp != NULL && i < index; i++) {
      pre = temp;
      temp = temp->next;
   }
   //checks if index exceeds list count
   if (temp != NULL && pre != NULL) {
      pre->next = temp->next;
      free (temp);
      return 0;
   }
   else {
      return E_INDEX_OUT_OF_RANGE;
   }
}

/// <summary>Inserts the value at a specified index</summary>
/// <param name="head"></param>
/// <param name="data"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int Insert (LinkedList* list, int data, int index) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   // Checks if the inserted node is going to be the head
   Node* newNode = CreateNode (data);
   if (index == 0) {
      newNode->next = list->head;
      list->head = newNode;
      return 0;
   }
   //if the list is not empty, it iterates to get the data at spec. index
   Node* temp = list->head;
   for (int i = 0; i < index - 1 && temp != NULL; i++) {
      temp = temp->next;
   }
   // checks if index exceeds list count
   if (temp == NULL || index < 0) {
      free (newNode);
      return E_INDEX_OUT_OF_RANGE;
   }
   newNode->next = temp->next;
   temp->next = newNode;
   return 0;
}
/// <summary>Returns the value at a specified index</summary>
/// <param name="head"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int Get (LinkedList* list, int index) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //Checks if the list is empty
   Node* temp = list->head;
   if (temp == NULL) return E_EMPTY_LIST;
   //iterates to get the value at index
   int count = 0;
   while (temp != NULL) {
      if (count == index) return(temp->data);
      count++;
      temp = temp->next;
   }
   return  E_INDEX_OUT_OF_RANGE;
}