#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node* next;
		node(int n )
		{
			val=n;
			next=0;
		}
};
class circle{
	public:
		node* rear;
		circle()
		{
			rear=0;
		}
		void insert(int n, int x=0)
		{
			if(rear==0)
			{
				rear= new node(n);
				rear->next=rear;
			}
			else
			{
				node* temp=new node(n);
				temp->next=rear->next;
				rear->next=temp;
				if(x)
				{
					rear=rear->next; //Insertion at end
				}
			}
		}
		void delatbeg()
		{
			if(rear!=0)
			{
				if(rear->next==rear)
				{
					cout<<"\nI am here";
					rear=0;
				}
				else
				{
					rear->next=rear->next->next;
				}
			}
		}
		void delatend()
		{
			if(rear!=0)
			{
				if(rear->next==rear)
				{
					rear=0;
				}
				else
				{
					node* temp;
					temp=rear->next;
					while(temp->next!=rear)
					{
						temp=temp->next;
					}
					temp->next= rear->next;
					rear=temp;
				}
			}
		}
		void print()
		{
			if(rear==0)
			{
				cout<<"\nEmpty list";
				return;
			}
			node* cur=rear->next;
			cout<<"\n";
			do
			{
				cout<<cur->val<<" ";
				cur=cur->next;
			}while(cur!=rear->next);
		}
};
int main()
{
	int n,x;
	circle a;
	while(1)
	{
		cout<<"\n1.Insert at beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Exit\nEnter your choice: ";
		cin>>n;
		switch(n)
		{
			case 1: cout<<"\nEnter the number: ";
					cin>>x;
					a.insert(x);
					a.print();
					break;
			case 2: cout<<"\nEnter the number: ";
					cin>>x;
					a.insert(x,1);
					a.print();
					break;
			case 3: a.delatbeg();
					a.print();
					break;
			case 4: a.delatend();
					a.print();
					break;
			case 5: exit(1);
			}
	}	
	return 0;
}
