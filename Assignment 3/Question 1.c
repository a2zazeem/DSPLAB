#include <stdio.h>
#include <stdlib.h>

void insertelement(int arr[], int front[], int rear[], int next[], int* fre, int k, int qn)
{
	int item,j;
	int n=k*10;
	if(qn>k)
	{
		printf("\nInvalid Queue Number\n");
		return;
	}
	printf("\n Enter the element to be inserted\n");
	scanf("%d",&item);
	if (*fre == -1)
    {
        printf("\nQueue Overflow\n");
        return;
	}
    int i = *fre;      // Store index of first free slot
    *fre = next[i];
    if (front[qn] == -1)
        front[qn] = i;
    else
        next[rear[qn]] = i;
    next[i] = -1;
    rear[qn] = i;  // Update the next of rear and then rear for queue qn
    arr[i] = item;
	  // Adding the item in array
   /* for(i=0;i<n;i++)   // Prints my current arrays.
			{
				printf("arr: %d \n",arr[i]);
			}
	for(i=0;i<n;i++)
			{
				printf("next: %d \n",next[i]);
			}
	for(i=0;i<k;i++)
			{
				printf("front: %d \n",front[i]);
			}
	for(i=0;i<k;i++)
			{
				printf("rear: %d \n",rear[i]);
			}*/
}
// Function to delete the elements from the queue with maximum number of elements
int deleteelement(int arr[], int front[], int next[], int* fre, int qn)
{
	if(front[qn] == -1)
	{
		printf("\n Underflow \n");
		return;
	}
	int i= front[qn];
	front[qn]=next[i];
	next[i]=*fre;
	*fre=i;
	int num =arr[i];
	arr[i]=0;
	return num;
}

//main driving function
void main()
{
	int choice=-1,k,qn;
	printf("\n Enter the number of queues to be implemented\n");
	scanf("%d",&k);	
	int i=0,n;
	int front[k];
	int rear[k];
	n=k*10;
	int arr[n];
	int fre=0; //indicates all spaces are free
	int next[n];
	while(i<k)
	{
		front[i]=-1;
		i++;
	}
	i=0;
	while(i<n-1)
	{
		next[i]=i+1;
		i++;
	}
	next[n-1]=-1;
	for(i=0;i<n;i++)
		arr[i]=0;
		mainmenu:
	while(choice!=0)
	{
		printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Enqueue \n2.Insert Operation \n3.Delete Operation \n4.Display all \n 5.Display Nexts\n0.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice); 
        if(choice==1)
        {      	
			printf("\n Enter the queue number where element to be inserted\n");
			scanf("%d",&qn);
			qn--;
        	insertelement(arr,front,rear,next,&fre,k,qn);
		}
        else if(choice==2)
        {
        	
        	int min=101;
        	for(i=0;i<k;i++)
        	{
        		if(min>(rear[i]-front[i]+1))
        		{
        			min=rear[i]-front[i]+1;
        			qn=i;
				}
			}
			insertelement(arr,front,rear,next,&fre,k,qn);
		}
		else if(choice==3)
		{
			int max=-1;
        	for(i=0;i<k;i++)
        	{
        		if((max<(rear[i]-front[i]+1))&& rear[i]!=-1) 
        		{
        			max=rear[i]-front[i]+1;
        			qn=i;
				}
			}
			printf("\n Element : %d has been deleted from the queue : %d \n",deleteelement(arr,front,next,&fre,qn),qn+1);
			
		}
		else if(choice==4)
		{	int j,num;
			printf("\nDisplaying all the queues in the array:\n");
			for(i=0;i<k;i++)
			{	
				printf("\n Queue: %d \n",i+1);
				if(front[i]==-1)
				{
					printf("\nQueue not created yet\n");
					continue;
				}
				printf("\n front of queue %d = %d and rear of queue %d = %d\n",i+1,front[i],i+1,rear[i]);
				num=front[i];
				while(num!=-1)
				{
					printf("%d\n",arr[num]); // Prints all the elements in every queue
					num=next[num];
				}
			}
			
		}
		else if(choice==5)
		{
			printf("\n Next : \n");
          	for(i=0;i<n;i++)
          	{
          		printf(" %d", next[i]); // Prints all the values in my Next array
			}
		}
		else if(choice==0)
		{
			printf("\n Exiting .. \n");
			exit(1);
		}
		else
			printf("\n Invalid Input \n");
	}
}



