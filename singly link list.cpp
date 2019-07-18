#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);

int main()
{
int option,a;
do
{
printf("\n MAIN MENU");
printf("\n1.create \n2.display \n 3.insert at begening \n4.insert at the end \n 5.insert at particular position \n6.delete begening");
printf("\n 7.delete end \n 8.delete a particular node \n 9.EXIT");
printf("\n Enter your option:");
scanf("%d",&option);
switch(option)
{
case 1:start=create(start);printf("\n list created sucessfully");break;
case 2:start=display(start);break;
case 3:start=insert_beg(start);break;
case 4:start=insert_end(start);break;
case 5:start=insert(start);break;
case 6:start=delete_end(start);break;
case 7:start=delete_end(start);break;
case 8:start=delete_node(start);break;
case 9:exit(0);break;
default:printf("\n invalid option enter correct option");
}
printf("\n do you want to continue(1/0):");
scanf("%d",&a);

}while(a==1);

}

struct node *create(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	printf("\n press -1 to end");
	printf("\n enter the  data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\n enter the data:");
		scanf("%d",&num);
	}
	return start;
	}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return start;
	}

struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n enter the value of data:");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;

}
struct node *insert_end(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	printf("\n enter the value of data:");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	return start;
}

struct node *insert(struct node *start)
{
	struct node *ptr,*new_node,*preptr;
	int num,val;
	printf("\n enter the value of data:");
	scanf("%d",&num);
	printf("\n enter the value before the data has to be inserted:");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		printf("\n there is no element specified....");
	}
	if(ptr==NULL)
		printf("\n there is no element specified....");
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
	}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node * ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
struct node *delete_node(struct node *start)
{
	struct node * ptr,*preptr;
	int val;
	printf("\n enter the value of node to be deleted:");
	scanf("%d",&val);
	ptr=start;
	if(ptr->data==val)
	{
		start=delete_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr=ptr->next;
			if(ptr==NULL)
			printf("\n there is no element specified....");
		}
		
		
		preptr->next=ptr->next;
		free(ptr);
		return start;
	}
}



















