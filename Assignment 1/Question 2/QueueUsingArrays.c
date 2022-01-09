////Implement Queue using Arrays

#include <stdio.h>
#include <stdlib.h>

#define max 100
void addelement();
void delelement();

int queue[max];
int front=-1, rear=-1, inputchoice=0;
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

//Code to add element to the Array	
void addelement()
{
	int insertvalue;
	if(rear==max-1)
		printf("Overflow Condition\n");
	else
	{
		printf("\n Enter value to be inserted to Queue: \n");
		scanf("%d",&insertvalue);
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
			rear=rear+1;
		queue[rear]=insertvalue;
	}
}


//Code to delete element from the Array
void delelement()
{
	if(front==-1 || front > rear)
		printf("\n Underflow Condition\n");
	else
	{
		printf("\n The deleted value is: %d \n", queue[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		front=front+1;
	}
}
