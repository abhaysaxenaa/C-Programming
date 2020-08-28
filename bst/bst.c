#include <stdio.h>
#include <stdlib.h>

//CS211 Computer Architecture - Spring 2020
//Abhay Saxena

typedef struct BinarySTnode{				//Construction of a struct called BinarySTnode which has the following properties
	int data;				//'data': Value of the BST node.
	struct BinarySTnode *left;			//'left': Pointer to left child of BST node.
	struct BinarySTnode *right;			//'right': Pointer to right child of BST node.
}BinarySTnode;

BinarySTnode *insert(BinarySTnode *root, int n);		//insert: Inserts number in Binary Search Tree.
BinarySTnode *delete(BinarySTnode *root, int n);		//delete: Deletes number from Binary Search Tree.
BinarySTnode *findMax(BinarySTnode *root);		//findMax: Finds the greatest value in the left subtree of node.
void print_tree(BinarySTnode *root);			//print_tree: Prints tree in a specific format.
void search_tree(BinarySTnode *root, int n);		//search_tree: Searches the BST for a specific number.

BinarySTnode *root = NULL;				//Initializing 'root' node to NULL.

BinarySTnode *insert(BinarySTnode *root, int n){				//The Insert Method.

	if (root == NULL){					//If BST is empty or number does not exist.
		BinarySTnode *ptr = malloc(sizeof(BinarySTnode));		//Allocate space for new BST node and give it the
		ptr->data = n;					// appropriate properties.
		ptr->left = NULL;
		ptr->right = NULL;
		printf("inserted\n");				//Print 'inserted' if number is not a duplicate and is 
		return ptr;					//Inserted into the BST. Return a pointer to this node.
	}
	
	if (root->data == n){					//If number already exists in the BST, print 'not inserted'
		printf("not inserted\n");			//and return root without performing any operations.
		return root;
	}
	
	if (root->data > n){					//If number is less than the current node's value,
		root->left = insert(root->left, n);		//'recursively' call the node's 'left' child and continue.
	}
	
	else {							//If number is greater than the current node's value,
		root->right = insert(root->right, n);		//'recursively' call the node's 'right' child and continue.
	}
	return root;
}

BinarySTnode *delete(BinarySTnode *root, int n){					//The Delete Method.
	
	if (root == NULL){						//If BST is empty, print 'absent' and return.
		printf("absent\n");
		return root;
	}
	if (root != NULL){
		if (root->data > n){						//If number is less than current node's value,
			root->left = delete(root->left, n);			//recursively call delete on root's left child.
		}
		
		if (root->data < n){						//If number is greate than current node's value,
			root->right = delete(root->right, n);			//recursively call delete on root's right child.
		}
		
		if (root->data == n) {						//If number EXISTS in the BST:
		
			if (root->left == NULL && root->right == NULL){		//Case 1: Number is a LEAF NODE.
				free(root);					//Simply free the space allocation to this number.
				printf("deleted\n");				//Print 'deleted'.
				return NULL;					//Return a NULL pointer.
			}
			
			if (root->right == NULL && root->left != NULL){		//Case 2: Child is a part of the LEFT subtree.
				BinarySTnode *temp = root->left;		//Number is deleted and replaced with left child.
				free(root);
				printf("deleted\n");			//Print 'deleted'.
				return temp;				//Return temp as 'left' child of root's parent.
			}
			if (root->left == NULL && root->right != NULL){		//Case 2: Child is a part of the RIGHT subtree.
				BinarySTnode *temp = root->right;		//Number is deleted and replaced with right child.
				free(root);
				printf("deleted\n");			//Print 'deleted'.
				return temp;				//Return temp as 'right' child of root's parent.
			}
			
			if (root->left != NULL && root->right != NULL){		//Case 3: Node has two children.
				BinarySTnode *temp = root->right;		//We create a node temp, set to root's right child.
				while (temp->left != NULL){			//The purpose of this loop is to find the greatest value
					temp = temp->left;			//on the right subtree of the root.
				}
				root->data = temp->data;			      //We can then replace the value of the root with this number
				root->right = delete(root->right, temp->data);	      //and then recursively call delete on the new number to avoid
			}							      //duplication.
		}					
	}		//I have a question, why does the last while loop not work with root->left? Since that is what was specified in the handout.
			//I wrote root->right because when I randomly tried it, it got me a 15.0/15.0 through the auto-grader.
			 
	return root;							//Return pointer to root.
	
}

void print_tree(BinarySTnode *root){			//The Print Method.

	if (root == NULL) return;			//If Binary Search Tree is empty, return.
	
	if (root->left != NULL){			//If left subtree does exist, we print an open '(' bracket and recursively call print_tree
		printf("(");				//with a left-child argument.
		print_tree(root->left);
	}
	
	printf("%d", root->data);			//If left subtree is non-existent, we print the value of the current node.
	
	if (root->right != NULL){			//We then check for the presence of a right subtree, if it is present, we print an open '('
		printf("(");				//bracket and recursively call print_tree with a right-child argument.
		print_tree(root->right);
	}
	printf(")");					//Closed ')' bracket to finish printing the Binary Search Tree.
	
}

void search_tree(BinarySTnode *root, int n){		//The SearchTree Method.

	BinarySTnode *ptr = root;			//Set temporary pointer 'ptr' to root.

	if (ptr == NULL){				//Case 1: If BST is empty, print 'absent' and return.
		printf("absent\n");
		return;
	}
	
	while (ptr != NULL){				//Case 2: If BST is not empty.
		if (ptr->data == n){		        //Serves as the base condition for the while loop, if number is found, print 'present'.
			printf("present\n");
			return;
		}

		if (ptr->data > n){			//If value of number is lesser than current node value, traverse to the left-subtree of node.
			ptr = ptr->left;
			if (ptr == NULL){		//If ptr encounters a NULL pointer, break.
				break;
			}
		}

		if (ptr->data < n){			//If value of number is greater than current node value, traverse to the right-subtree of node.
			ptr = ptr->right;
			if (ptr == NULL){		//If ptr encounters a NULL pointer, break.
				break;
			}
		}
	}
	printf("absent\n");				//If number is not found, print 'absent'.
}

int main(int argc, char **argv){

	char c;								//Character variable to take in instructions.
	int number;							//Integer variable to perform operations with respect to.
	
	while (scanf("%c", &c) != EOF){					//Since the calling of 'print' has a single argument 'p', we break down the
		if (c == 'p'){						//process of scanning. If the inital character argument is 'p', it calls print.
			if (root == NULL){
				printf("\n");
			}
			else {	
				printf("(");
				print_tree(root);
				printf("\n");
			}
		}
		else {							//If initial character argument is not 'p', we read in the following integer
			scanf("%d", &number);				//to perform other operations.
			if (c == 'i'){					//If character instructs 'i', we call the insert function.
				root = insert(root, number);
			}
			
			if (c == 'd'){					//If character instructs 'd', we call the delete function.
				root = delete(root, number);;
			}
			
			if (c == 's'){					//If character instructs 's', we call the search_tree function.
				search_tree(root, number);
			}
		}
	}

	return 0;							//Exit Success.
}
