//## @Author: Paul Passek
//## Description: simple version of a single linked list with insert and delete operations
#include "stdio.h"
#include "stdlib.h"

struct node {
  int data;
  struct node *next;
};

struct node *mkNode(int val){
  struct node *node = NULL;
  if((node = malloc(sizeof (struct node))) != NULL){
  node->data = val; node->next = NULL; return node;}
  else {return NULL;}
}

struct node *head;
struct node *tail;

void insert_sorted (int val) {
  struct node *p = head;

  struct node *new = mkNode(val);

  if (head == NULL ||p->data >= val) {
    head = malloc(sizeof (struct node));
    head->data = new->data;
    head->next = p;
  }
  else if (p->next == NULL && p->data <= val){
    new->next = p->next;
    p->next = new;
  }
  else {
    struct node *ptr = head;
    while (p != NULL  && p->data <= val)
      p = p->next;

    while (ptr->next != p)
      ptr = ptr->next;

    p = malloc(sizeof (struct node));
    p->data = new->data;
    p->next = ptr->next;
    ptr->next = p;
  }
}


void printList(){
  struct node *tmp = head;
  printf("(");
  while(tmp != NULL){
  printf(" %d", tmp->data);
  tmp = tmp->next;
  }
  printf(" )\n");
}

struct node *reverse (void) {

  struct node * reversed = NULL;
  struct node * old = head;
  struct node * next = NULL;
  struct node * head_cp = NULL;
  struct node * previous = NULL;


  while (old != NULL) {

    struct node * temp = malloc(sizeof(struct node));
    temp->data = old->data;
    temp->next = NULL;

    if (head_cp == NULL) {
      head_cp = temp;
      previous = temp;
    }
    else {
      previous->next = temp;
      previous = temp;
    }

    next = old->next;
    old->next = reversed;
    reversed = old;
    old = next;
  }

  head = head_cp;
  return reversed;
}

int main (int argc, char * argv[]) {
  struct node *list1 = NULL;
  insert_sorted(1);
  insert_sorted(2);
  insert_sorted(4);
  insert_sorted(5);
  insert_sorted(7);
  insert_sorted(6);
  insert_sorted(3);
  printList();
  list1 = reverse();
  printList();
  head = list1;
  printList();
  return 0;
}
