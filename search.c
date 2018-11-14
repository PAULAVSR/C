//## @Author: Paul Passek
//## @Description: versions for binary search (standard, with pointer)
#include <stdio.h>

int linearSearch (int n, int a[], int l); // ACHTUNG in Aufgaben array: int [] a
int binarySearch2 (int n, int a[], int l);// ACHTUNG in Aufgaben array: int [] a
int binarySearch (int n, int a[], int l);
int binarySearch3 (int n, int a[], int l);

int main (int argc, char * argv[]) {

  int a[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  int l = 25;
  int n;
  scanf("%d",&n);
  getchar();

  printf("index = %d\n",linearSearch(n,a,l));
  printf("index = %d\n",binarySearch(n,a,l));
  //printf("index = %d\n",binarySearch2(n,a,l));
  printf("index = %d\n",binarySearch3(n,a,l));
  return 0;

}

int linearSearch (int n, int a[], int l) {
  int pos = l-1;
  while (pos>=0&&a[pos]!=n)pos--;
  return pos;
}

int binarySearch2 (int n, int a[], int l) {
  int index = l/2;
  int middle = a[index];
  if (middle < n) {
    while (index < l) {
      if (middle > n) { index -= (l-index)/2; l = index + (l - index)/2; middle = a[index];}
      else {
        index += (l - index)/2;
        middle = a[index];
        if (middle == n) { return index; }
      }
      if ((a[l] > n && a[index] < n) && (l-index == 1)) {return -1;}
    }
    index --;
    if (a[index] == n) { return index; }
    return -1;
  }
  else if (middle > n) {
    int lb = 0;
    while (index > 1 && index <= (l/2)) {
      if (middle < n) { index += ((l/2)-lb)/2;
        lb = index - ((l/2)-lb)/2;
        middle = a[index];
      }
      else{
        index -= (index-lb)/2;
        middle = a[index];
        if (middle == n) { return index; }

      }
      if ((a[index] > n && a[lb] < n) && (index-lb == 1)) {return -1;}
    }
    index --;
    if (a[index] == n) { return index; }
    return -1;
  }
  else  return index;
}

int binarySearch (int n, int a[], int l) {
  int lower = 0;
  int upper = l - 1;

  while (lower <= upper) {
    int middle = lower + ((upper-lower)/2);

    if (a[middle] == n){
      return middle;
    }
    else {
      if (a[middle] > n) {
        upper = middle -1;
      }
      else {
        lower = middle +1;
      }
    }
  }
  return -1;
}

int binarySearch3 (int n, int a[], int l) {
  int *lower;
  int *upper;

  lower = a;
  upper = a+l-1;

  if (*lower > n) return -1;

  while (*lower <= *upper) {
    int *middle;
    middle = lower + ((upper - lower)/2);
    if (*middle == n) {
      return middle-a;
    }
    else {
      if ((*middle) > n) {
        upper = middle -1;
      }
      else {
        lower = middle +1;
      }
    }
  }

  return -1;
}
