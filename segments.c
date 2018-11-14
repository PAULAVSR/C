//## @Author: Paul Passek
//## @Description: seven-segment display for Integer
#include <stdio.h>


#define HORIZONTAL " __ "
#define RIGHTUPPER " __|"
#define LEFTUPPER "|__ "
#define SINGLELEFT "|   "
#define SINGLERIGHT "   |"
#define DOUBLESIGHT "|  |"
#define FULLHOUSE "|__|"

void printLine1 (int factor);
void printLine2 (int factor);
void printLine3 (int factor);
void printLine4 (int factor);
void printLine5 (int factor);

int checkInput (int * zahl){
  while (* zahl < 0){
    printf("Zahl: ");
    scanf("%d",zahl);
  }

  return * zahl;
}

int main (int argc, char * argv[]){

  int zahl, factors, length = 0;

  printf("Zahl:");
  scanf("%d",&zahl);
  zahl = checkInput (&zahl);
  factors = zahl;
  while (factors % 10 != factors){
    factors /= 10;
    length++;
  }

  int factorarr[length];

  factors = zahl;
  for (int i = 0;i<=length;++i){
    factors = (zahl / 10) * 10;
    factorarr[i] = zahl - factors;

    zahl = factors/10;
  }


  for (int i = 0 ; i<=length ;++i ){
    printLine1(factorarr[length-i]);
    printf("   ");
  }

  printf("\n");

  for (int i = 0 ; i<=length ;++i ){
    printLine2 (factorarr[length-i]);
    printf("   ");
  }

  printf("\n");

  for (int i = 0 ; i<=length ;++i ){
    printLine3 (factorarr[length-i]);
    printf("   ");
  }

  printf("\n");

  for (int i = 0 ; i<=length ;++i ){
    printLine4 (factorarr[length-i]);
    printf("   ");
  }

  printf("\n");

  for (int i = 0 ; i<=length ;++i ){
    printLine5 (factorarr[length-i]);
    printf("   ");
  }

    printf("\n");
    printf("\n");

}

void printLine1 (int factor){

  if (factor != 1 && factor != 4){
    printf("%s",HORIZONTAL);
  }
  else {
    printf("    ");
  }

}

void printLine2 (int factor){

  if (factor == 1 || factor == 2 || factor == 3 || factor == 7 ){
    printf("%s",SINGLERIGHT);
  }
  else if (factor == 5 || factor == 6){
    printf("%s",SINGLELEFT);
  }
  else {
    printf("%s", DOUBLESIGHT);
  }

}


void printLine3 (int factor){

  if (factor == 1 || factor == 7 ){
    printf("%s",SINGLERIGHT);
  }
  else if (factor == 2 || factor == 3){
    printf("%s",RIGHTUPPER);
  }
  else if (factor == 5 || factor == 6){
    printf("%s",LEFTUPPER);
  }
  else if (factor == 4 || factor == 8 || factor == 9){
    printf("%s",FULLHOUSE);
  }
  else {
    printf("%s", DOUBLESIGHT);
  }

}


void printLine4 (int factor){

  if (factor != 0 && factor != 2 && factor != 8 && factor !=6){
    printf("%s",SINGLERIGHT);
  }
  else if (factor == 2 ){
    printf("%s",SINGLELEFT);
  }
  else if (factor == 0 || factor == 8 || factor == 6) {
    printf("%s", DOUBLESIGHT);
  }

}

void printLine5 (int factor){

  if (factor == 1 || factor == 4 || factor == 7 ){
    printf("%s",SINGLERIGHT);
  }
  else if (factor == 3 || factor == 5 || factor == 9){
    printf("%s",RIGHTUPPER);
  }
  else if (factor == 2){
    printf("%s",LEFTUPPER);
  }
  else {
    printf("%s", FULLHOUSE);
  }

}
