#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int level1count=0,i,maxfreq=INT_MIN;

struct node{
    char data[100];
	int intdata;
    struct node *child;
    struct node *sibling;
};

struct node *createNode(char *data) //creating a node with structure pointer
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	strcpy(n->data,data);
	n->intdata=1;
	n->child=NULL;
	n->sibling=NULL;
		return n;
};

//function to check if the category that is input by the user is already present or not
int checkl1(char *category, struct node *root)
{
	struct node *t1=root->child;
	while(t1!=NULL)
	{
		if (strcmp(t1->data,category)==0)
		{
			printf("\n Category Already Exists\n");
			return 1;
		}
		t1=t1->sibling;
	}
	return 0;
}

////function to print the depth of a node
int nodedepth(struct node *root,char *inputstring)
{
	if(strcmp(root->data,inputstring)==0)
		{
			printf("\n Depth is 0 \n");
			return 1;	
		}
	struct node *t1=root->child;
	struct node *ptr=t1;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->data,inputstring) == 0)	
		{
			printf("\n Depth is 1 \n");
			return 1;
		}
		else
		{
			struct node *t2=ptr->child;
			struct node *ptr2=t2;
			while(ptr2!=NULL)
			{
				if(strcmp(ptr2->data,inputstring)== 0)
				{
					printf("\n Depth is 2 \n");
					return 1;
				}
				ptr2=ptr2->sibling;
			}
		}
		ptr=ptr->sibling;
	}
	return 0;
}		

//gets the count of the number of child of a given node.
void getchildcount(struct node *ptr)
{
	int count=1;
	if(!ptr->child)
	{
		printf("\n Degree of the node is 0, as it is leaf node\n");
	}
	else
	{
		struct node *ptr2=ptr->child;
		while(ptr2->sibling!=NULL)
		{
			count++;
			ptr2=ptr2->sibling;
		}
		printf("\n Degree of the node is %d .\n",count);
	}
}

//function to print the degree of a node
int nodedegree(struct node *root,char *inputstring)
{
	if(strcmp(root->data,inputstring)==0)
		{
			getchildcount(root);
			return 1;	
		}
	struct node *t1=root->child;
	struct node *ptr=t1;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->data,inputstring) == 0)	
		{
			getchildcount(ptr);
			return 1;
		}
		else
		{
			struct node *t2=ptr->child;
			struct node *ptr2=t2;
			while(ptr2!=NULL)
			{
				if(strcmp(ptr2->data,inputstring)== 0)
				{
					getchildcount(ptr2);
					return 1;
				}
				ptr2=ptr2->sibling;
			}
		}
		ptr=ptr->sibling;
	}
	return 0;
}

//function to print all the words in decreasing order of their frquency
printDesc(struct node *root)
{
	for(i=maxfreq;i>1;i--) 
	{
		struct node *t1=root->child;
		while(t1!=NULL) 
		{
			
			if(t1->child)
			{
				struct node *t2=t1->child; 
				while(t2!=NULL)
				{
					
					if(t2->child)
					{
						int temp=t2->child->intdata;
						if(temp==i)
							printf("\n For frequency: %d the Word is: %s",i,t2->data);
					}
				t2=t2->sibling;
				}
			}
		t1=t1->sibling;
		}	
	}
	//print 1 freq words here
	struct node *t1=root->child;
	while(t1!=NULL)
	{
		if(t1->child!=NULL)
		{
			struct node *t2=t1->child;
			while(t2!=NULL)
			{
				if(t2->child==NULL)
					printf("\n For frequency: 1 the Word is: %s",t2->data);
				t2=t2->sibling;
			}
		}
	t1=t1->sibling;
	}
}

//main driving function
void main()
{
	int choice,start=0;
	char category[100],inputword[100];
	struct node *root=createNode("Words");
	struct node *t1=createNode("Words");
	root->child=t1;
	printf("\nWelcome to Binary Search Tree Program\n=====================================================\nEnter one of the below choices\n");
	mainmenu:
		printf("\n1: Add a category \n2: Input the words for the respective category");
		printf("\n3: To Display leaf nodes \n4:Find the depth of any node \n5: Get Degree of any node \n6: Display the words in frequency descending order \n0: Exit \n");
		scanf("%d",&choice);
	if(choice==1)
	{	
		categoryinput:
		printf("\nEnter the category:\n");
			scanf(" %[^\n]%*c",category); //input the category
			if(start==0)
			{
				strcpy(t1->data,category);
				start++;			 
			}
			else
			{
				if(checkl1(category,root)==1)
				{
					goto categoryinput;
				}
				struct node *newnode=createNode(category);//create a node on every new category
				struct node *ptr=t1;
				while(ptr->sibling!=NULL)
					ptr=ptr->sibling;
				ptr->sibling=newnode;
			}
			printf("\nCategory Added\n");
			level1count++;
	}
	else if(choice==2)
	{
		
		struct node *ptr=t1;
		if(level1count==0)
		{
			printf("\n No Category Available\n");
			goto mainmenu;
		}
		printf("\n Choose from one of the below available categories:\n");
		for(i=1;i<=level1count;i++)
		{
			printf("%d. %s\n",i,ptr->data);
			ptr=ptr->sibling;
		}
		scanf("%d",&choice);
		if(choice>level1count || choice <0)
		{
			printf("\nInvalid choice, Retry\n");
			goto mainmenu;
		}
		ptr=t1;
		for(i=1;i<choice;i++)
		{
			ptr=ptr->sibling;
		}
		printf("\nEnter the word for the category: %s\n",ptr->data);
		scanf("%s",inputword);
		if(ptr->child==NULL)
		{
			struct node *newnode=createNode(inputword);
			ptr->child=newnode;	
		}
		else
		{
			struct node *t2=ptr->child;
			struct node *ptr2=t2;
			int flag=0;
			while(ptr2!=NULL)
			{
				if(strcmp(ptr2->data,inputword)==0) // word found inside the category selected.
				{
					flag=1;
					if(ptr2->child==NULL)
					{
						struct node *newnode=createNode("");
						newnode->intdata=2;
						ptr2->child=newnode;
					}
					else
					{
						int temp=ptr2->child->intdata;
						temp++;
						ptr2->child->intdata=temp;
						if(temp>maxfreq)
							maxfreq=temp;
					}
				}
				ptr2=ptr2->sibling;
			}
			if(flag==0)
			{
				ptr2=t2;
				while(ptr2->sibling!=NULL)
					ptr2=ptr2->sibling;
				struct node *newnode=createNode(inputword);
				ptr2->sibling=newnode;
			}
		}

	}

	else if(choice==3)
	{
		struct node *t1=root->child;
		struct node *ptr=t1;
		while(ptr!=NULL)
		{
			if(ptr->child==NULL)
			{
				printf("%s \n",ptr->data);
			}
			else
			{
				struct node *t2=ptr->child;
				struct node *ptr2=t2;
				while(ptr2!=NULL)
				{
					if(ptr2->child==NULL)
						printf("%s\n",ptr2->data);
					ptr2=ptr2->sibling;
				}
			}
			ptr=ptr->sibling;
		}
	}

	else if(choice==4)
	{
		char inputstring[100];
		printf("\nEnter the string of the node\n");
		scanf("%s",inputstring);
		int flag=0;
		flag=nodedepth(root,inputstring);
		if(flag==0)
			printf("\nThe input string does not match with any node in the tree\n");
	}

	else if(choice==5)
	{
		char inputstring[100];
		printf("\nEnter the string of the node\n");
		scanf("%s",inputstring);
		int flag=0;
		flag=nodedegree(root,inputstring);
		if(flag==0)
			printf("\nThe input string does not match with any node in the tree\n");
	}
	else if(choice==6)
	{
		printDesc(root);
		goto mainmenu;
	}
	else if(choice==0)
	{
		printf("\n Exiting.. \n");
		exit(1);
	}
	else
	{
		printf("\nInvalid Input. Try again\n");
		goto mainmenu;
	}
	goto mainmenu;
}
		

