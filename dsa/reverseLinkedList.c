#include <cstddef>
#include <cstdlib>
#include <stdio.h>

typedef struct node Node;

struct node{
  int data;
  Node *next;
};

// Global head pointer
Node *head = nullptr;

Node *createNode(int data){
  Node *newNode = (Node*) malloc(sizeof(Node));
  if(newNode == nullptr){
    printf("New node can not be allocated!");
    return nullptr;
  }

  newNode->data = data;
  newNode->next = NULL;

  // printf("Inside newNoded: %p\n", newNode);
  // printf("Address of newNode: %p\n", &newNode);

  return newNode;
}

void insertBegain(int data){
  Node *newNode = createNode(data);
  if(newNode!=nullptr){
    newNode->next = head;
    head = newNode;
  }
}

void reverseList(){
  if(head == NULL){
    return;
  }
  Node *node = NULL;
  Node *currentNode = head;
  Node *headNode = head;
  while(headNode->next!=NULL){
    headNode = headNode->next;
    currentNode->next = node;
    node = currentNode;
    currentNode = headNode;
  }
  headNode->next = node;
  head = headNode;
}

void printList(){
  Node *currentNode = head;
  while(currentNode){
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }
  printf("NULL\n");
}

int main(){
  insertBegain(1);
  insertBegain(2);
  insertBegain(3);
  insertBegain(4);
  insertBegain(5);

  printList();

  reverseList();

  printList();
  // printf("%d\n", head->data);
  // printf("Inside head: %p\n", head);
  // printf("Address of data: %p\n",&head->data);
  // printf("Address of head: %p\n", &head);
  return 0;
}
