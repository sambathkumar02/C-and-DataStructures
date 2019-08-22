#include<stdio.h>
#include<stdlib.h>
int max(int arr[],int n)
{
	int max,i;
	max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}

void count_sort(int arr[],int n,int exp)
{
	int output[10],i,j;
	int count[10]={0};
	for(i=0;i<n;i++)
		count[(arr[i]/exp)%10]++;
	for(i=1;i<10;i++)
		count[i]+=count[i-1];
	for(i=n-1;i>=0;i--)
	{
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
		arr[i]=output[i];
}

void radix_sort(int arr[],int n)
{
	int m,exp,i;
	m=max(arr,n);
	for(exp=1;m/exp>0;exp*=10)
		count_sort(arr,n,exp);
	printf("\n sorted array..");
	for(i=0;i<n;i++)
		printf("\t %d",arr[i]);
}
		
	
	
int main()
{
	int arr[100],i,j,n;
	printf("\n enter the number of elements....");
	scanf("%d",&n);
	printf("\n Enter the elements..");
	for(i=0;i<n;i++)
		scanf("\n %d",&arr[i]);
	radix_sort(arr,n);
}
	
	
	

