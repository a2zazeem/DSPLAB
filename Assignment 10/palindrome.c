#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void palindromeString(char s[]) //function to find the longest palindrome string
{
	int left, right, beg=0, end=1, i;
	for(i=1;i<strlen(s);i++)
	{
		left=i-1;
		right=i;
		
		while(s[left]==s[right] && left>=0 && right<strlen(s)) //checking for even sized palindrome substring
		{
			if(right - left + 1 > end)
			{
				beg = left;
				end = right - left + 1; 
			}
			left--;
			right++;
		}
		
		left=i-1;
		right=i+1;
		
		while(s[left]==s[right] && left>=0 && right<strlen(s)) //checking for odd sized palindrome substring
		{
			if(right - left + 1 > end)
			{
				beg = left;
				end = right - left + 1; 
			}
			left--;
			right++;
		}
	}
	printf("\nPalindrome String is: "); //printing the longest palindrome in the string
	for(i=beg;i<=beg+end-1;i++)
	{
		printf("%c",s[i]);	
	}	
}


void main()
{
	char s[100];
	
	printf("Welcome to Longest Palindromic String Program\n\n Input your string below:\n");
	fgets(s, 100, stdin);
	if(strlen(s)<2) //checking boundary condition
	{
		printf("\nPalindrome String is : %s",s);
		exit(0);
	}
	else
	{
		palindromeString(s); //calling palindrome finder function
	}
}

