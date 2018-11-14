//## @Author: Paul Passek
//## Description: calculate binary or decimal version of a given number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int decimalToBinary (int n);
int binaryToDecimal (int n);

void decideCalc (int d);

int main (int argc , char * argv[]) {

	int d = 0;

	printf ("***********************\n\n");
	printf ("Variante 1: Umrechnung von Dezimalsystem in Binärsystem\n\n");
	printf ("Variante 2: Umrechnung von Binärsystem in Dezimalsystem\n\n");
	printf ("Variante 3: Beenden\n\n");
	printf ("***********************\n\n");

	while (!(d == 1 || d == 2 || d == 3)){
			printf ("Variante ");
			scanf ("%d",&d);
			getchar();
	}

	decideCalc (d);



}
// negative Zahlen abfangen

void decideCalc (int d) {

	int solution,n = -1;



	if (d == 1) {
		printf("\n\n++++++++++++++++++++++++++++\n\n");

		while (n < 0){
			printf ("Zahl im Dezimalsystem: ");
			scanf ("%d",&n);
			getchar();
		}
		solution = decimalToBinary (n);
		printf("%d\n",solution);
		}
	else if (d == 2) {
		printf("\n\n++++++++++++++++++++++++++++\n\n");

		while (n<0){
			printf ("Zahl im Binärsystem: ");
			scanf ("%d",&n);
			getchar();
		}
		solution = binaryToDecimal (n);
		printf("%d\n",solution);
		}
	else{
		exit(0);}

	printf("\n++++++++++++++++++++++++++++\n\n\n");

		main(0,0);
}

int decimalToBinary (int n) {

	int i = 0;
	int exp = 1;
	int binary = 0;

	printf ("\nDualzahl: ");
	while ( exp <= n) {
		exp = pow (2,i);
		i++;
	}

	if (i>2){i-=2;}

	for (int j = i; j>-1;--j) {
		if (n-pow(2,j)<0) {
			binary *= 10;
		}
		else {
			binary = (binary * 10) + 1;
			n -= pow (2,j);
		}

	}
	return binary;
}

int binaryToDecimal (int n) {

	int count = 0;
	int temp_n = n;
	while (temp_n>1) {
		temp_n /=10;
		count +=1;
	}
	//count ++;
	printf ("\nDezimalzahl: ");
	int decimal = 0;
	for (int i = 0;i<count+1;++i) {
		int temp = (n/10)*10;
		int factor = n - temp;
		if (!(factor == 0 || factor == 1)){printf("!!!! Das war eine ungültige Zahl im Binärsystem. Sie gelangen nun zum Haupmenü.\n\n"); main(0,0);}
		decimal += factor * pow(2,i);
		n = temp/10;
	}


	return decimal;
}
