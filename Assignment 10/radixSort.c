#include <stdio.h>

void radixSort(int *a, int n) //function to implement radix sort
{
	int i,b[10],m=0,exp=1;
	for(i=0;i<n;i++)
	{
		if(a[i]>m)
		m=a[i];
	}
	
	while(m/exp > 0)
	{
		int box[10] = {0};
		for(i=0;i<n;i++)
			box[a[i] / exp %10]++;
		for(i=1;i<10;i++)
			box[i] += box[i-1];
		for(i=n-1;i>=0;i--)
			b[--box[a[i] / exp % 10]] =a[i];
		for(i=0;i<n;i++)
			a[i]=b[i];
		exp *= 10;
	}
}

void main() //main driver function
{
	int arr[100], i, num;
	printf("Welcome to Radix Sort Program \n\n Enter the number of elements: ");
	scanf("%d",&num);
	printf("Enter the elements of the array:");
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
	radixSort(&arr[0], num);
	printf("\nSorted  elements : ");
	for(i=0;i<num;i++)
		printf("%d  ",arr[i]);
}
