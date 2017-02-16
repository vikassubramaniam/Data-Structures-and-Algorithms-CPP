#include<iostream>
#include<string.h>
using namespace std;
#define n 100
void push(char x,char a[],int* top)
{
	if((*top)!=(n-1))
	{
		(*top)++;
		a[*top]=x;
	}
	else
	{
		cout<<"Stack is full\n";
		exit(1);
	}
}
void pop(char a[],int* top)
{
	if((*top)!=-1)
	{
		*top=*top-1;
	}
	else
	{
		cout<<"Not accepted:Received ) before ( \n";
		exit(0);
	}
}
void check (char a[],int* top)
{
	if((*top))
	{
		cout<<"\nNot accepted: Excess open braces:\n";
		for (int i = 0; i <= *top; i++)
		{
			cout<<a[i];
		}
	}
	else
	{
		cout<<"\nAccepted. All braces balanced\n";
	}
}	


int main()
{
	int top=-1;
	char a[n],ch;
	int i;
	while(1)
	{
		cin>>ch;
		if (ch == '(')
		{
			push(ch,a,&top);
		}
		else if (ch == ')')
		{
			pop(a,&top);
		}
		else if(ch=='.')
		{
			break;
		}
	}
	check(a,&top);
	return 0;
}
