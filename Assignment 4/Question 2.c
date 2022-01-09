#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct node  //creating a node
{
	int data;
	struct node *left;
	struct node *right;
};

	char s[1000]="(";
	struct node* arrnode[100];
	char arrchar[100];
	int arrchartop=-1,arrnodetop=-1;

struct node* createNode(int data) //creating a node with structure pointer
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
};

int characterPriority(char ch) //function that check for operator precedence
{
	if(ch=='(')
		return 0;
	else if(ch=='+' || ch=='-')
		return 3;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='^')
		return 1;
	else
		return -1;
}

struct node* createTree(char* str) //function that builds my binary tree for the given infix expression
{
  struct node* stackN[MAX];
	char stackC[MAX];
	struct node *t;
	struct node *t1;
	struct node *t2;
	int i,j=-1,k=-1;
	
	for(i=0;i<strlen(str);i++){
		if(str[i]=='('){
			stackC[++j]=str[i];
		}
		else
		if(isalpha(str[i]) || isalnum(str[i])){
			t=createNode(str[i]);
			stackN[++k]=t;
		}
		else
		if(characterPriority(str[i])>0){
			while(j!=-1 && str[j]!='(' && ((str[i]!='*' && characterPriority(stackC[j])>=characterPriority(str[i])) || (str[i]=='*' && characterPriority(stackC[j]) >characterPriority(str[i])))){
				t=createNode(stackC[j]);
				stackC[--j];
				
				t1=stackN[k];
				stackN[--k];
				
				t2=stackN[k];
				stackN[--k];
				
				t->left=t2;
				t->right=t1;
				stackN[++k]=t;
			}
			stackC[++j]=str[i];
		}
		else
		if(str[i]==')'){
			while(j!=-1 && stackC[j]!='('){
				t=createNode(stackC[j]);
				stackC[--j];
				
				t1=stackN[k];
				stackN[--k];
				
				t2=stackN[k];
				stackN[--k];
				
				t->left=t2;
				t->right=t1;
				stackN[++k]=t;
			}
			stackC[--j];
		}
	}
	t=stackN[k];
    return t;
}
		
		
int isOperator(char ch) //function to check whether a certain charcter is a valid operator or not
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')')
		return 1;
	return 0;
}


int checkInfix(char* str) // function to check if the given input string is a valid infix expression
{ 
	int i;
	for(i=0;i<strlen(str)-1;i++)
	{
		if((!isalnum(str[i])) && (!isalpha(str[i])) && (isOperator(str[i]) == 0))
			{
				return 1;
			}
		if(str[i]=='(' || str[i]==')')
			continue;
		int j=i;
		jiterate:
			j++;
			if(str[j]=='(' || str[j]==')') //ignores all braces 
				goto jiterate;
		if((isOperator(str[i]) && isOperator(str[j])) || (isalnum(str[i]) && isalnum(str[j])) || (isalpha(str[i]) && isalpha(str[j]))) //checks for repetition of operands or operators
			{
				printf("Invalid 2 at str : %c",str[i]);
				return 1;
			}
	}
	return 0;	
}

infixPostfix(struct node *root) //converts infix expression to postfix using binary expression tree
{  if (root){
        infixPostfix(root->left);
        infixPostfix(root->right);
        printf("%c",root->data);
    }
}


infixPrefix(struct node *root) //converts infix expression to prefix using binary expression tree
{  if (root){
		printf("%c",root->data);
        infixPrefix(root->left);
        infixPrefix(root->right);   
    }
}


void main()
{
	int i,choice, flag=-1;
	char str[MAX],ch[MAX]=")";
	mainmenu:
		printf("\nWelcome to Expression Converter Program\n--------------------------------------------\n1.Input a new Infix Expression with single digit numbers\n2.Check the Infix Expression\n3.Convert Infix to Postfix\n4.Convert Infix to Prefix\n0.Exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nEnter the Infix Expression\n");
			scanf("%s",str);
			strncat(s, str, strlen(str));
			strncat(s, ch, 1);
			printf("\nInfix Expression Updated as %s\n",s);
			goto mainmenu;
		}
		else if(choice==2)
		{
			struct node *root = createTree(s);
			flag=checkInfix(s);
			if(flag==0)
				printf("\n This is a correct/valid infix expression\n");
			else
			{
				printf("\nThis is an invalid Infix Expression \n");
			}
			
			goto mainmenu;
		}
		else if(choice==3)
		{
			if(flag==-1)
			{
				printf("\nKindly validate the Infix Expression First\n");
				goto mainmenu;
			}
			else if(flag==1)
			{
				printf("\nInvalid Infix Expression, Postfix Cannot be Performed\n");
			}
			else
			{
				struct node *root = createTree(s);
				infixPostfix(root);
				goto mainmenu;
			}
		}
		else if(choice==4)
		{
			if(flag==-1)
			{
				printf("\nKindly validate the Infix Expression First\n");
				goto mainmenu;
			}
			else if(flag==1)
			{
				printf("\nInvalid Infix Expression, Prefix Cannot be Performed\n");
				printf("\nInvalid Infix Expression, Prefix Cannot be Performed\n");
			}
			else
			{
				struct node *root = createTree(s);
				infixPrefix(root);
				goto mainmenu;
			}
			
		}
		else if(choice==0)
		{
			printf("\nExiting the Program...\n");
			exit(1);
		}
		else
		{
			printf("\nInvalid Input. Please Try Again\n");
			goto mainmenu;
		}
}

