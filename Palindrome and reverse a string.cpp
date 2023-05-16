#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,palindrome=1;
	char str[100];
	printf("Enter a string: ");
	scanf("%s",str);
	
	j = strlen(str)-1;
	
	for(i=0;i<=j;i++){
		if(str[i]!=str[j]){
			palindrome = 0;
			break;
		}
		--j;
	}
	if(palindrome == 1)
	  printf("%s is a palindrome ",str);
	else
	printf("%s is not  a palindrome ",str);
	
   return 0;
}
