#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

	struct node *head;
	struct node *ptr;
	struct node *head1;
	struct node *head2;
	int size,i,l,r;

void addnode(int val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *ptr=head;
	if(newnode==NULL)
	{
		printf("\nMemory not allocated to new node\n");
		exit(1);
	}
	
	newnode->data=val;
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
	}
	else
	{
		while(ptr->next!=head)
			ptr=ptr->next;		
		ptr->next=newnode;
		ptr=newnode;
		ptr->next=head;
	}
}


//splits my circular linked list into two halves
void split()
{
	if(head==NULL)
	{
		printf("\nLinked List is empty\n");
		exit(1);
	}
	head1=head;
	ptr=head1;
	printf("ptr=%d",ptr->data);
	if(size%2!=0)
	{
		for(i=1;i<=size/2;i++)
		ptr=ptr->next;
	}
	else
	{
		for(i=1;i<size/2;i++)
			ptr=ptr->next;
	}
	printf("ptr=%d",ptr->data);
	head2=ptr->next;
	ptr->next=head1;
	ptr=head2;
	for(i=1;i<size/2;i++)
		ptr=ptr->next;
	ptr->next=head2;
}


//function to diplay the two circular singley linked lists
void display()
{
	if(head==NULL)
	{
		printf("\nLinked List is empty\n");
		exit(1);
	}
	printf("\n First Node: \t");
	ptr=head1;
	do
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head1);
	
	printf("\n Second Node: \t");
	ptr=head2;
	do
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head2);
}

void main()
{
	int choice=-1;
	int val;
	
	while(choice!=0)
	{
		mainmenu:
		printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert the linked list elements\n2.Split the Linked List\n3.Display\n0.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice); 
        if(choice==1)
        {
        	printf("\nEnter the size of the linked list\n");
        	scanf("%d",&size);
        	printf("\nEnter the elements of the linked list\n"); 
			for(i=0;i<size;i++)
			{
				scanf("%d",&val);
				if(isalnum(val)!=1) // exception validation for number inputs
				addnode(val);  // adds all nodes to the linked list
				else
				{
					printf("\nIncorrect Input\n");
					goto mainmenu;
				}
			}
			printf("\nElements added.\n");
		}
        else if(choice==2)
        {
        	split(); // splits the list into two halves.
		}
		else if(choice==3)
			display(); // Displays both the linked lists.
		else if(choice==0)
			printf("\nExiting..\n"); // Exits program
		else
			{
				printf("\nInvalid Input\n");  // Exception
				exit(1);
			}
	}
}
