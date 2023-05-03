#include<stdio.h>
int main()
{
	int n,a[100],t,i;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	printf("Enter the elements in an array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	t=a[0];
	for(i=0;i<=n;i++)
	{
		if(a[i]>t){
			t=a[i];
			
		}
	}
	printf("The greatest element in an array is %d",t);
	
	return 0;
	
}
