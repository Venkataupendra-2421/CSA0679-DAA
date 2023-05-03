#include<stdio.h>
int main()
{
	int a,b,i,j,prime;
	printf("Enter two positive numbers: ");
	scanf("%d %d",&a,&b);
    printf("The prime numbers between %d and %d are:\n",a,
	b);
	for(i=a;i<=b;i++){
		if(i == 1|| i == 0)
		  continue;
		  
	    prime=1;
	    
	    for(j=2;j<=i/2;j++){
	    	if(i%j==0){
	    		prime= 0;
	    		break;
			}
		}
		if(prime == 1)
		  printf("%d",i);
	}
	return 0;
}
