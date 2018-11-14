//## @Author: Paul Passek
//## Description: produce histogram of n unsigned char values
//## Input: number n of unsigned char values, n unsigned char values
#include <stdio.h>
#include <stdlib.h>

void makeHist ( int number, unsigned char arr[]);
int compare_ints (const void *p1,const void *p2);

int main (int argc, char * argv[]) {
  int number;

  scanf("%d",&number);
  getchar();
  unsigned char arr[number];

  for (int i=0;i<number;++i) {
    scanf("%hhu",&arr[i]);
    getchar();
  }

  makeHist (number,arr);

  return 0;

}

void makeHist  (int number, unsigned char arr[]) {
  int index = 0;
  int elements = 0;
  int counter = 0;
  unsigned char unsorted_arr [number][2];
  unsigned char binary [number];
  for (int i=0;i<number;++i) {binary[i]=1;}

   while (index < number) {

     if (binary[index] == 1) {
       counter = 0;
       unsigned char value = arr[index];
       for (int i = index; i<number; ++i) {
         if (arr[i] == value) {
           ++counter;
           binary[i]=0;
          }
        }
      unsorted_arr [elements][0] = value;
      unsorted_arr [elements][1] = counter;
      ++elements;
      }

     for (int i=0;i<number;++i) {
      if (binary[i] == 1) {
        index = i;
        break;
      }
      else { if (i==number-1 && binary[i] == 0) {index = number;}}
      }
   }
  printf("\n");
  qsort(unsorted_arr,elements,2*sizeof(unsigned char),compare_ints);

  for (int i=0; i<elements;++i) {
    int reps = unsorted_arr[i][1];
    int loop = 0;
    printf("%hhu : %hhu   |  ",unsorted_arr[i][0],unsorted_arr[i][1]);
      while (loop<reps) {printf("*");loop++;}
    printf("\n");
  }
}
//comparism routine for qsort
int compare_ints (const void *p1,const void *p2) {
  unsigned char arg1 = *(unsigned char *)p1;
  unsigned char arg2 = *(unsigned char *)p2;
  if (arg1<arg2) return -1;
  if (arg1>arg2) return 1;
  return 0;
}
