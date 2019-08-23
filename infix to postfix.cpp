#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char stk[15],inp[20],out[20],elem;
int top=-1,count=0;
void push(char c)
{

	top++;
	stk[top]=c;
}
void pop()
{
	out[count++]=stk[top];
	top--;
}
int prior(char c)
{
	switch(c)
	{
		case '/':
			return 2;break;
		case '*':
			return 2;break;
		case '+':
			return 1;break;
		case '-':
			return 1;break;
		case '^':
			return 3;break;
		default:
			printf("\n please give a operator in the equation.");
	}
}
	
	
int main()
{
	
	int i,j;
	printf("\n Enter the input Expression with delimitter #:");
	scanf("%s",&inp);
	printf("\n %s",inp);
	for(i=0;i<=strlen(inp);i++)
	{
		elem=inp[i];
		
		
		if(isalnum(elem))
		{
			out[count++]=elem;
			
		}
		else if(elem=='#')
		{
			while(top!=-1)
				pop();
		}
	
		
		
		
		else
		{
			if(elem=='(')
			{
				push(elem);
				elem=inp[++i];
				
				while(elem!=')')
				{
					if(isalnum(elem))
						out[count++]=elem;
					else
						push(elem);
					elem=inp[++i];
				}
				i--;
			}
			else if(elem==')')
			{
				while(stk[top]!='(')
				{
					pop();
				}
				top-=1;
			}
			
			else
			{
				if(top==-1)
					push(elem);
				else
				{
				if(prior(stk[top])>=prior(elem))
				{
					pop();
					push(elem);
				}
				else
					push(elem);
				}
			}
		}
	}
	out[count]='\0';
	printf("\n %s",out);
		
}	 	 
		
		
			

	

