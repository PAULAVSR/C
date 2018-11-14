//## @Author: Paul Passek
//## Description: simple implementation to check wether a given bracket-String is correctly opened and closed eg. {(} will return false 
#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdlib.h"

struct node {
  int data;
  struct node *next;
};

struct node *stack = NULL;
int bracketMatching (char input[]);

struct node *mkNode(char val){
  struct node *node = NULL;
  if((node = malloc(sizeof (struct node))) != NULL){
  node->data = val; return node;}
  else {return NULL;}
}

void push (char x) {
  struct node *p = mkNode(x);
  p->next = stack;
  stack = p;
}

int pop (void) {
  if (stack == NULL) return -1;
  struct node *p;
  char result;

  p = stack;
  result = p->data;

  stack = p->next;
  free (p);
  return result;
}


int main (int argc, char * argv []) {

  char a[100];
  scanf("%s",&a);

  if (bracketMatching (a))
    printf("korrekte Klammerung\n");
  else
    printf("fehlerhafte Klammerung:\n%s\n",a);
  }

int isMatching (char char1, char char2) {
  if (char1 == '(' && char2 == ')')
     return 1;
   else if (char1 == '{' && char2 == '}')
     return 1;
   else if (char1 == '[' && char2 == ']')
     return 1;
   else
     return 0;
}

int bracketMatching (char input[]) {
  int i = 0;


  while (input[i]) {
    if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
      push(input[i]);
    }
    if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
      if (stack == NULL) return 0;
      else if (!isMatching(pop(),input[i])) return 0;
    }
    i++;
  }

  if (stack == NULL)
    return 1;
  else
    return 0;
}
