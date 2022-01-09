#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	char name[50];
	int score;
};
struct student s[100];
int front=-1, rear=-1, pos=-1;


void insert()
{
	char name[50];
	int score;
	printf("\nEnter the name of the student\n");
	scanf("%s",name);
	enterscore:
	printf("\nEnter the gate score\n");
	scanf("%d",&score);
	if(score<0 && score>100)
	{
		printf("\nInvalid Score\n");
		goto enterscore;
	}
	if(rear>=100)
	{
		printf("\nOverflow\n");
		return;
	}
	pos=rear++;
	while((pos>=0) && (s[pos].score>=score))
	{
		s[pos+1].score=s[pos].score;
		strcpy(s[pos+1].name,s[pos].name);
		pos--;
	}
	s[pos+1].score=score;
	strcpy(s[pos+1].name,name);
	if(front==-1)
		front++;
		
	printf("\nData inserted into the Queue with name: %s and score: %d at position: %d\n",s[pos+1].name,s[pos+1].score,pos+1);
}


void removerecord()
{
	if(front>=rear)
	{
		printf("\nUnderflow\n");
		exit(1);
	}
	printf("\nSuccessfully deleted the record: \n Name: %s \n Gate Score: %d\n",s[front].name,s[front].score);
	s[front].score=0;
	front++;
	printf("\nFront is now at: \n Name: %s \n Gate Score: %d\n",s[front].name,s[front].score);
	
}

void display()
{
	int ptr=front;
	printf("\n Name:  \t Gate Score:");
	while(ptr<=rear)
	{
		printf("\n %s \t %d ",s[ptr].name,s[ptr].score);
		ptr++;
	}
}

void main()
{
	int choice=-1;
	mainmenu:	
	while(choice!=0)
	{
		printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert Data\n2.Delete Data\n3.Display current Queue\n0.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice); 
        if(choice==1)
        {
        	insert();
        	goto mainmenu;
		}
		if(choice==2)
		{
			removerecord();
			goto mainmenu;
		}
		if(choice==3)
		{
			display();
			goto mainmenu;
		}
}
}
