#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//CS211 Computer Architecture - Spring 2020
//Abhay Saxena

void Palindrome(char* string){
	
	int length = strlen(string);				//Finding length of string to perform operations.
	for (int v = 0; v < length; v++){			//Converts all uppercase characters to lowercase characters
	  string[v] = tolower(string[v]);			//with help of the tolower() function.
	}
	
	int low = 0;						//low iterator index to check from the starting of the string
	int hi = length - 1;					//hi iterator index to check from the end of the string
	
	while (low < hi){					//While the low index does not surpass the hi index.
		while (!(isalpha(string[low]))){		//isalpha checks if the character is an alphabet.
			low++;					//low keeps incrementing till a lowercase alphabet is found.
		}
		while (!(isalpha(string[hi]))){			//hi keeps decrementing till a lowercase alphabet is found.
			hi--;
		}
		if (string[low] != string[hi]){			//This condition checks if the string[low] matches string[hi].
			printf("no\n");				//The program breaks instantly if string is not a palindrome.
			return;
		}
		low++;
		hi--;
	}
	printf("yes\n");					//if loop doesn't break then it is a palindrome.
}

int main(int argc, char **argv){
	Palindrome(argv[1]);					//Passing the string input directly to the helper function.
	return 0;
}


