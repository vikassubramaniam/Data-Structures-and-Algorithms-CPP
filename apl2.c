#include<stdio.h>
#include<stdlib.h>
struct node
{

struct node *prev;
int n;
struct node *next;
};
struct node *s,*s1;
struct node *curr,*temp,*pr;
	//int ch,cch;
	//s=NULL;
	//s1=NULL;
struct node *create(struct node *x)
{
	if(x==NULL)
	{
		x=(struct node*)malloc(sizeof(struct node));
		printf("Enter the number\n");
		scanf("%d",&x->n);
		x->prev=NULL;
		x->next=NULL;
		return x;
	}
	else{
		printf("The List already created\n");
		return x;
	}
}
void display(struct node *x)
{
	curr=x;
	while(curr!=NULL)
	{
		printf("%d->",curr->n);
		curr=curr->next;
	}
}
void insend(struct node *x)
{
	curr=x;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number\n");
	scanf("%d",&temp->n);
	temp->next=NULL;
	curr->next=temp;
	temp->prev=curr;
}
struct node *insbeg(struct node *x)
{
    temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number\n");
	scanf("%d",&temp->n);
	temp->next=x;
	x->prev=temp;
	return temp;
}
void inspos(struct node *x)
{
	int pos,c=1;
	curr=x;
	printf("Enter the position to be inserted\n");
	scanf("%d",&pos);
	while(curr->next!=NULL)
	{
		c++;
	
	if(c==pos)
	{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number\n");
	scanf("%d",&temp->n);
	temp->next=curr->next;
	curr->next->prev=temp;
	curr->next=temp;
	temp->prev=curr;
	break;
	
	}
	curr=curr->next;
}
}
struct node *delbeg(struct node *x)
{
	curr=x;
	if(curr==NULL)
	{
		printf("No node to be deleted\n");
		return x;
	}
	else if(curr->next==NULL)
	{
		printf("You are deleting one and only one node\n");
		free(curr);
		x=NULL;
		return x;
	}
	else
	{
		x=x->next;
		x->prev=NULL;
		free(curr);
		return x;
	}
}
struct node *delend(struct node *x)
{
	curr=x;
	if(curr==NULL)
	{
		printf("No node to be deleted\n");
		return x;
	}
	else if(curr->next==NULL)
	{
		printf("You are deleting final node\n");
		free(curr);
		x=NULL;
		return x;
    }
		else
		{
			while(curr->next!=NULL)
			{
				pr=curr;
				curr=curr->next;
				
			}
			pr->next=NULL;
			free(curr);
			return x;
		}
	
}
void delpos(struct node *x)
{
	int pos,c=1;
	curr=x;
	printf("Enter the position to be deleted\n");
	scanf("%d",&pos);
	while(curr->next!=NULL)
	{
		c++;
	
	if(c==pos)
	{
	
	temp=curr->next;
	curr->next->next->prev=curr;
	curr->next=curr->next->next;
	free(temp);
	break;
	}
	curr=curr->next;
}
}
void reverse(struct node *x)
{
	curr=x;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	while(curr!=NULL)
	{
		printf("%d->",curr->n);
		curr=curr->prev;
	}
}
void count(struct node *x)
{
	int c=0;
	curr=x;
	while(curr!=NULL)
	{
		curr=curr->next;
		c++;
	}
	printf("The number of nodes are %d\n",c);
}
void search(struct node *x)
{
	int se,ctr=1;
	curr=x;
	printf("Enter the searching element\n");
	scanf("%d",&se);
	while(curr!=NULL)
	{
		if(curr->n==se)
		{
			printf("The element found at %d position\n");
			break;
		}
		ctr++;
		curr=curr->next;
	}
	
}
struct node *split(struct node *x)
{
	int pos,c=1;
	curr=x;
	printf("Enter the position to be split\n");
	scanf("%d",&pos);
	while(curr->next!=NULL)
	{
		c++;
		if(c==pos)
		{
			temp=curr->next;
			curr->next=NULL;
			temp->prev=NULL;
			break;
		}
		curr=curr->next;
		
	}
	return temp;
}
void merge(struct node *x,struct node *y)
{
	curr=x;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=y;
	y->prev=curr;
}

void sort(struct node *x)
{
	int c=0,i,j,te;
	curr=x;
	while(curr!=NULL)
	{
		curr=curr->next;
		c++;
	}
	for(i=0;i<c;i++)
	{
		curr=x;
		for(j=0;j<c-i-1;j++)
		{
			if(curr->n > curr->next->n)
			{
				te=curr->n;
				curr->n=curr->next->n;
				curr->next->n=te;
				
			}
			curr=curr->next;
		}
	}
}
void main(void)
{
//	struct node *s,*s1;
	int ch,cch;
	s=NULL;
	s1=NULL;
	do
	{
		printf("\n1.create\n");
		printf("2.Display\n");
		printf("3.Insend\n");
		printf("4.Insbeg\n");
		printf("5.Inspos\n");
		printf("6.Delbeg\n");
		printf("8.Delpos\n");
		printf("9.Reverse\n");
		printf("10.Count\n");
		printf("11.Search\n");
		printf("12.Split\n");
		printf("13.Merge\n");
		printf("14.Sort\n");
		printf("15.Exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					s=create(s);
		           break;
		    case 2:printf("1.First list\n2.Second list\n");
			       printf("Enter the choice\n");
				   scanf("%d",&cch);
				   if(cch==1)
				   {
				   	display(s);
				   	
				   }
				   else if(cch=2)
				   {
				   	display(s1);
				   }
				   break;
			case 3:insend(s);
			       break;
			case 4:insbeg(s);
			       break;
		    case 5:inspos(s);
			       break;
		    case 6:s=delbeg(s);
			       break;
		    case 7:s=delend(s);
			       break;
		    case 8:delpos(s);
			       break;
			case 9:reverse(s);
			       break;
			case 10:count(s);
			       break;
			case 11:search(s);
			       break;
			case 12:s1:split(s);
			       break;
			case 13:merge(s,s1);
			       s1=NULL;
				   break;
			case 14:sort(s);
			        break;
		}
	}while(ch!=15);
	
}


	
				   			 	
	
