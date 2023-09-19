#include <stdio.h> // WE will be using printf
#include <stdlib.h> // WE will be using malloc | free

/* Linked List in C */
/* What is linked list and what can i do about it */
/* The runtime complexity of a doubly linked list */
/* How does ArrayList work in CPU and Memory */
/*NULL<-[Prev:NULL|Data:1|Next]<->[Prev|Data:2|Next]->NULL */

// code -------------------------------------------------------typedef struct { 

// Node structure for the doubly linked list
struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};
// Function to create a new node
struct Node* createNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode ==NULL){
    exit(1);
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}
// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data){
  struct Node* newNode = createNode(data);
  newNode->next = *head;
  if(*head != NULL){
    (*head)->prev = newNode;
  }
  *head = newNode;
}
// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data){
  struct Node* newNode = createNode(data);
  struct Node* current = *head;
  if(*head == NULL){
    *head = newNode;
  }
  else {
    while (current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
    current->prev = current;
  }
}
// Function to delete a node by value
void deleteNode(struct Node** head, int data){
  struct Node* current = *head;
  while(current != NULL){
    if(current->data == data){
      if(current->prev != NULL){
        current->prev->next = current->next;
      }
      free(current);
      return;
    }
    current = current->next;
  }
}
// Function to print the linked list
void printList(struct Node* head){
  struct Node* current = head;
  printf("list");
  while(current != NULL){
    printf("%d ->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
// code -------------------------------------------------------

// main (arg,args[])

int main() {
  struct Node* head = NULL;
  insertAtEnd(&head,1);
  insertAtEnd(&head,2);
  insertAtEnd(&head,3);
  insertAtBeginning(&head,0);
  printList(head);
  deleteNode(&head,2);
  printList(head);

    return 0;
}











