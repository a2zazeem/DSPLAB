//Implement Stack using Arrays

#include <stdio.h>

int top = -1, n, mystack[100];
int inputchoice=0;
void push();
void pop();
void display();
void main()
{	//user inputs stack size
	printf("Please Input Stack Size: \n");
	scanf("%d",&n);
	while(inputchoice!=4)
	{
		printf("Enter either: \n 1 for Push \n 2 for Pop \n 3 to Display \n 4 to Exit \n");
		scanf("%d",&inputchoice);
		switch(inputchoice)
		{	
			case 1:
				{
					push();
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					printf("Exiting Program");
					break;
				}
			default:  
                 	printf("Invalid Choice, Choose 4 to Exit Program \n");
                 	break;             	
		}
	}
}
	
//Code to push element to the Array	
void push()
	{
		int stack_data;
		if(top==n)
			printf("Overflow");
		else
		{
			printf("Enter the value to push into stack \n");
			scanf("%d",&stack_data);
			top=top+1;
			mystack[top]=stack_data;
		}
	}

//Code to push element from the Array
void pop()
{
	if(top==-1)
		printf("Underflow");
	else
	{
		printf("\n The popped value from the stack is: %d \n",mystack[top]);
		top=top-1;
	}
}

//Code to display all elements of the Array
void display()
{
	int i;
	for(i=top; i>=0; i--)
		printf("%d\n",mystack[i]);
	if(top==-1)
		printf("Empty Stack");
}
