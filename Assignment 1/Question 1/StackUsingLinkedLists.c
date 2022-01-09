//Implement Stack using Linked Lists

#include <stdio.h>
#include <stdlib.h>

int inputchoice=0;
void push();
void pop();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *head;


void main()
{
	while(inputchoice!=4)
	{
		printf("Enter either: \n 1 for Push \n 2 for Pop \n 3 to Display \n 4 to Exit \n");
		scanf("%d",&inputchoice);
		switch(inputchoice)
		{	
			case 1:
				{
					push();
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					printf("Exiting Program");
					break;
				}
			default:  
                 	printf("Invalid Choice, choose 4 to Exit Program \n");
                 	break;             	
		}
	}
}
	

//Code to push element to the LinkedList
void push()
	{
		int inputvalue;
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==NULL)
			printf("Pushing element not allowed");
		else
		{
			printf("Enter the value to be pushed into stack\n");
			scanf("%d",&inputvalue);
			
				newnode->data=inputvalue;
				newnode->next=head;
				head=newnode;
		}
	}


//Code to delete element from the LinkedList
void pop()
{
	printf("Initiating POP Operation \n");
	struct node *popptr;
	if(head == NULL)
		printf("Stack Empty");
	else
	{
		popptr=head;
		head=head->next;
		free(popptr);
	}	
}


//Code to display all element of the LinkedList
void display()
{
	struct node *displayptr;
	if(head==NULL)
		printf("Stack Empty");
	else
	{
		printf("Displaying Stack\n");
		displayptr=head;
		while(displayptr != NULL)
		{
			printf("\n %d \n",displayptr->data);
			displayptr=displayptr->next;
		}
	}
}
