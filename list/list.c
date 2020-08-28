#include <stdio.h>
#include <stdlib.h>

//CS211 Computer Architecture - Spring 2020
//Abhay Saxena

typedef struct LLnode_struct{					//Defining struct as a Linked List
	int data;						//node, with properties 'data' and a
	struct LLnode_struct *next;				//pointer to the 'next' node.
}LLnode_struct;

LLnode_struct* LLhead = NULL;					//Initializing the front 'LLhead' 									//node to NULL.

LLnode_struct* insert(LLnode_struct* LLhead, int n){		//The Insert Method.

	LLnode_struct *ptr = malloc(sizeof(LLnode_struct));	//Creates space using malloc for
	LLnode_struct *temp = malloc(sizeof(LLnode_struct));	//ptr and temp pointers.
	
	ptr->data = n;						//Sets 'n' as the value for ptr.
								
								//Check for DUPLICATES.
	if (LLhead != NULL){					//If linked list is not empty.
	temp = LLhead;						//Sets 'temp' pointing to front.
		while (temp != NULL){			//While 'temp' does not reach the end of LL.
			if (temp->data == n){		//If 'n' is already present in LL, return.
				return LLhead;		//Since no duplicates are allowed.
			}
			temp = temp->next;		//Traverses through the linked list.
		}
		free(temp);				//If no duplicates are found, we free temp.
	}
	
	ptr->next = LLhead;				//Inserts ptr as the front of the LL.
	LLhead = ptr;					//Sets front of the LL as ptr.
	return LLhead;					//Return the front of the LL.
}

LLnode_struct* delete(LLnode_struct* LLhead, int n){		//The Delete Method.

	if (LLhead == NULL){					//If linked list is empty, return.
		return LLhead;
	}
	
	LLnode_struct *ptr = LLhead->next;			//Create two temporary pointers,
	LLnode_struct *prev = LLhead;				//'ptr' and 'prev'.

	if (prev->data == n){					//If item to be deleted is the first
		LLhead = prev->next; 				//item.
		return LLhead;
	}
	
	while (ptr != NULL){					//While ptr does not reach the end
		if (ptr->data == n){				//of the linked list, we traverse
			prev->next = ptr->next;			//through and if we encounter the 
		}						//number to be deleted, we set the
		prev = ptr;					//prev->next to ptr->next, which
		ptr = ptr->next;				//deletes the desired number.
	}
	
	return LLhead;						//return front of the linked list.
}

void bubbleSort(){						//The BubbleSort helper function.
	LLnode_struct *temp;					//Creates two temporary pointers
	LLnode_struct *ptr;					//'temp' and 'ptr'.
	
	for (temp = LLhead; temp != NULL; temp = temp->next){		//The nested for loops
		for (ptr = temp; ptr != NULL; ptr = ptr->next){		//traverse through the
			if ((temp->data) > (ptr->data)){		//entire LL and switch
				int num = temp->data;			//the locations in a
				temp->data = ptr->data;			//sorted order.
				ptr->data = num;
			}						//Time Complexity: O(n^2).
		}
	}
}

void print_list(LLnode_struct *LLhead, int num){		//The PrintList helper function.
	LLnode_struct *ptr = LLhead;
	printf("%d :", num);				//Creates a temporary pointer and traverses
	while (ptr != NULL){				//through entire linked list while printing
		printf(" %d", ptr->data);		//it in a specific format.
		ptr = ptr->next;
	}
	printf("\n");
}

void free_(){						//Freeing the Linked List.
	LLnode_struct *ptr = LLhead;
	while (!(ptr == NULL)){				//Creates a temporary pointer ptr and 
		LLnode_struct *pointer = ptr;		//traverses through entire LL while freeing
		ptr = ptr->next;			//each node's space allocation.
		free(pointer);
	}
}

int count(){						//Counting the number of nodes in LL.
	LLnode_struct *ptr = LLhead;
	int count = 0;					//Traverses through LL and returns 'count'
	while (!(ptr == NULL)){				//which is the total number of nodes in LL.
		count++;
		ptr = ptr->next;
	}
	return count;					//Returns 'count' of linked list.
}

int main (int argc, char **argv){
	
	int number;					//Number to be inserted/deleted from LL.
	char c;						//Operation to be performed: 'i'/'d'.
	int countList = 0;				//Variable to store total #nodes in LL.
	
	while (scanf("%c%d", &c, &number) != EOF){		//Takes in arguments till 'EOF'.
	
		if (c == 'i'){						//If command is 'i':
				LLhead = insert(LLhead, number);	//calls 'insert'
				bubbleSort();				//sorts LL after inserting node
				countList = count();			//returns total count of LL nodes
				print_list(LLhead, countList);		//prints the LL in format.
		}
		
		if (c == 'd'){						//If command is 'd':
			LLhead = delete(LLhead, number);		//calls 'delete'
			bubbleSort();					//sorts LL after deleting node
			countList = count();				//returns total count of LL nodes
			print_list(LLhead, countList);			//prints the LL in format.
		}
	}
	
	free_();						//Calls free method to free space allocation of LL.
	
	return 0;
}
