#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
void swap(int *a,int *b);
void print(int arr[],int n);
void selection_sort(int arr[],int n);
void bubble_sort(int arr[],int n);
void insertion_sort(int arr[],int n);


int main()
{
	int arr[100],i,j,n,opt;
	printf("\n Enter the number of elements:");
	scanf("%d",&n);
	printf("\n Enter the numbers :");
	for(i=0;i<n;i++)
		scanf("\t%d",&arr[i]);
	while(1)
	{

	printf("\n ***sorting techniques***\n1.bubble sort\n2.selection sort\n3.insertion sort\n 4.exit");
	printf("\n Enter your choice...:");
	scanf("%d",&opt);
	switch(opt)
	{
	case 1:bubble_sort(arr,n);break;
	case 2:selection_sort(arr,n);break;
	case 3:insertion_sort(arr,n);break;
	case 4:exit(0);
	default:printf("\n Enter correct option..");
	}
	}
}






void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\t %d",arr[i]);
}


void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void selection_sort(int arr[],int n)
{
	int i,j,smaller,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
		
		}
		
	}
	 	printf("\n output of selection sort...");
		print(arr, n);
			
	
	
}

void bubble_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				
			}
		}
	}
	printf("\n output of bubble sort...");
	print(arr, n);
}

void insertion_sort(int arr[],int n)
{
	int i,j,cur;
	for(i=1;i<n;i++)
	{
		cur=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>cur)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		
		arr[j+1]=cur;
		
	}
	printf("\n output of insertion  sort...");
	print(arr,n);
}
		

