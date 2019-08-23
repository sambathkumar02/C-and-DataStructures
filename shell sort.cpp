#include<stdio.h>
#include<stdlib.h>
void shell_sort(int arr[],int n)
{
	int gap,i,j,temp;
	gap=n/2;
	for(gap;gap>0;gap/=2)
	{
		for(i=gap;i<n;i+=1)
		{
			temp=arr[i];
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
				arr[j]=arr[j-gap];
			arr[j]=temp;
		}
	}
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
	shell_sort(arr,n);
}
	

