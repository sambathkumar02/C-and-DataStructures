#include<stdio.h>
#include<stdlib.h>
void linear_search(int[],int);
void binary_search(int[],int);


int main()
{
	int arr[100],key,i,j,n,opt;
	printf("\n Enter the number of elements:");
	scanf("%d",&n);
	printf("\n Enter the numbers in ascending order:");
	for(i=0;i<n;i++)
		scanf("\t%d",&arr[i]);

	printf("***searching techniques***\n1.linear\n2.binary\n3.exit");
	printf("\n Enter your choice...:");
	scanf("%d",&opt);
	switch(opt)
	{
	case 1:linear_search(arr,n);break;
	case 2:binary_search(arr,n);break;
	case 3:exit(0);
	default:printf("\n Enter correct option..");
	}
}




void linear_search(int arr[],int n)
{
	int key,flag=0,i,pos;
	printf("\n enter the element to be searched:");
	scanf("%d",&key); 
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			flag=1;pos=i;
		}
	}
	if(flag==1)
		printf("\n Elemnet is found in position %d",pos);
	else
		printf("\n Element is not found..");
		
}



void binary_search(int arr[],int n)
{
	int key,i,flag=0,mid,beg=0,end=n-1;
	printf("\n enter the element to be searched:");
	scanf("%d",&key);
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==key)
		{
			printf("\n the element is found in %d position",mid);
			flag=1;
			break;
		}
		else if(arr[mid]>key)
			end=mid-1;
		else
			beg=mid+1;
	}
	if(flag==0)
		printf("\n The element is not found..");
}
			
	
	
	
	
	


