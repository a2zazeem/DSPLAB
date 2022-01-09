#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
int MAX=100000;
int arr[100000];

//function to merge the subarrays
void merge(int a[],int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int left[n1+1], right[n2+1];
	int i,j,k;
	
	for(i=1;i<=n1;i++)
	{
		left[i]=a[p+i-1];
	}
	for(j=1;j<=n2;j++)
	{
		right[j]=a[q+j];
	}
	left[n1+1] = INT_MAX;
	right[n2+1] = INT_MAX;
	
	i=1;
	j=1;
	
	for(k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
	}	
}

//function to perform merge sort
int mergeSort(int a[],int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
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
	
	mergeSort(arr,0,MAX-1);
	
	printf("\nSorted array :\n");
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
