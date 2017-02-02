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
		cout<<"\nEnter some number(end the number with . and press enter)";
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
	list(int x)
	{
		head= tail=0;
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
list* addition(list*a, list*b)
{
	list* sum;
	sum=new list(0);
	int carry=0,add;
	int y=pow(10,4);
	node* curr=0;
	node* pre=0;
	node* op1=a->tail;
	node* op2=b->tail;
	while((op1!=0)&&(op2!=0))
	{
		add= op1->n + op2->n + carry;
		curr= new node(add%y);
		carry= add/y;
		
		curr->next=pre;
		if(sum->tail==0)
		{
			sum->tail=curr;
		}
		else
		{
			pre->prev=curr;
		}
		
		pre=curr;
		op1=op1->prev;
		op2=op2->prev;
	}
	if(op1==0&&op2==0)
	{
		if(carry!=0)
		{
			curr=new node(carry);
			curr->next=pre;
			pre->prev=curr;
		}
		sum->head=curr;
	}
	else if(op1==0)
	{
		while(op2!=0)
		{
			add= op2->n + carry;
			curr= new node(add%y);
			carry= add/y;
			curr->next=pre;	
			if(sum->tail==0)
			{
				sum->tail=curr;
			}
			else
			{
				pre->prev=curr;
			}

			pre=curr;
			op2=op2->prev;
		}
		if(carry!=0)
		{
			curr=new node(carry);
			curr->next=pre;
			pre->prev=curr;
		}
		sum->head=curr;
	}
	else
	{
		while(op1!=0)
		{
			add= op1->n + carry;
			curr= new node(add%y);
			carry= add/y;
			
			curr->next=pre;	
			if(sum->tail==0)
			{
				sum->tail=curr;
			}
			else
			{
				pre->prev=curr;
			}

			pre=curr;
			op1=op1->prev;
		}
		if(carry!=0)
		{
			curr=new node(carry);
			curr->next=pre;
			pre->prev=curr;
		}
		sum->head=curr;
	}
	return sum;
}
int main()
{
	list* a;
	a=new list();
	printlist(a->head);
	list* b;
	b= new list();
	printlist(b->head);
	list* c;
	c= addition(a,b);
	cout<<"\nSum:";
	printlist(c->head);
	return 0;
}
