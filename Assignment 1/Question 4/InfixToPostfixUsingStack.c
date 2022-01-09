//Infix to Postfix using Stack

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct node{
	char data;
	struct node *next;
};
struct node *head = NULL;
int flag;

//code to push elements into stack while converting infix to postfix
void push(char ch)
{
	char c=ch;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=c;
	newnode->next=head;
	head=newnode;
}

//code to pop elements from stack while converting infix to postfix
char pop()
{
	struct node *ptr;
	char ch;
	if(head==NULL)
	{
		printf("Stack Empty");
	}
	else
	{
		ptr=head;
		ch=ptr->data;
		head=head->next;
		ptr->next=NULL;
		free(ptr);
	}
	return ch;
}

//function created to check for precedence of the operand
int characterPriority(char ch)
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

//function to calculate the postfix expression and return the final result
int postfixcalculator(char evalexp[])
{
	int s[strlen(evalexp)];
	int flag=0,top=-1,i=0,a,b;
	char ch;
	int postfixpop()
	{
		return s[top--];
	}
	void postfixpush(int num)
	{
		if(flag==0)
		{
			s[++top]=num;
			flag=1;
		}
		else
		{
			int n=num+10*(postfixpop());
		s[++top]=n;
		}
	}
	while((ch=evalexp[i++]) != '\0')
	{
		if(isalnum(ch))
		{
			postfixpush(ch-'0');
		}
		else if(ch==' ')
			flag=0;
		else
		{
			
			flag=0;
			a=postfixpop();
			b=postfixpop();
			switch(ch)
			{
				case'+':postfixpush(b+a); break;
				case'-':postfixpush(b-a); break;
				case'*':postfixpush(b*a); break;
				case'/':postfixpush(b/1); break;
				case'^':postfixpush(pow(b,a)); break;
				default: printf("Incorrect Input"); return 0;
			}
		}
	}
return postfixpop();
}



void main()
{
	char expression[50];
	char *ptr, x;
	printf("\n Enter the Expression: \n");
	scanf("%s",expression);
	ptr=expression;		
	int count=0;
	char evalexp[100]="";
	int k=0;
	printf("The Postfix Expression is:");
	while(*ptr != '\0')
	{
		if(isalnum(*ptr))
		{
			printf("%c",*ptr);
			evalexp[k++]=*ptr;			
		}
		
		else
		{
			push(' ');
			evalexp[k++]=' ';
			if(*ptr=='(')
			{
				push(*ptr);
			}
			else if(*ptr==')')
			{
				while((x=pop()) != '(')
				{
					printf("%c",x);
					evalexp[k++]=x;
				}
			}
			else
			{
				if(head==NULL)
				{
					push(*ptr);
				}
				else
				{
					while(characterPriority(head->data) >= characterPriority(*ptr) )
					{
						printf("here");
						printf("%c",x=pop());
						evalexp[k++]=x;
					}
				push(*ptr);
			}
		}
	}
		ptr=ptr+1;
 }

	while(head!=NULL)
	{
		x=pop();
		printf("%c",x);
		evalexp[k++]=x;
	}
	
	printf("\n EVAL EXP: \n %s",evalexp);
	printf("\n EVALUATED RESULT: \n %d",postfixcalculator(evalexp));
		
}
