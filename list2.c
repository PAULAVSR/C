//## @Author: Paul Passek
//## @Description: simple version of double knotted list with insert and delete operation
#include "stdio.h"
#include "stdlib.h"

struct dnode{
int data;
struct dnode *next, *prev;
};
struct dnode *head;
struct dnode *last;

void printList();

struct dnode *mkNode(int val){
  struct dnode *node = NULL;
  if((node = malloc(sizeof (struct dnode))) != NULL){
    node->data = val;
    node->next=node->prev = NULL;
    return node;
  }
  else return NULL;
}

void insert_first (int val) {
  struct dnode *old = head;
  struct dnode *new = mkNode (val);
  head = malloc(sizeof(struct dnode));
  head->data = new->data;
  head->prev = NULL;
  head->next = old;
  last = old;
  if (old == NULL) last = head;
}

void delete (int val) {
  struct dnode *p = head;
  struct dnode *prev = NULL;

  while (last->next != NULL) last = last->next;

  while (p->next != NULL){

    if (p->data != val || p == head){
    prev = p;
    p = p->next;}

    if (head->data == val) {
      head = p;
      prev = head;
      if (head == last) head = NULL;
    }
    else {
      if (p->data == val) {
        prev->next = p->next;
        p = p->next;
          if (p == last && p->data == val) {
              head->next = NULL;
          }
      }
    }
  }
}

void printList(){
  struct dnode *tmp = head;
  printf("(");
  while(tmp != NULL){
    printf(" %d", tmp->data);
    tmp = tmp->next;
  }
  printf(" )\n");
}

int main (int argc, char * argv[]) {

  struct dnode *list2 = NULL;
  head = list2 ;
  insert_first(4);
  insert_first(4);
  insert_first(4);
  insert_first(5);
  insert_first(4);
  insert_first(4);
  insert_first(4);
  printList ();
  delete(5);
  printList();

  return 0;

}
