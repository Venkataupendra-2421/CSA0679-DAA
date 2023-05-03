#include<stdio.h>
int main()
{
	int r,n,sum=0,t;
	printf("Enter the number:");
	scanf("%d",&n);
	t=n;
	while(n>0)
	{
		r=n%10;
		sum=sum+(r*r*r);
		n=n/10;
    }
    if(t==sum)
    printf("%d is an armstrong number",n);
    else
    printf("%d is not an armstrong number",n);
    return 0;
    
}
