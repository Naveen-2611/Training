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
/// <summary>
/// this will create a new linked list.
/// </summary>
/// <returns></returns>

bool deleted;// Boolean varaible to keep track of deleted list 
Node* create () {// creating a NULL pointer
	Node* head = NULL;
	deleted = false;
	return head;
}
Node* createNode (int data) { //creates a new node with specified value
	Node* newNode = NULL;
	newNode = (Node*)malloc (sizeof (Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}
/// <summary>
/// insert the value at end
/// </summary>
/// <param name="head"></param>
/// <param name="data"></param>
int Add (struct Node** head, int data) { //Function to insert a new node at the end of the list
	if (deleted == true) return List_does_not_exist;
	Node* newNode = createNode (data);
	if (*head == NULL) {
		*head = newNode;
		return 0;
	}
	// Create a pointer to iterate till the last node
	Node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	// make the next of the tail to the new Node
	current->next = newNode;
	return 0;
}

/// <summary>
/// count the no of elements in the list
/// </summary>
/// <param name="head"></param>
/// count the no of elements in the list
int Count (Node** head) { //Counts number of nodes in linked list
	if (deleted == true) return List_does_not_exist;
	Node* temp = *head;
	int count = 0;
	while (temp != NULL) {
		count++;/// Increment count by 1
		temp = temp->next;
	}
	return count;///Return the count of nodes
}
/// <summary>
/// Delete entire list
/// </summary>
/// <param name="head"></param>
int Delete (Node** head) {// Delete the entire list 
	if (deleted == true) return List_does_not_exist;// check the list is empty and delete list
	Node* current = *head;
	Node* next = NULL;
	if (current == NULL); {
		deleted = true;
		return 0;
	}
	while (current != NULL) {
		next = current->next;
		free (current);
		current = next;
	}
	*head = NULL;
	deleted = true;
	return 0;
}
/// <summary>
/// removes the first occurrence of a specific element.
/// </summary>
/// <param name="head"></param>
/// <param name="data"></param>
int Remove (Node** head, int data) {// Removes the first occurrence of the specified value
	if (deleted == true) return List_does_not_exist;// check the list is empty and delete list
	Node* temp = *head;
	Node* pre = NULL;
	if (temp == NULL) return Empty_list;

	if (temp != NULL && temp->data == data) {
		*head = temp->next;
		free (temp);
		return 0;
	}
	while (temp != NULL && temp->data != data) {
		pre = temp;
		temp = temp->next;
	}
	if (temp != NULL) {
		pre->next = temp->next;
		free (temp);
		return 0;
	}
	else {
		return Value_not_found;
	}
}
/// <summary>
/// this will remove the element at a particular index 
/// </summary>
/// <param name="head"></param>
/// <param name="index"></param>
/// <returns></returns>
int RemoveAt (Node** head, int index) { //Removes the specified value based on the index
	if (deleted == true) return List_does_not_exist;// check the list is empty and delete list
	Node* temp = *head;
	Node* pre = NULL;
	if (temp == NULL) return Empty_list;

	if (index == 0) {
		*head = temp->next;
		free (temp);
		return 0;
	}

	for (int i = 0; temp != NULL && i < index; i++) {
		pre = temp;
		temp = temp->next;
	}
	if (temp != NULL && pre != NULL) {
		pre->next = temp->next;
		free (temp);
		return 0;
	}
	else {
		return Index_out_of_range;
	}

}

/// <summary>
/// Inser the value in specified index
/// </summary>
/// <param name="head"></param>
/// <param name="data"></param>
/// <param name="index"></param>
/// <returns></returns>

int Insert (Node** head, int data, int index) {// Insert a value at specified index
	if (deleted == true) return List_does_not_exist;// check the list is empty and delete list
	Node* newnode = createNode (data);
	if (index == 0) {
		newnode->next = *head;
		*head = newnode;
		return 0;
	}
	Node* temp = *head;
	for (int i = 0; i < index - 1 && temp != NULL; i++) {
		temp = temp->next;

	}
	if (temp == NULL || index < 0) {
		free (newnode);
		return Index_out_of_range;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	return 0;
}
/// <summary>
///  gets the element at a particular index.
/// </summary>
/// <param name="head"></param>
/// <param name="index"></param>
/// <returns></returns>
int Get (Node* head, int index) {//Get the value on specied index
	if (deleted == true) return List_does_not_exist;// check the list is empty and delete list
	Node* temp = head;
	if (temp == NULL) return; Empty_list; //Checks if the list is empty
	int count = 0;
	while (temp != NULL) {
		if (count == index)
			return(temp->data);
		count++;
		temp = temp->next;
	}
	return Index_out_of_range;
}