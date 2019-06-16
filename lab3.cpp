/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

/* C++ implementation to delete a doubly Linked List node  
   at the given position */
//#include<bits/stdc++.h> 
  
using namespace std; 
  
/* a node of the doubly linked list */
class Node {
	public: 
    int data; 
    class Node* next; 
    class Node* prev; 
}; 
  
/* Function to delete a node in a Doubly Linked List. 
   head_ref --> pointer to head node pointer. 
   del  -->  pointer to node to be deleted. */
void deleteNode(class Node** head_ref, class Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    /* Change next only if node to be deleted is NOT  
       the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted is NOT  
       the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
} 
  
/* Function to delete the node at the given position 
   in the doubly linked list */
void deleteNodeAtGivenPos(class Node** head_ref, int n) 
{ 
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0) 
        return; 
  
    class Node* current = *head_ref; 
    int i;
    i = 0; 
  
    /* traverse up to the node at position 'n' from 
       the beginning */
    for (int i = 1; current != NULL && i < n; i++) 
        current = current->next; 
  
    /* if 'n' is greater than the number of nodes 
       in the doubly linked list */
    if (current == NULL) 
        return; 
  
    /* delete the node pointed to by 'current' */
    deleteNode(head_ref, current); 
} 
  
/* Function to insert a node at the beginning  
   of the Doubly Linked List */
void push(class Node** head_ref, int new_data) 
{ 
    /* allocate node */
    class Node* new_node =  
         (class Node*)malloc(sizeof(class Node)); 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* since we are adding at the beginning, 
    prev is always NULL */
    new_node->prev = NULL; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* change prev of head node to new node */
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
/* Function to print nodes in a given doubly 
   linked list */
   //int j = 0;
int printList(class Node* head) 
{ 
	int j = 0;
    while (head != NULL) { 
        cout<<head->data<< " "; 
        head = head->next;
        j++; 
    }
    return j; 
} 

int printlist(class Node* head) 
{ 
	int j = 0;
    while (head != NULL) { 
        //cout<<head->data<< " "; 
        head = head->next;
        j++; 
    }
    return j; 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    class Node* head = NULL; 
  
    /* Create the doubly linked list 10<->8<->4<->2<->5 */
    push(&head, 5); 
    push(&head, 2); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 10); 
  
    cout << "Doubly linked list before deletion:n"; 
    printList(head); 
  
    int n = printlist(head); 
  
    /* delete node at the given position 'n' */
    deleteNodeAtGivenPos(&head, n); 
  
    cout << "\nDoubly linked list after deletion:n"; 
    printList(head); 
  
    return 0; 

}