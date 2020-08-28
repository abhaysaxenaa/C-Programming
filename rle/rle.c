#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//CS211 Computer Architecture - Spring 2020
//Abhay Saxena

void compress(char* string){

	int length = strlen(string);				//Initializing length to the length of the string.
	
	for (int i = 0; i < length; i++){			//For loop iterates through each character of the string. 
		if (string[i] >= 48 && string[i] <= 57){	//Checks for digits and prints 'error' if any digit is found.
			printf("error\n");
			return;
		}
	}

	char frequency[10];					//Creating a temporary char array to store the frequency of
								//one character.
	char *s = malloc((sizeof(char)*(length*2+1)));	//Creating a temporary string pointer using malloc to store the compressed 								//string.
	int k = 0; 					//We will use the variable 'v' to iterate through the newly created string 's'.
	int count;					//The variable 'count' will be used to record the number of times a character is repeated.
	
	for (int i = 0; i < length; i++){			//Iterating through the length of the original string.
		s[k++] = string[i];				//We copy the current character in string to the compressed string 's'.
		count = 1;					//Count is initialized to 1 after each iteration.
		if ((i+1) < length){	
			while (string[i] == string[i+1]){	//Condition executes as long as string[i] is being repeated.
				count++;			//Count increments as character is several more times.
				i++;				//Index pointer increments.
			}
		}
		sprintf(frequency, "%d", count);	       //The sprintf() function prints all values from count into frequency.
		
		for (int j = 0; frequency[j] != '\0'; j++){	  //Here, we copy the frequency number into the string 's'.
			s[k] = frequency[j];
			k++;
		}
		
		for (int l = 0; frequency[l] != '\0'; l++){	  //We reset the values of frequency to 0, to reuse this char array
			frequency[l] = 0;			  //in the next iteration.
		}
			
	}
								//For-loop ends after storing all characters and frequencies in 's'.
	s[k] = '\0';						//Ends the string with the null terminator to remove extra space.
								
	int newLen = strlen(s);					//Set the variable 'newLen' to the length of the compressed string.
	
	if (newLen <= length){					//If the length of the compressed string is lesser than the original,
		for (int i = 0; i < newLen; i++){		//we print the compressed string.
			printf("%c", s[i]);
		}
	}
	
	else {
		for (int i = 0; i < length; i++){		//If the length of the original string is lesser than the compressed
			printf("%c", string[i]);		//string, we print the original string.
		} 
	}
	
	free(s);						//Freeing the allocated space to string pointer 's'.
	printf("\n");
	
}

int main(int argc, char **argv){
	compress(argv[1]);					//Passing the string input to helper fuction instantly.
	return 0;
}
