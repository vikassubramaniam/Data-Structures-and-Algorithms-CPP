#include<iostream>
#include<math.h>
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
		cout<<"Enter some number(end the number with . and press enter)";
		do
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
		}while(a!='.');
		if(j!=0)
		{
			if(head==0)
			{
				head=tail=new node(i);
			}
			else
			{
				int x= pow(10,4-j);
				int y= pow(10,j);
				tail->next= new node( i+ (tail->n % x)*y );
				tail->next->prev=tail;
				tail=tail->next;
				
				node* pull = tail->prev;
				while(pull->prev!=0)
				{
					pull->n = (pull->n/x) +( (pull->prev->n % x) *y);
					pull=pull->prev;
				}
				head->n = head->n/x;
			}
		}

	}
	node *head,*tail;
};
void printlist(node* head)
{
	if(head!=0)
	{
		node* tmp=head;
		cout<<endl;
		cout<<tmp->n;
		tmp=tmp->next;
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
	else
		cout<<"Empty";
}
int main()
{
	list* a;
	a=new list();
	printlist(a->head);
	return 0;
}
