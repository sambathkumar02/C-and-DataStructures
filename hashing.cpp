#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
struct node 
{
	int data;
	struct node *next;
};
struct node *start[size];

	

int table[size];int hash,i;


void linear_probing(int rem,int elem)
{
	int temp,flag=0;
	temp=rem;
	while(flag==1)
	{
		if(rem==size-1)
		{
			for(i=0;i<=temp;i++)
			{
				if(table[i]==0)
				{
					table[i]=elem;
					flag==1;
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			while(rem!=size-1 && flag==0)
			{
				if(table[rem]==0)
				{
				
					table[rem]=elem;
					flag=1;
				}
					
				else
				{
					rem++;
				}
			}
		}
	}
			
}
struct node *separate_chaining(struct node *ptr,int num)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=num;
	if(ptr==NULL)
	{
		ptr=temp;
	}
	else
	{
		p=ptr;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
		
	}
	return ptr;
	
}
	 
void display()
{
	for(i=0;i<size;i++)
	{
		printf("\n %d",table[i]);
		if(start[i]!=NULL)
		{
			struct node *s;
			s=start[i];
			while(s!=NULL)
			{
				printf("\t %d",s->data);
				s=s->next;
			}
		}
	}
}


void hashing(int keyValue)
{
	
	hash=(keyValue)%(size);
	if(table[hash]==0)
	{
		table[hash]=keyValue;
		return;
	}
	else
		start[hash]=separate_chaining(start[hash],keyValue);
		
	
}

int main()
{
	for(i=0;i<size;i++)
	{
		table[i]=0;
		start[i]=NULL;
	}
	
	int numbers[10],n;
	printf("\n Enter the number of eleemnts (less than or equal to %d ):",size);
	scanf("%d",&n);
	if(n>size)
	{
		printf("\n Enter the correct number of elements ..");
		exit(0);
	}
	else
	{
		printf("\n Enter the elements:");
		for(i=0;i<n;i++)
			scanf("\t %d",&numbers[i]);
		for(i=0;i<n;i++)
			hashing(numbers[i]);
		display();
	}
}
	
	
	


