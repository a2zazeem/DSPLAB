#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr1[MAX],*arr2;

//function to construct max heap
void max_heapify(int arr[], int i, int heapsize)
{	
	int temp, largest, l, r;
	l = (2*i + 1);
	r = (2*i + 2);
	largest = i;
	
	if(l<heapsize && arr[l]>arr[i])
		largest = l;
	if(r<heapsize && arr[r]>arr[largest])
		largest = r;
	if(largest != i){
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,largest,heapsize);
	}		
}

int *buildMaxHeap(int arr[], int items)
{
	int heapsize = items;
	int j;
	for(j = items/2; j>=0; j--){
		max_heapify(arr,j,heapsize);
	}
	return arr;
}

void insert_max(int element, int items)
{
	int parent;
	while(items>0){
		parent = (items-1)/2;
		if(element<=arr1[parent]){
			arr1[items]=element;
			return;
		}
		arr1[items]  = arr1[parent];
		items = parent;
	}
	arr1[0] = element;
}

void delete_max(int arr[],int items)
{
	int last = arr[items-1];
	arr[0] = last;
	items=items-1;
	max_heapify(arr,0,items);
}

void heapsort_max(int arr[],int items)
{
	int i,temp;
	
	for(i=items/2-1; i>=0; i--)
		max_heapify(arr,i,items);
	for(i=items-1; i>0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		max_heapify(arr,0,i);
	}	
}

void min_heapify(int arr[], int i, int heapsize)
{
	int temp, smallest, l, r;
	l = (2*i +1);
	r = (2*i + 2);
	smallest = i;
	
	if(l<heapsize && arr[l]<arr[i])
		smallest = l;
	if(r<heapsize && arr[r]<arr[smallest])
		smallest = r;
	if(smallest != i){
		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		min_heapify(arr,smallest,heapsize);
	}
}

int *buildMinHeap(int arr[], int items){
	int heapsize = items;
	int j;
	for(j=items/2; j>=0; j--){
		min_heapify(arr,j,heapsize);
	}
	return arr;
}

void insert_min(int element, int items)
{
	int parent;
	while(items>0){
		parent = (items-1)/2;
		if(element>=arr1[parent]){
			arr1[items]=element;
			return;
		}
		arr1[items]  = arr1[parent];
		items = parent;
	}
	arr1[0] = element;
}

void delete_min(int arr[],int items)
{
	int last = arr[items-1];
	arr[0] = last;
	items=items-1;
	min_heapify(arr,0,items);
}

void heapsort_min(int arr[],int items)
{
	int i,temp;
	
	for(i=items/2-1; i>=0; i--)
		min_heapify(arr,i,items);
	for(i=items-1; i>0; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		min_heapify(arr,0,i);
	}	
}
//function to print my heap
void printarr(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void main(){
	int i, items, choice, ch1, ch2, element;
	int flag=0;
	
	printf("\nWelcome to Heapsort Using Min-Heapify and Max-Heapify\n-------------------------------------------------------------------------\n");
	
	mainmenu:		
		printf("\nMain Menu\n");
		printf("1. Use Max_heapify \n");
		printf("2. Use Min_heapify  \n");
		printf("3. Exit \n");
		scanf("%d",&choice);
		
		if(choice == 1){
			maxheapmenu:
			printf("\nMax Heap Menu\n");
			printf("\n1. Build Max_heap");
			printf("\n2. Insert a key into heap");
			printf("\n3. Delete a key from heap");
			printf("\n4. Sort the elements");
			printf("\n5. Retun backto mainmenu");
			printf("\n6. Exit\n");
			scanf("%d",&ch1);
			
			if(ch1 == 1){
				printf("\nEnter the no of elements less than %d :- ",MAX);
				scanf("%d",&items);	
					
				for(i=0;i<items;i++){
					scanf("%d",&arr1[i]);
				}

				arr2 = buildMaxHeap(arr1,items);
				
				printf("\nMax_heap :-\n");
				printarr(arr2,items);
				goto maxheapmenu;
			}
			else 
			if(ch1 == 2){
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&element);
				
				insert_max(element,items);
				printf("\nMax_heap after insertion operation:-\n");				
				
				items = items+1;
				printarr(arr1,items);
				goto maxheapmenu;
			}
			else 
			if(ch1 == 3){
				flag = 1;
				delete_max(arr1,items);
				printf("\nMax_heap after deletion opeartion:-\n");								
				printarr(arr1,items-1);
				goto maxheapmenu;
			}
			else 
			if(ch1 == 4){
				if(flag == 1)
					items--;
				heapsort_max(arr1,items);
				printf("\nMax_heap after sorting:-\n");					
				printarr(arr1,items);
				goto maxheapmenu;
			}
			else 
			if(ch1 == 5){
				goto mainmenu;
			}
			else
			if(ch1 == 6)
			{
				printf("\nExiting...");
				exit(1);
			}
			else{
				printf("\nInvalid choice..Try again.");
				goto mainmenu;
			}
		}
		else
		if(choice == 2){
			minheapmenu:
			printf("\nMax Heap Menu\n");
			printf("\n1. Build Max_heap");
			printf("\n2. Insert a key into heap");
			printf("\n3. Delete a key from heap");
			printf("\n4. Sort the elements");
			printf("\n5. Retun backto mainmenu");
			printf("\n6. Exit\n");
			scanf("%d",&ch2);
			
			if(ch2 == 1){
				printf("\nEnter the no of elements less than %d :- ",MAX);
				scanf("%d",&items);
		
				for(i=0;i<items;i++){
					scanf("%d",&arr1[i]);
				}
				
				arr2 = buildMinHeap(arr1,items);
				printf("\nMin_heap :-\n");				
				printarr(arr2,items);
				goto minheapmenu;
				
			}
			else 
			if(ch2 == 2){
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&element);
				
				insert_min(element,items);
				printf("\nMin_heap after insertion operation:-\n");				
				items = items+1;
				printarr(arr1,items);
				goto minheapmenu;	
			}
			else 
			if(ch2 == 3){
				flag = 1;
				delete_min(arr1,items);
				printf("\nMin_heap after deletion operation:-\n");				
				printarr(arr1,items-1);
				goto minheapmenu;				
			}
			else 
			if(ch2 == 4){
				if(flag == 1)
					items--;
				heapsort_min(arr1,items);
				printf("\nMin_heap after sorting:-\n");								
				printarr(arr1,items);
				goto minheapmenu;
				
			}
			else 
			if(ch2 == 5){
				goto mainmenu;
			}
			else
			if(ch2 == 6)
			{
				printf("\nExiting...");
				exit(1);
			}
			else{
				printf("\nInvalid choice..Please Retry");
				goto minheapmenu;
			}
		}
		else
		if(choice == 3)
		{
			printf("\nExiting...");
			exit(1);
		}
		else{
			printf("\nInvalid choice..Please Retry");
			goto mainmenu;
		}
}
