#include <cstddef>
#include <cstdio>
#include <cstdlib>
typedef struct node Node;

struct node{
  Node* prev;
  int data;
  Node* next;
};

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data){
  Node* newNode = (Node*) malloc(sizeof(Node));
  if(newNode==NULL){
    return nullptr;
  }

  newNode->data = data;
  newNode->prev= NULL;
  newNode->next = NULL;

  return newNode;
}

void insertNode(int data){
  Node* newNode = createNode(data);
  if(newNode!=NULL){
    if(head == NULL){
      head = newNode;
      tail = newNode;
      return;
    } 
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

void deleteNode(int data){
  Node *currentNode = head;
  while(currentNode->data!=data){
    currentNode = currentNode->next;
  }
  if(currentNode==head){
    if(head==tail){
      head=NULL; tail=NULL;
    }
    else{
      head = head->next;
      head->prev=NULL;
    }
    free(currentNode);
  }
  else if(currentNode==tail && head!=tail){
    currentNode->prev->next = NULL;
    tail = currentNode->prev;
    free(currentNode);
  }
  else{
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    free(currentNode);
  }
}

void display(){
  Node *currentNode = head;
  while(currentNode!=tail){
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }
  printf("%d\n", currentNode->data);
}

int main(){
  insertNode(10);
  insertNode(20);
  insertNode(30);
  insertNode(40);
  insertNode(50);

  display();

  deleteNode(10);

  display();

  return 0;
}
