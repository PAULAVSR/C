//## @Author: Paul Passek
//## Description: simple verison of a Caesar-Cipher en-/decryption
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"

char * encipher (char string[], int key);
char * decipher (char string[], int key);

int main (int argc, char * argv[]) {

  char a[] = "YLHOH NDPHQ DOOPDHKOLFK CX GHU XHEHUCHXJXQJ HLQHQ JURVVHQ IHKOHU"
  "JHPDFKW CX KDEHQ DOV VLH YRQ GHQ EDHXPHQ KHUXQWHUJHNRPPHQ ZDUHQ XQG"
  "HLQLJH VDJWHQ VFKRQ GLH EDHXPH VHLHQ HLQ KROCZHJ JHZHVHQ GLH RCHDQH"
  "KDHWWH PDQ QLHPDOV YHUODVVHQ GXHUIHQ";

  //char b[] = "VSUDFK\nH";
  int key = 3;
  char *string;
  string =  decipher (a,key);
  printf("%s\n",string);
  printf("\n\n");
  string = encipher (string,key);
  printf("%s\n\n",string);

  free (string);
  return 0;

}

char * encipher (char string[], int key) {
  char *string2;
  string2 = malloc(strlen(string)*sizeof(char));

  for (int i = 0; i < strlen(string); ++i) {
    if (isalpha(string[i])){
      string2[i] = string[i] + key;
      if ((int)string2[i] > 90) string2[i] -= 26;
    }
    else{
      string2[i] = string[i];
    }
  }
  return string2;
}

char * decipher (char string[], int key) {
  char *string2;
  string2 = malloc (strlen(string)*sizeof(char));

  for (int i = 0; i < strlen(string); ++i) {
    if (isalpha(string[i])){
      string2[i] = string[i] - key;
      if ((int)string2[i] < 65) string2[i] += 26;}
    else {
      string2[i] = string[i];
    }
  }

  return string2;
}
