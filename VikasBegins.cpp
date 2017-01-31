#include<iostream>
using namespace std;
class node{
	public:
	node(int x)
	{
		n=x;
		next=0;
		prev=0;
	}
	int n;
	node *next,*prev;
};
class list{
	public:
	list()
	{
		char a=' ';
		int i=0,j=0;
		head=tail=0;
		cout<<"Enter some number";
		while(a!='\n')
		{
			cin>>a;
			if(a<='9'&&a>='0')
			{
				i= i*10 + (a - '0');
				j++;
				if(j==4)
				{
				
					if(head==0)
					{
						head=tail=new node(i);
					}
					else
					{
						tail->next= new node(i);
						tail->next->prev=tail;
						tail= tail->next;
					}
					j=i=0;
				}
			}
		}
		if(j!=0)
		{
			if(head==0)
			{
				head=tail=new node(i);
			}
			else
			{
				tail->next= new node(i);
				tail->next->prev=tail;
				tail->next=tail;
			}
		}
	}
	node *head,*tail;
};
void printlist(node* head)
{
	node* tmp=head;
	cout<<endl;
	while(tmp!=0)
	{
		if(tmp->n >= 1000)
			cout<< tmp->n;
		else if(tmp->n>=100)
			cout<<"0"<<tmp->n;
		else if(tmp->n>=10)
			cout<<"00"<<tmp->n;
		else
			cout<<"000"<<tmp->n;
		tmp=tmp->next;
	}
}
int main()
{
	list* a;
	a=new list();
	printlist(a->head);
	return 0;
}
