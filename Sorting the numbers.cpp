#include<stdio.h>
int main()
{
	int m,n[20],i,j,t;
	printf("Enter the number of elements:");
	scanf("%d",&m);
	printf("Enter the elements in the list:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&n[i]);
		
	}
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(n[i]>n[j])
			
			{
				t=n[i];
				n[i]=n[j];
				n[j]=t;
				
			}
		}
		printf("The sorted list is:\n");
		for(i=0;i<m;i++){
		
		  printf("%d",n[i]);
	}
		printf("\n");
    }
	return 0;
 } 
