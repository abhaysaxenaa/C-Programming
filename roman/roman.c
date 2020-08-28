#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CS211 Computer Architecture - Spring 2020
//Abhay Saxena

/*This approach utilizes the number read from standard input, and processes in it a way where each of its base values as well as well as single numeric digits are compared to their respective roman literal and printed out in the specified format.*/

void romanString (int number){
	
	int quotient = 0;			//This variable quotient will be used to determine the power of the highest 							//base value of the number and print out its roman equivalent w.r.t its 						//individual digit power.
	
	if (number >= 1000){			//If the number's highest base value is > 1000, we print 'M' w.r.t to the 							//digit value of the quotient.
		quotient = number / 1000;
		number = number % 1000;		//The use of the modulus is simply to find the remainder of the number and 							//continue the same operation with its next highest base value.
		while (quotient > 0){		//The while loop prints 'M' depending on the single digit value of the 							//quotient.
			printf("M");
			quotient--;
		}
	}
	
	if (number >= 900){			//Similarly, the remainder of the number is used to compare its next highest 							//base value and print its roman equivalent respectively.
		quotient = number / 900;	//Base value 900
		number = number % 900;
		printf("CM");
	}
	
	if (number >= 500){			//Base value 500.
		quotient = number / 500;
		number = number % 500;
		while (quotient > 0){
			printf("D");
			quotient--;
		}
	}
	
	if (number >= 400){			//Base value 400.
		quotient = number / 400;
		number = number % 400;
		printf("CD");
	}
	
	if (number >= 100){			//Base value 100.
		quotient = number / 100;
		number = number % 100;
		while (quotient > 0){
			printf("C");
			quotient--;
		}
	}
	
	if (number >= 90){			//Base value 90.
		quotient = number / 90;
		number = number % 90;
		printf("XC");
	}
	
	if (number >= 50){			//Base value 50.
		quotient = number / 50;
		number = number % 50;
		printf("L");
	}
	
	if (number >= 40){			//Base value 40.
		quotient = number / 40;
		number = number % 40;
		printf("XL");
	}
	
	if (number >= 10){			//Base value 10.
		quotient = number / 10;
		number = number % 10;
		while (quotient > 0){
			printf("X");
			quotient--;
		}
	}
	
	if (number == 10){			//After the original number has been processed to its single digit numeric, we 							//simply print its roman literal.
		printf("X");
	}
	if (number == 9){
		printf("IX");
	}
	if (number == 8){
		printf("VIII");
	}
	if (number == 7){
		printf("VII");
	}
	if (number == 6){
		printf("VI");
	}
	if (number == 5){
		printf("V");
	}
	if (number == 4){
		printf("IV");
	}
	if (number == 3){
		printf("III");
	}
	if (number == 2){
		printf("II");
	}
	if (number == 1){
		printf("I");
	}
	printf("\n");				//Print new line.
}

int main (int argc, char **argv) {
	
	int value = atoi(argv[1]);		//atoi converts a string representation to an integer, which we use for
	romanString(value);			//processing.
	return 0;
	
}
