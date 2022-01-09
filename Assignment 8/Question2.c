#include<stdio.h>
#include<stdlib.h>

int MAX, prime;

//function to calculate the prime number that will be used in the hkey2 for double hashing
void getprime()
{
	int num=MAX;
	int flag;
	while(num>0)
	{
		flag=0;
		int m = num/2,i;
		for(i=2;i<=m;i++)
		{
			if(num%i==0)
				flag=1;
		}
		
		if(flag==0)
		{
			prime=num;
			break;
		}
		else
		{
			num--;
		}
	}
	
}
//function to insert the values into the hashtable
void insertValue(int arr[])
{
	int key, index, i,hkey,hkey2,flag=0;
	printf("\nEnter the value to be inserted in the hash table\n");
	scanf("%d",&key);
	hkey=key%MAX;
	hkey2=prime - (key % prime);
	
	for(i=0;i<MAX;i++)
	{
		index=(hkey+(i * hkey2))%MAX;
		int temp=arr[index];
		if(temp==0 || temp==-1)
		{
			arr[index]=key;
			temp=arr[index];
			break;
		}
		
	}
	
	if(i==MAX)
	{
		printf("\nCannot insert this item, The hashing function could not find a suitable location in the hashtable\n");
		return;
	}
}

//function that returns loadfactor of the hashtable
float loadfact(int arr[])
{
	int n=0, i;
	for(i=0;i<MAX;i++)
	{
		if(arr[i]>0)
		{
			n++;
		}
	}
	return (float)n/(float)MAX;
}

//function to search a value in the hashtable
void searchValue(int arr[])
{
	int key, index,i,hkey2, flag=0,hkey;
	printf("\nEnter the element to be searched in the hash table\n");
	scanf("%d",&key);
	hkey=key%MAX;
	hkey2=prime - (key % prime);
		
	for(i=0;i<MAX;i++)
	{
		index=(hkey+(i * hkey2))%MAX;
		int temp=arr[index];
		if(temp==key)
		{
			printf("\nValue found at index %d",index);
			break;
		}
	}
	if(i==MAX)
	{
		printf("\nElement does not exist in the hashtable\n");
		return;
	}
}

//function to dusplay all the elements of the hashtable
void display(int arr[])
{
	int i;
	for(i=0;i<MAX;i++)
	{
		printf("\nIndex %d value %d",i, arr[i]);	
	}	
}

//function to search and delete a value from the hashtable and replace it by -1
void deleteValue(int arr[])
{
	int key, index,i, hkey2, flag=0,hkey;
	printf("\nEnter the element to be deleted in the hash table\n");
	scanf("%d",&key);
	hkey=key%MAX;
	hkey2=prime - (key % prime);
	
	for(i=0;i<MAX;i++)
	{
		index=(hkey+(i * hkey2))%MAX;
		int temp=arr[index];
		if(temp==key)
		{
			arr[index]=-1;
			printf("\nValue found at index %d and has been deleted",index);
			break;
		}
	}
	if(i==MAX)
	{
		printf("\nElement does not exist in the hashtable\n");
		return;
	}
}

//main driving function
void main()
{
	
	int choice,i;
	printf("\nWelcome to the hashtable \n");
	printf("\nEnter the size of the array\n");
	scanf("%d",&MAX);
	int arr[MAX];
	for(i=0;i<MAX;i++)
	{
		arr[i]=0;
	}
	
	getprime();
	
	mainmenu:
	printf("\nChoose one of the below options, to perform the respective operations\n");
	printf("\n-------------------------------------------------------------------------------------------\n");
	printf("\n1. Insert element to the hash table\n2. Search an element from the hash table. \n3. Delete an element from the hashtable. \n4. Display the full hashtable. \n5. Calculate load factor of the hash table\n6. Exit \n");
	scanf("%d",&choice);
	if(choice==1)
	{
		insertValue(arr);
		goto mainmenu;
	}
	else if(choice==2)
	{
		searchValue(arr);
		goto mainmenu;
	}
	else if(choice==3)
	{
		deleteValue(arr);
		goto mainmenu;
	}
	else if(choice==4)
	{
		display(arr);
		goto mainmenu;
	}
	else if (choice==5)
	{
		float lf=loadfact(arr);
		printf("\nLoad Factor= %f",lf);
		goto mainmenu;
	}
	else if(choice==6)
	{
		printf("\nExiting..\n");
		exit(1);
	}
	else
	{
		printf("\nInvalid choice, Please try again...\n");
		goto mainmenu;
	}
}
