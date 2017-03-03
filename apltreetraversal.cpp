#include<iostream>
using namespace std;
class node
{
	public:
	node *left;
	int n;
	node *right;
	node(int m)
	{
		n=m;
		left=0;
		right=0;
	}
};
class tree
{
	public:
	node* root;
	tree()
	{
		root=0;
	}
	void insert()
	{
		int n;
		cout<<"\nEnter the number:";
		cin>>n;
		if(root==0)
		{
			root=new node(n);
			cout<<"\nI am here";
			return;
		}
		node* curr=root;
		node* temp= new node(n);
		while(curr!=0)
		{
			if(curr->n==temp->n)
			{
				cout<<"\nDuplicate node";
				break;
			}
			else if(temp->n<curr->n)
			{
				if(curr->left==0)
				{
					curr->left=temp;
					break;
				}
				else
				{
					curr=curr->left;
				}
			}
			else if(temp->n>curr->n)
			{
				if(curr->right==0)
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
};

void inorder(node* x)
{
	if(x!=0)
	{
		inorder(x->left);
		cout<<x->n<<"->";
		inorder(x->right);
	}
}
void preorder(node*x)
{
	if(x!=0)
	{
		cout<<x->n<<"->";
		preorder(x->left);
		preorder(x->right);
	}
}
void postorder(node*x)
{
	if(x!=0)
	{
		postorder(x->left);
		postorder(x->right);
		cout<<x->n<<"->";
	}
}
int height(node* x)
{
    if (x==0)
        return -1;
    else
    {
        
        int lheight = height(x->left);
        int rheight = height(x->right);
 
        
        if (lheight > rheight)
        {
        	cout<<"\nHeight of "<<x->n<<" is "<<lheight+1;
            return(lheight+1);
    	}
        else 
		{
			cout<<"\nHeight of "<<x->n<<" is "<<rheight+1;	
			return(rheight+1);
		}
    }
}
int main()
{
	int ch;
	tree s;
	do
	{
		cout<<"\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.height  of each node\n6.Exit\nEnter the choice\n";
		cin>>ch;
		switch(ch)
		{
		    case 1:s.insert();
		           break;
		    case 2:inorder(s.root);
		           break;
		    case 3:preorder(s.root);
		           break;
		    case 4:postorder(s.root);
		           break;
		    case 5:int i=height(s.root);
			       break;     
		    
		}
	}while(ch!=6);
		
	return 0;
}
