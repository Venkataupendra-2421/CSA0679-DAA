#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,palindrome=1;
	char str[100],revstr[100];
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
	for(i=0;i<=j;i++){
		revstr[i] = str[j-i];
    }
    revstr[i]='\0';
    printf("\n The reverse of %s is %s",str,revstr);
    
    return 0;
}
