#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
	char info[3][40];
	struct node *link;
};
//initialising head pointer for my linked list
struct node *head;
int nodecount=0;

//function to display the whole list
void displayall()
{
	struct node *ptr;
	ptr=head;
	printf("\nThe list has the following elements:\n");
	do
	{
		printf("%s ",ptr->info[0]);
		printf("%s ",ptr->info[1]);
		printf("%s",ptr->info[2]);
		ptr=ptr->link;
		printf("\n");
	}while(ptr!=head);	
}

//function to display second string only
void displaysecondonly()
{
	struct node *ptr;
	char ch;
	int i;
	ptr=head;
	printf("\nThe list has the following second elements:\n");
	do
	{
		printf("\n%s\n",ptr->info[1]);
		ptr=ptr->link;
	}while(ptr!=head);
}

//function to check the string rule
void checkstring()
{
	struct node *ptr;
	int flag=0;
	int i;
	ptr=head;
	if(head==NULL)
	{
		printf("\nLinked List is empty\n");
		exit(1);
	}
	do
	{
		if(strcmp(ptr->info[2],ptr->link->info[0]) != 0)
		{
			printf("\nThe element %s does not match with %s in the node",ptr->info[2],ptr->link->info[0]);
			flag=1;
		}
		ptr=ptr->link;
	}while(ptr!=head);
	if(flag==0)
		printf("\nString match sucessful\n");
	else
		printf("\nString not Matching\n");
}

//function to replace the string of any node
void replacenodestring() //nodecount
{
	int i,nodenumber;
	int choice;
	struct node *ptr;
	printf("\nEnter the node number you want to replace the string of:\n");
	scanf("%d",&nodenumber);
	if((nodenumber>nodecount) || (nodenumber<1)) //Exception checked
	{
		printf("\nNode does not exist\n");
		return;
	}
	else
	{	
		ptr=head;
		for(i=1;i<nodenumber;i++)
		{
			ptr=ptr->link;
		}
		stringreplacechoice:
		printf("\nChoose which string you want to change:\nPress 1 for first\nPress 2 for second\nPress 3 for third\nPress 4 to go to mainmenu\n");
		scanf("%d",&choice);
		if(choice==4)
			return;
		else if(choice>=1 && choice<=3)
		{	
			printf("\nEnter the string:\n");
			scanf("%s",ptr->info[choice-1]);
		}
		else
		{
			printf("\nInvalid Choice\n"); //exception 
			goto stringreplacechoice;
		}
	}
	printf("\nString has been replaced to 'color' in the node %d and column %d.\n",nodenumber,choice);
}

//function to add a new node to the linkedlist
void addnode()
{
	int i;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory not allocated to new node\n");
		exit(1);
	}
	printf("\nEnter the three string elements for the node\n");
	nodecount++;
	for(i=0;i<3;i++)
	{
		scanf("%s",newnode->info[i]); 
	}
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		head=newnode;
		head->link=head;
	}
	else
	{
		while(ptr->link!=head)
		ptr=ptr->link;		
		ptr->link=newnode;
		ptr=newnode;
		ptr->link=head;
		printf("\nElements added to the node %d.\nChecking for string match rule\n",nodecount);
		checkstring();
	}
}


//main driving function
void main()
{	
	int choice = -1, pos, value;
	printf("\nThis is the implementation of Linked List in C \n");
	mainmenu:
	while(choice!=0)
	{
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert the node\n2.Display all nodes\n3.Display only second integer of all nodes\n");
		printf("4.Replace string Values\n5.To Validate String Match Rule\n0.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice); 
        if(choice==1)
        {
        	printf("\nchoice is 1\n");
			addnode();
			goto mainmenu;
		}
		else if (choice==2)
		{
			
			displayall();
			goto mainmenu;
		}
		else if (choice==3)
		{
			displaysecondonly();
			goto mainmenu;
		}
		else if (choice==4)
		{
			replacenodestring();
			goto mainmenu;
		}
		else if (choice==5)
		{
			checkstring();
			goto mainmenu;
		}
		else if (choice==0)
		{
			printf("\nExiting Program\n");
			exit(1);
		}
		else
		{
			printf("\nInvalid Input, Try Again\n");
			goto mainmenu;
		}
}}









