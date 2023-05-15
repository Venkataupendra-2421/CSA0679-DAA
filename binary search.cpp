#include<stdio.h>
int main()
{
	int a[100],flag=0,i,n,mid,last,first,key,b;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	printf("enter %d elements ",n);
	for(i=1;i<=n;i++)
	{
	 scanf("%d",&a[i]);
	}
	printf("Enter the element to find in an array:");
	scanf("%d",&key);
	first=0;
	last=n-1;
	mid=(first+last)/2;
	while(first<=last)
	{
		if(a[mid]==key)
		{
			printf("flag=1 and key element found");	
				break;
		}
		else if(a[mid]>key)
		{
		last=mid-1;
			printf("flag=1 and key element not found");	
				break;
		}
		else if(a[mid]<key)
		first=mid+1;
			printf("flag=1 and key  element found");	
				break;
	}
	
}
