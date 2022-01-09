#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MAX=100000;
int arr[100000];

//function to perform the parition operation
int partition(int arr[], int p, int q){
	int x,i,j,temp;
	x=arr[p];
	i=p;
	
	for(j=p+1;j<=q;j++){
		if(arr[j]<=x){
			i=i+1;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	
	temp=arr[p];
	arr[p]=arr[i];
	arr[i]=temp;
	return i;
}

//function to take any random element from the array as pivot element
int piv_create(int arr[], int p, int r)
{	int temp;
    int rnd = p + rand() % (r - p);
 
    temp=arr[rnd];
	arr[rnd]=arr[r];
	arr[r]=temp;
 
    return partition(arr, p, r);
}

//function to implement quicksort
int quicksort(int arr[],int p,int r){
	int q,i;
	if(p<r){
		q=piv_create(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

//main function 
int main()
{	
	FILE* fp;	
	int i,choice,temp,p;
	clock_t t1,t2;
	
	printf("\nWelcome to Quicksort Implementation \n");
	printf("\n-------------------------------------------------------------");
	
	menu:
	printf("\nChoose from below:");
	printf("\n1.Take random input");
	printf("\n2.Take sorted input");
	printf("\n3.Take sorted with 1%% as random input");
	printf("\n4. Exit\n");
	scanf("%d",&choice);
	printf("\nEnter the value of n:\n");
	scanf("%d",&MAX);
	
	ch:
		if(choice == 1)
		{
			fp = fopen("random_input.txt","r");
			for(i=0 ; i<MAX ; i++){
 		   	fscanf(fp,"%d",&arr[i]);
			}
		}
		else 
		if(choice == 2)
		{
			fp = fopen("sorted_input.txt","r");
			for(i=0 ; i<MAX ; i++){
 		   	fscanf(fp,"%d",&arr[i]);
			}
		}
		else 
		if(choice == 3)
		{
		
			fp = fopen("sorted_input.txt","r");
			for(i=0 ; i<MAX ; i++)
			{
 		   		fscanf(fp,"%d",&arr[i]);
			}
	
			p = MAX/100;
			for(i=0;i<p;i++)
			{
				temp = arr[i];
				arr[i]  = arr[p+i];
				arr[p+i] = temp;
			}	
		
		}
		else 
		if(choice == 4){
			exit(1);
		}
		else{
			printf("\nInvalid choice!!");
			goto ch;
		}
    
    t1=clock();	
    
    quicksort(arr,0,MAX-1);
	
	printf("\nAfter sorting:-");
	for(i=0;i<MAX;i++)
	{
		printf("%d ",arr[i]);
	}
	
	t2=clock();	
	double total_time=((double)(t2 -t1))/CLOCKS_PER_SEC;
    printf("\n\nTotal time of execution  = %f, when array size = %d\n", total_time, MAX);
    
	printf("\n");
	fclose(fp);
	goto menu;
	return 0;
}
