//## @Author: Paul Passek
//## @Description: magic-square algorithm: https://de.wikipedia.org/wiki/Magisches_Quadrat#Das_Lo-Shu
#include <stdio.h>

int makeQuad (int n,int quad[][n]);
void validateRowCol (int *row, int *col, int row_border, int col_border);

int main (int argc, char *argv []) {
  int n = 2;

  while (n%2 == 0) {
    scanf("%d",&n);
  }
  int quad [n][n];
  for (int i=0;i<n+1;++i) {
    for (int j=0;j<n;++j) {
      quad [i][j] = 0;
    }
  }

  makeQuad (n,quad);
  return 0;
}

int makeQuad (int n,int quad[][n]) {
  int row_border = n-1;
  int col_border = n-1;
  int row,col,counter = 0;
  int median = (n-1)/2;
  if (median == 0) {
    quad[median][median] = ++counter;
  }
  else {
    quad[median+1][median] = ++counter;
  }

  row = median+1;
  col = median;

  while (counter < n*n) {
    row ++;
    col ++;

    validateRowCol (&row,&col,row_border,col_border);
      while (quad[row][col] != 0) {
        row++;
        col--;
        validateRowCol(&row,&col,row_border,col_border);
      }
      quad[row][col] = ++counter;
  }

  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) {
      printf("%d ",quad [i][j]);
    }
    printf("\n");
  }
}

void validateRowCol (int *row, int *col, int row_border, int col_border) {
  if (row_border - *row < 0) { *row = *row - row_border -1; }
  if (col_border - *col < 0) { *col = *col - col_border -1; }
  if (*col < 0) {*col = col_border;}
}
