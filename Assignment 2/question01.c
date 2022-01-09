#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int inputchoice=0;
void push(char);
char pop();
struct node
{
	int data;
	struct node *next;
};
struct node *head;


int main()
{
	int len, open_count=0, close_count=0, flag=0;
	char str[100];
	char *ptr,check;
	printf("\nEnter the string\n");
	fflush(stdin);
	gets(str);
	ptr=str;
	while(*ptr != '\0')
	{
		if((*ptr == '{') || (*ptr == '[') || (*ptr == '('))
		{
			open_count++;
			push(*ptr);
		}
		else if((*ptr == '}') || (*ptr == ']') || (*ptr == ')'))
		{
			close_count++;
			check=pop();
			if( ( ( *ptr=='}' ) && ( check!='{' ) ) || ( ( *ptr == ']' ) && ( check!='[' ) ) || ( ( *ptr == ')' ) && ( check!='(' ) ))
			{
				flag = 1;
			}
		}
		else
		{
			printf("\nInvalid Input String\n");
			exit(1);
		}
		ptr++;
	}
	if(open_count != close_count)
	{
		flag = 1;
	}
	if(flag==0)
		printf("True");
	else
		printf("False");
	return 0;
}

//Code to push element to the LinkedList
void push(char inputvalue)
	{
		struct node *newnode=(struct node*)malloc(sizeof(struct node*));
		if(newnode==NULL)
			printf("Pushing element not allowed");
		else
		{			
				newnode->data=inputvalue;
				newnode->next=head;
				head=newnode;
		}
	}


//Code to delete element from the LinkedList
char pop()
{
	char ch;
	struct node *popptr;
	if(head == NULL)
		printf("Stack Empty");
	else
	{
		popptr=head;
		head=head->next;
		ch=popptr->data;
		free(popptr);
		return ch;
	}	
}


