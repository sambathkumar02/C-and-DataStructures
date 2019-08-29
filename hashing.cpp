#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
struct node 
{
	int data;
	struct node *next;
};
struct node *start[size]={NULL};

	

int table[size]={0};int hash,i;


void linear_probing(int hash,int elem)
{
	int	flag=0;
	while(flag!=1)
	{
		if(hash==size-1)
			hash=-1;
		hash++;
	    if(table[hash]==0)
		{
				table[hash]=elem;
				flag=1;
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


void hashing1(int keyValue)
{
	
	hash=(keyValue)%(size);
	if(table[hash]==0)
	{
		table[hash]=keyValue;
		return;
	}
	else
		linear_probing(hash,keyValue);
		
	
}
void hashing2(int keyValue)
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
    int numbers[10],n,opt;
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
		printf("1.Linear Probing\n2.Seperate Chaining\nEnter your option:");
		scanf("%d",&opt);
		switch(opt)
		{
		 case 1:
			for(i=0;i<n;i++)
			    hashing1(numbers[i]);
			display();break;
		case 2:
		    for(i=0;i<n;i++)
		     hashing2(numbers[i]);
	    	display();break;
		default:
		    printf("\nPlease enter crt option");
	    }
		
	}
}

