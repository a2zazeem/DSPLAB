////Implement Queue using LinkedLists

#include <stdio.h>
#include <stdlib.h>

#define max 100
void addelement();
void delelement();

struct node
{
	int data;
	struct node *next;
};

struct node *front;
struct node *rear;
int inputchoice=0;
void main()
{
	while(inputchoice!=3)
	{
		printf("\n Enter either: \n 1 for Enqueue \n 2 for Dequeue \n 3 to Exit\n");
		scanf("%d",&inputchoice);
		switch(inputchoice)
		{	
			case 1:
				{
					addelement();
					break;
				}
			case 2:
				{
					delelement();
					break;
				}
			case 3:
				{
					printf("Exiting Program");
					break;
				}
			default:  
                 	printf("Invalid Choice, Choose 3 to Exit Program \n");
                 	break;             	
		}
	}
}
	
//Code to add element to the LinkedList
void addelement()
{
	printf("Enter the element to be added: \n");
	int inputValue;
	scanf("%d",&inputValue);
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
			printf("Pushing element not allowed \n");
	else
	{
		newnode->data=inputValue;
		if(front==NULL)
		{
			front=newnode;
			rear=newnode;
			front->next=NULL;
			rear->next=NULL;
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
			rear->next=NULL;
		}
	}
}


//Code to delete element from the LinkedList
void delelement()
{
	struct node *ptr;
	int delValue;
	if(front==NULL)
		printf("\n Underflow Condition\n");
	else
	{
		printf("\n The deleted value is: %d \n", front->data);
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
		}
		else
		{
			ptr=front;
			front=front->next;
			free(ptr);
		}
	}
}
