//## @Author: Paul Passek
//## @Description: converter for measure of length and measure of weight - full terminal program with little "GUI"
#include "header.h"

int main(int argc, char * argv[]){

  menuChoice ();

  return 0;

}


int askUser (char spaces_plus [100], char spaces [100], int choices) {

  printf("%s+++++++++++\n",spaces_plus);
  int n = -1;
  while (n < 1 || n > choices){
    printf("%sNummer: ",spaces);
    scanf("%d",&n);
    getchar();
  }
  printf("%s+++++++++++\n",spaces_plus);

  return n;

}


void menuChoice (void) {
  printf("%s\n",STARS_SPACES);
  printf("                         *\n");
  printf("Hauptmenü Umrechnungen   *\n");
  printf("                         *\n");
  printf("  1   Längenmaße         *\n");
  printf("                         *\n");
  printf("  2   Gewichtsmaße       *\n");
  printf("                         *\n");
  printf("                         *\n");
  printf("  3   Programm beenden   *\n");
  printf("                         *\n");
  printf("%s\n",STARS_SPACES);

  int n = askUser (SUB_FIRST_PLUS, SUB_FIRST,3);

  switch (n) {
    case 1: distanceMeasure ();break;
    case 2: weightMeasure ();break;
    case 3: exit(0);break;
  }
}

void distanceMeasure (void) {

  printf("%s************************\n",SUB_SECOND);
  printf("%s*  1 Zoll (=Inch)      *\n",SUB_SECOND);
  printf("%s*  2 Fuß               *\n",SUB_SECOND);
  printf("%s*  3 Schritt (=Yard)   *\n",SUB_SECOND);
  printf("%s*  4 Meile             *\n",SUB_SECOND);
  printf("%s*                      *\n",SUB_SECOND);
  printf("%s*  5 Gewichtsmaße      *\n",SUB_SECOND);
  printf("%s*  6 Hauptmenü         *\n",SUB_SECOND);
  printf("%s************************\n",SUB_SECOND);

  int n = askUser (SUB_THIRD_PLUS, SUB_THIRD,6);

  switch (n) {
    case 1: convertInch ();break;
    case 2: convertFeet ();break;
    case 3: convertYard ();break;
    case 4: convertMiles ();break;
    case 5: weightMeasure ();break;
    case 6: menuChoice ();break;
  }
}

int askConvertDirection (char space [100], char names [100], char menu_point [100]) {

  printf ("%s*************************\n",space);
  printf ("%s*  1 Umrechnung von %s  \n",space,names);
  printf ("%s*  2 Umrechnung nach %s \n",space,names);
  printf ("%s*                       \n",space);
  printf ("%s*  3 %s         \n",space,menu_point);
  printf ("%s*************************\n",space);

  int n = askUser (SUB_FOURTH_PLUS, SUB_FIFTH,3);

  switch (n) {
    case 1: return 1;break;
    case 2: return 2;break;
    case 3: if (strcmp (menu_point,"Längenmaße") == 0){distanceMeasure ();break;} else {weightMeasure();break;}
  }
  return 0;
}

float converter (float constant, float input) { return input*constant;}


void convertInch () {

  char brit [] = "Zoll";
  char germ [] = "cm";
  char menu_point [] = "Längenmaße";

  int direction = askConvertDirection (SUB_FOURTH,brit,menu_point);
  float constant = 0;

  switch (direction) {
    case 1: constant = 2.54;break;
    case 2: constant = 0.3937;break;
  }

  converterOutput (direction,constant,brit,germ);


  convertInch ();

}

void convertFeet  () {

  char brit [] = "Fuß";
  char germ [] = "cm";
  char menu_point [] = "Längenmaße";

  int direction = askConvertDirection (SUB_FOURTH,brit,menu_point);
  float constant = 0;

  switch (direction) {
    case 1: constant = 30.48;break;
    case 2: constant = 0.0328;break;
  }

  converterOutput (direction,constant,brit,germ);


  convertFeet ();

}

void convertYard () {

  char brit [] = "Yard";
  char germ [] = "m";
  char menu_point [] = "Längenmaße";

  int direction = askConvertDirection (SUB_FOURTH,brit,menu_point);
  float constant = 0;

  switch (direction) {
    case 1: constant = 0.9144;break;
    case 2: constant = 1.0936;break;
  }

  converterOutput (direction,constant,brit,germ);

  convertYard ();

}
// See Meilen oder Landmeilen
void convertMiles () {

  char brit [] = "Meilen (Land)";
  char germ [] = "km";
  char menu_point [] = "Längenmaße";

  int direction = askConvertDirection (SUB_FOURTH,brit,menu_point);
  float constant = 0;

  switch (direction) {
    case 1: constant = 1.60934;break;
    case 2: constant = 0.6214;break;
  }

  converterOutput (direction,constant,brit,germ);

  convertMiles ();

}


void converterOutput (int direction, float constant, char brit[100], char germ [100]) {

  float input = 0;

  if (direction == 1) {
    printf("%s****************************\n",SUB_SIX);
    printf ("%s Umrechnung von %s in %s\n",SUB_SIX,brit,germ);
    printf ("%s ",SUB_SIX);
    scanf ("%f",&input);
    getchar();
    printf ("%s %s entsprechen\n",SUB_SIX,brit);
    printf ("%s %f %s\n",SUB_SIX,converter(constant,input),germ);
    printf("%s****************************\n",SUB_SIX);
  }
  else {
    printf("%s****************************\n",SUB_SIX);
    printf ("%s Umrechnung von %s in %s\n",SUB_SIX,germ,brit);
    printf ("%s ",SUB_SIX);
    scanf ("%f",&input);
    getchar();
    printf ("%s %s entsprechen\n",SUB_SIX,germ);
    printf ("%s %f %s\n",SUB_SIX,converter(constant,input),brit);
    printf("%s****************************\n",SUB_SIX);
  }
}

void weightMeasure (void) {

  printf("%s************************\n",SUB_SECOND);
  printf("%s*  1 Unze              *\n",SUB_SECOND);
  printf("%s*  2 Pfund             *\n",SUB_SECOND);
  printf("%s*                      *\n",SUB_SECOND);
  printf("%s*  3 Längenmaße        *\n",SUB_SECOND);
  printf("%s*  4 Hauptmenü         *\n",SUB_SECOND);
  printf("%s************************\n",SUB_SECOND);

  int n = askUser (SUB_THIRD_PLUS, SUB_THIRD, 4);

  switch (n) {
    case 1: convertOunce ();break;
    case 2: convertPound ();break;
    case 3: distanceMeasure (); break;
    case 4: menuChoice (); break;
  }
}

void convertOunce () {

  char brit [] = "Unze";
  char germ [] = "g";
  char menu_point [] = "Gewichtsmaße";

  int direction = askConvertDirection (SUB_FOURTH,brit,menu_point);
  float constant = 0;

  switch (direction) {
    case 1: constant = 28.35;break;
    case 2: constant = 0.0353;break;
  }

  converterOutput (direction,constant,brit,germ);

  convertOunce ();
}

void convertPound () {

  char brit [] = "Pfund";
  char germ [] = "kg";
  char menu_point [] = "Gewichtsmaße";

  int direction = askConvertDirection (SUB_FOURTH,brit,menu_point);
  float constant = 0;

  switch (direction) {
    case 1: constant = 0.45359;break;
    case 2: constant = 2.205;break;
  }

  converterOutput (direction,constant,brit,germ);

  convertPound ();
}
