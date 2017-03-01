#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int n;
	struct node *right;
};
struct node *curr,*temp,*prev;

struct node* create(struct node *x)
{
	if(x==NULL)
	{
		x=(struct node*)malloc(sizeof(struct node));
		printf("Enter the number\n");
		scanf("%d",&x->n);
		x->left=NULL;
		x->right=NULL;
		return x;
		
	}
	else
	{
		printf("tree already created\n");
		return x;
	}
}
void insert(struct node *x)
{
	curr=x;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number\n");
	scanf("%d",&temp->n);
	temp->left=NULL;
	temp->right=NULL;
	while(curr!=NULL)
	{
		if(curr->n==temp->n)
		{
			printf("Duplicate node\n");
			break;
		}
		else if(temp->n<curr->n)
		{
			if(curr->left==NULL)
			{
			curr->left=temp;
			break;
		}
			else{
				curr=curr->left;
			}
			
		}
	
	else if(temp->n>curr->n)
	{
		if(curr->right==NULL)
		{
			curr->right=temp;
			break;
		}
		else
		{
			curr=curr->right;
			
		}
	}
}
}
void inorder(struct node*x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		printf("%d->",x->n);
		inorder(x->right);
	}
}
void preorder(struct node*x)
{
	if(x!=NULL)
	{
		printf("%d->",x->n);
		preorder(x->left);
		preorder(x->right);
	}
}
void postorder(struct node*x)
{
	if(x!=NULL)
	{
		postorder(x->left);
		postorder(x->right);
		printf("%d->",x->n);
	}
}
void printLevelOrder(struct node* x)
{
    int h = height(x);
    int i;
    int j=h;
    for (i=1; i<=h; i++)
    {
    	printf(" height %d nodes :", j--);
        printGivenLevel(x, i);
	}

      
}
void printGivenLevel(struct node* x, int level)
{
    if (x == NULL)
        return;
    if (level == 1)
        printf("%d \n", x->n);
    else if (level > 1)
    {
        printGivenLevel(x->left, level-1);
        printGivenLevel(x->right, level-1);
    }
} 

int height(struct node* x)
{
    if (x==NULL)
        return 0;
    else
    {
        
        int lheight = height(x->left);
        int rheight = height(x->right);
 
        
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void main(void)
{
	int ch;
	struct node *s;
	s=NULL;
	do
	{
		printf("1.create\n");
		printf("2.Insert\n");
		printf("3.Inorder\n");
		printf("4.Preorder\n");
		printf("5.Postorder\n");
		printf("6.height  of each node\n");
		printf("7.Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:s=create(s);
			       break;
		    case 2:insert(s);
		           break;
		    case 3:inorder(s);
		           break;
		    case 4:preorder(s);
		           break;
		    case 5:postorder(s);
		           break;
		    case 6:printLevelOrder(s);
			       break;     
		    
		}
		}while(ch!=7);
		
	
}
