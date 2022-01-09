#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void insertatbeg(int);
void insertatend(int);
void bintodec();

struct node
{
	int data;
	struct node *next;
};
struct node *head;

//function to insert the number at the beginning
void insertatbeg(int num)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node*));
	if(newnode==NULL)
		printf("\nPushing element not allowed by Memory\n");
	else
	{
			newnode->data=num;
			newnode->next=head;
			head=newnode;
			printf("\nElement %d inserted at beginning of the List\n",num);
	}
}

//function to insert the number at the end of the linked list
void insertatend(int num)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node*));
	struct node *ptr;
	if(newnode==NULL)
		printf("\nPushing element not allowed by Memory\n");
	else
	{
		newnode->data=num;
		if(head==NULL)
		{
			newnode->next=NULL;
			head=newnode;
			printf("\nElement %d inserted to the List\n",num);
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=newnode;
			newnode->next=NULL;
			printf("\nElement %d inserted at end of the List\n",num);
		}
	}
}

//function with the formula to convert the binary to decimal
void bintodec()
{
	struct node *ptr;
	int len=0,i,result=0;
	if(head==NULL)
	{
		printf("\nList is Empty\n");
		exit(1);
	}
	ptr=head;
	while(ptr->next!=NULL)
	{
		len++;
		ptr=ptr->next;
	}
	ptr=head;
	for(i=len;i>=0;i--)
	{
		result= result + (ptr->data * (pow(2,i)));
		ptr=ptr->next;
	}
	printf("\n The equivalent decimal number is: %d \n", result);
}

//main driving function
void main()
{
	int choice=0,num;
	while(choice!=3)
	{
		MainMenu:
		printf("\nWelcome to Binary to Decimal Converter\n==================================== \n Enter Either of the following: \n1.Insert\n2.Convert Current List to Decimal\n3.Exit\n");
		fflush(stdin);
		scanf("%d",&choice);
		if(choice==1)
		{
			InsertMenu:
			printf("\nInsert Menu\n\nPlease enter either 0 or 1\nEnter 3 for previous menu\n");
			scanf("%d",&num);
			if(num==3)
			{
				goto MainMenu;
			}
			else if((num==0) || (num==1))
			{
				char ch;
				InsertDecide:
					printf("\nPress 'b' to insert %d to beginning of the list\nPress 'e' to insert %d at the end of the list\n",num,num);
					fflush(stdin);
					scanf("%c",&ch);
					{
						if((ch!='b') && (ch!='e'))
						{
							printf("\n Invalid Input. Retry \n");
							goto InsertMenu;
						}
						if(ch=='b')
							insertatbeg(num);
						if(ch=='e')
							insertatend(num);
					}
			}
			else
				{
					printf("\n Invalid Input. Retry \n");
					goto InsertMenu;	
				}
			
		}
		else if(choice==2)
		{
			bintodec();
		}
		else if(choice==3)
		{
			printf("\nExiting\n");
			break;
		}
		else
			printf("\nInvalid Input. Please try again\n");
	}
}
