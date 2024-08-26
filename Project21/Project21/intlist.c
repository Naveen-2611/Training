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

LinkedList* Create () {
   LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList));
   if (list != NULL) {
      list->head = NULL;
      list->deleted = false;
      list->count = 0;
      return list;
   }
   else
      return E_LIST_NOT_FOUND;
}

Node* CreateNode (int data) { //creates a new node with specified value
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode != NULL) {
      newNode->data = data;
      newNode->next = NULL;
      return newNode;
   }
   else
      return E_NODE_NOT_FOUND;
}

int Add (LinkedList* list, int data) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //checks if the list is empty
   Node* newNode = CreateNode (data);
   if (list->head == NULL) {
      list->head = newNode;
      list->count++;
      return 0;
   }
   // if the list is not empty, it iterates to the desired position
   Node* current = list->head;
   while (current->next != NULL) {
      current = current->next;
   }
   current->next = newNode;
   list->count++;
   return 0;
}

int Count (LinkedList* list) {
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   return list->count;
}

int Delete (struct LinkedList* list) {
   if (list->deleted == true)
      return E_LIST_DOES_NOT_EXIST;
   if (list->head == NULL) {
      list->deleted = true;
      return 0;
   }
   struct Node* temp = NULL;
   while (list->head != NULL) {
      temp = list->head;
      list->head = (list->head)->next;
      free (temp);
   }
   list->deleted = true;
   return 0;
}

int Remove (LinkedList* list, int data) {
   // checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //Checks if the list is empty
   if (list->head == NULL) return E_EMPTY_LIST;

   Node* temp = list->head;
   Node* pre = NULL;

   //Check if the data in head(1st node) is to be removed
   if (temp->data == data) {
      list->head = temp->next;
      free (temp);
      list->count--;
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
      list->count--;
      return 0;
   }
   else {
      return E_VALUE_NOT_FOUND;
   }
}

int RemoveAt (LinkedList* list, int index) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   //Checks if the list is empty
   if (list->head == NULL) return E_EMPTY_LIST;
   Node* temp = list->head;
   Node* pre = NULL;
   //Check if the data in head(1st node) is to be removed
   if (index == 0) {
      list->head = temp->next;
      free (temp);
      list->count--;
      return 0;
   }

   int c = Count (list);

   //if the list is not empty, it iterates to remove the data at spec. index
   if (index >= 0 && index < c) {
      for (int i = 0; i < index - 1; i++) {
         temp = temp->next;
      }
      pre = temp;
      temp = temp->next;
      pre->next = temp->next;
      free (temp);
      list->count--;
      return 0;
   }
   else {
      return E_INDEX_OUT_OF_RANGE;
   }
}

int Insert (LinkedList* list, int data, int index) {
   //checks if the list is deleted
   if (list->deleted == true) return E_LIST_DOES_NOT_EXIST;
   // Checks if the inserted node is going to be the head
   Node* newNode = CreateNode (data);
   if (index == 0) {
      newNode->next = list->head;
      list->head = newNode;
      list->count++;
      return 0;
   }
   int c = Count (list);
   Node* temp = list->head;
   if (temp == NULL) {
      free (newNode);
      return E_INDEX_OUT_OF_RANGE;
   }
   if (index >= 0 && index < c) {
      for (int i = 0; i < index - 1; i++)
         temp = temp->next;
   }
   else {
      free (newNode);
      return E_INDEX_OUT_OF_RANGE;
   }
   newNode->next = temp->next;
   temp->next = newNode;
   list->count++;
   return 0;
}

int Get (LinkedList* list, int ind, int* data) {
   if (list->deleted == true) {
      *data = NULL;
      return E_EMPTY_LIST;
   }
   if (list->head == NULL) {
      *data = NULL;
      return E_EMPTY_LIST;
   }
   Node* current = list->head;
   int count = 0;
   while (current != NULL) {
      if (count == ind) {
         *data = current->data;
         return 0;
      }
      count++;
      current = current->next;
   }
   *data = NULL;
   return  E_INDEX_OUT_OF_RANGE;
}