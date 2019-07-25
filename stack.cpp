#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
struct node *push(struct node *);
struct node *display(struct node *);
struct node *pop(struct node *);
int main()
{
int option;
do
{
printf("\n MAIN MENU");
printf("\n 1.push\n2.pop\n3.display");
printf("\n Enter your option:");
scanf("%d",&option);
switch(option)
{
case 1:top=push(top);break;
case 2:top=pop(top);break;
case 3:top=display(top);break;
case 4:exit(0);break;
default:printf("\n enter the correct option");
}
}while(option!=4);
}


struct node *push(struct node *top)
{
	struct node *ptr,*new_node;
	int num;
	printf("\n press -1 to end");
	printf("\n enter the value of data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(top==NULL)
		{
			new_node->next=NULL;
			top=new_node;
		}
		else
		{
			new_node->next=top;
			top=new_node;
			
		}
		printf("\n enter the data:");
		scanf("%d",&num);
	}
	return top;
}

struct node *display(struct node *top)
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
		printf("\n the stack is empty");
	while(ptr->next!=NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return top;
}

struct node *pop(struct node *top)
{
	struct node * ptr,*preptr;
	ptr=top;
	if(top==NULL)
		printf("\n the stack is empty");
	top=ptr->next;
	free(ptr);
	printf("\n The element is popped");
	return top;
}
	
	
	

