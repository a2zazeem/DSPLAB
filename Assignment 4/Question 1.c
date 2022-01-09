#include <stdio.h>
#include <stdlib.h>

struct node  //creating a node
{
	int data;
	struct node *left;
	struct node *right;
	int rcount;
	int lcount;
};


struct node* createNode(int data) //creating a node with structure pointer
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	n->lcount=0;
	n->rcount=0;
	return n;
};

int checkTree(int x) //function to check my binary tree condition
{
	x++;
	while(x%2 == 0)
		x=x/2;		
	if(x == 1)
		return 1;
	else
		return 0;
}

struct node* createTree(struct node* root,int data) //function to create the binary tree
{
	if(root==NULL)
	{
		struct node *n=createNode(data);
		return n;
	}
	
	else if(root->rcount==root->lcount)
	{
		root->left=createTree(root->left,data);
		root->lcount++;
	}
	
	else if(root->rcount < root->lcount)
	{
		
		if(checkTree(root->lcount))
		{
			root->right=createTree(root->right,data);
			root->rcount++;
		}
		else
		{
			root->left=createTree(root->left,data);
			root->lcount++;
		}
	}
	return root;
}

int heightTree(struct node *root) //function to print height of the tree
{
	if(root==NULL)
		return 0;
	int left=heightTree(root->left);
	int right=heightTree(root->right);
	if(right<left)
		return(++left);
	else
		return(++right);
}

void inOrder(struct node *root) //function to print tree in inorder
{	 		
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

void preOrder(struct node *root) //function to print tree in preorder
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(struct node *root) //function to print tree in postorder
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);
	}
}

void treeStage(struct node *root, int i)
{
	if(root==NULL)							
		return;
	if(i==1)
		printf("%d   ",root->data);
	else if(i>1)
	{
		treeStage(root->left,i-1);
		treeStage(root->right,i-1);
	}
}

void printTree(struct node *root) //function to print the tree
{
	int i,j,height=heightTree(root);
	for(i=0;i<height;i++)
	{
		printf("\n");
		for(j=0;j<height-i;j++){
			printf("   ");
		}
		treeStage(root,i);
		printf("\n");
	}
}

void main()
{
	
	int size,choice,height,i;
	struct node *root=NULL;
	printf("\nWelcome to the Binary Tree Program\n------------------------------------------\nEnter the number of elements of the tree: \n");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter the elements of the tree:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	//Creating the Tree from the input elements
	for(i=0;i<size;i++)
		root=createTree(root,arr[i]);
	mainmenu:
		printf("\n");
		printf("\nChoose from below:\n1.Get Height of the Tree\n2.Get Inorder Traversal of the Tree\n3.Get Preorder Traversal of the Tree\n4.Get Postorder Traversal of the Tree");
		printf("\n5.Display the Tree\n0.Exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			height=heightTree(root);
			printf("The height of the Binary Tree = %d\n",height);
			goto mainmenu;
		}
		else if(choice==2)
		{
			printf("\nInorder Traversal of the Binary tree:- ");
			inOrder(root);
			goto mainmenu;
		}
		else if(choice==3)
		{
			printf("\nPreorder Traversal of the Binary tree:- ");
			preOrder(root);
			goto mainmenu;
		}
		else if(choice==4)
		{
			printf("\nPostorder Traversal of the Binary tree:- ");
			postOrder(root);
			goto mainmenu;
		}
		else if(choice==5)
		{
			printTree(root);
			goto mainmenu;
		}
		else if(choice==0)
		{
			printf("\nExiting Program...\n");
			exit(1);
		}
		else
		{
			printf("\nInvalid Input, Please Try Again\n\n");
			goto mainmenu;
		}
}
