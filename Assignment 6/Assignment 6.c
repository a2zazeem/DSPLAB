#include <stdio.h>
#include <stdlib.h>

int leftSubTree = 0;

//creating a node of type structure
struct node{
	int data;
	int height;
	struct node* left;
	struct node* right;
};

//creating a node of type structure pointer
struct node* new_node(int value){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data = value;
	n->height = 1;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

//function to find the maximum of 2 integers
int max(int x,int y)
{
	return (x>y)?x:y;
}

//function to get the height of the AVL tree
int height(struct node* root)
{
	if(root==NULL)
		return 0;
	else{
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		
		if(leftHeight > rightHeight)
			return leftHeight;
		else
			return rightHeight;
	}
}

//function for clockwise rotation of tree
struct node* rotate_right(struct node* t1)
{
	struct node* t2 = t1->left;
	struct node* temp = t2->right;
	t2->right = t1;
	t1->left = temp;
	t1->height = max(height(t1->left),height(t1->right)) + 1;
	t2->height = max(height(t2->left),height(t2->right)) + 1;
	
	return t2;
}

//function for anticlockwise rotation of tree
struct node* rotate_left(struct node* t1)
{
	struct node* t2 = t1->right;
	struct node* temp = t2->left;
	t2->left = t1;
	t1->right = temp;
	t1->height = max(height(t1->left),height(t1->right)) + 1;
	t2->height = max(height(t2->left),height(t2->right)) + 1;
	
	return t2;
}

//function to get the balance factor
int balance(struct node* n){
	if(n != NULL)
		return (height(n->left) - height(n->right));
	else 
		return 0;
}

//function to insert a new node into the AVL tree
struct node* insert_node(struct node* root,int item)
{
	if(root==NULL){
		return new_node(item);
	}
	
	if(item < root->data){
		root->left=insert_node(root->left,item);
	}
	else
	if(item > root->data){
		root->right=insert_node(root->right,item);
	}
	else
		return root;
	root->height = max(height(root->left), height(root->right)) + 1;
	int bal = balance(root);
	if( bal > 1 && item < root->left->data)
	{		
		return rotate_right(root);
	}		
	if( bal < -1 && item > root->left->data)
	{
		return rotate_left(root);
	}		
	if( bal > 1 && item > root->left->data)
	{		
		root->left = rotate_left(root->left);	
		return rotate_right(root);
	}
	if( bal < -1 && item < root->right->data)
	{			
		root->right = rotate_right(root->right);	
		return rotate_left(root);
	}

	return root;
}

//function to find the node with min value
struct node* min_node(struct node* temp)
{
	struct node* n = temp;
	while(n->left != NULL)
		n=n->left;
		
	return n;
}

//function to delete a node from the AVL tree
struct node* delete_node(struct node* root, int item)
{
	if(root == NULL)
		return root;
	
	if(item < root->data)
		root->left = delete_node(root->left, item);
	else
	if(item > root->data)	
		root->right = delete_node(root->right,item);
	else{
		if((root->left == NULL)|| (root->right == NULL)){
			struct node* temp = (root->left) ? root->left : root->right;
			
			if(temp == NULL){
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			
			free(temp);
		}
		else{
			struct node* temp = min_node(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right,temp->data);
		}
	}
	
	if(root == NULL)
		return root;
	root->height = max(height(root->left),height(root->right))+1;
	int bal = balance(root);
	if(bal > 1 && balance(root->left) >=0)
	{
		return rotate_right(root);
	}
	
	if(bal < -1 && balance(root->right) <= 0)
	{
		return rotate_left(root);
	}	
	if(bal > 1 && balance(root->left) < 0)
	{
		root->left = rotate_left(root->left);
		return rotate_right(root);
	}
	
	if(bal < -1 && balance(root->right) > 0)
	{	
		root->right = rotate_right(root->right);
		return rotate_left(root);
	}
	
	return root;
}

//function to print the preorder traversal of the binary tree
void preorder(struct node *root){
	if(root != NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//function to print the inorder traversal of the binary tree
void inorder(struct node *root){			
	if(root != NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

//function to print the postorder traversal of the binary tree
void postorder(struct node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

//function to print the data item present in ith level
void printLevel(struct node* root,int i){
	if(root == NULL)
		return;
	if(i == 1){
		printf("%d ",root->data);
		return;
	}
	else
	if(i>1){
		printLevel(root->left,i-1);
		printLevel(root->right,i-1);
	}
}


//function to get the height of the AVL tree
int levelheight(struct node* root){
	if(root==NULL)
		return 0;
	else{
		int leftHeight = levelheight(root->left);
		int rightHeight = levelheight(root->right);
		
		if(leftHeight > rightHeight)
			return leftHeight+1;
		else
			return rightHeight+1;
	}
}

//function to print the levelorder traversal of the binary tree
void levelorder(struct node* root){
	int h = levelheight(root);
	int i;
	for(i=1; i<=h; i++)
		printLevel(root,i);
}

//function to find the sum of all nodes in the left subtree of the root node 
int sumTree(struct node* root){
	if(root!=NULL){
		leftSubTree = leftSubTree+root->data;
		sumTree(root->left);
		sumTree(root->right);	
	}
	return 	leftSubTree;
}

//main function
int main(){
	int choice,value;
	struct node* root=NULL;
	
	printf("\nWelcome to AVL Tree\n");
	printf("\n---------------------------------\n");
	
	mainmenu:
		printf("\nEnter the choice:\n ");
		printf("\n1.Insert a node\n");
		printf("\n2.Delete a node\n");
		printf("\n3.Print the Pre-order Traversal\n");
		printf("\n4.Print the In-order Traversal\n");
		printf("\n5.Print the Post-order Traversal\n");
		printf("\n6.Print the Level-order Traversal\n");
		printf("\n7.Sum of all nodes in left subtree of root node\n");
		printf("\n0.Exit\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nEnter data for the new node\n");
			scanf("%d", &value);
			root = insert_node(root,value);
			goto mainmenu;
		}
		else
		if(choice==2){
			printf("\nEnter the node you want to delete\n");
			scanf("%d",&value);
			root = delete_node(root,value);
			goto mainmenu;
		}
		else
		if(choice==3){
			preorder(root);
			goto mainmenu;
		}
		else
		if(choice==4){
			inorder(root);
			goto mainmenu;
		}
		else
		if(choice==5){
			postorder(root);
			goto mainmenu;
		}
		else
		if(choice==6){
			levelorder(root);
			goto mainmenu;
		}
		else
		if(choice==7){
			printf("\nSum of the nodes in the left subtree = %d\n",sumTree(root->left));
			goto mainmenu;
		}
		else
		if(choice==0){
			exit(1);
		}
		else{
			printf("\nINVALID CHOICE!! TRY AGAIN.");
			goto mainmenu;
		}
		goto mainmenu;
}

