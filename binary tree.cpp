#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;

struct node *insert(struct node *root)
{
	struct node *new_node,*temp;
	int num,opt,n;
	printf("\n Enter the number of elements:");
	scanf("%d",&n);
	while(n!=0)
	{
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->left=NULL;
	new_node->right=NULL;
	printf("\n Enter the value of data:");
	scanf("%d",&num);
	new_node->data=num;
	if(root==NULL)
	{
		root=new_node;
	}
	else
	{
		temp=root;
		int flag=0;
		while(flag!=1)
		{
		fflush(stdin);
		printf("\n Enter 1.left or 2.right:");
		scanf("%d",&opt);
		if(opt==1)
		{
		
			if(temp->left==NULL)
			{
				temp->left=new_node;
				temp=temp->left;
				flag=1;
			}
			else
				flag=0;
			printf("\n %",root->left);
			
		}
		else if(opt==2)
		{
			
			
			if(temp->right==NULL)
			{
				temp->right=new_node;
				temp=temp->right;
				flag=1;
			}
			else
				flag=0;
		}
		else
			printf("\n invalid option...");
		}
	}
	n--;
	}
	printf("\n Elements inserted sucessfully..");
	return root;
	
	
}

struct node *del(struct node *root)
{
	int key;
	printf("Enter the value of node to be searched:");
	scanf("%d",&key);
	struct node *ptr;
	ptr=root;
}
		
		

void inorder(struct node *pos)
{
	if(pos!=NULL)
	{
		inorder(pos->left);
		printf(" \t %d",pos->data);
		inorder(pos->right);
	}
}
void display(struct node *root)
{
	struct node *ptr;
	ptr=root;
	printf("\n Elements in tree..\n");
	inorder(ptr);
}

int main()
{
	root=insert(root);
	display(root);
}

