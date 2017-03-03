#include<iostream>
#include <math.h>
#include<string>
#define MAX 100
using namespace std;
int isoperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'||ch=='%')
		return 1;
	else
		return 0;
}
int main()
{
	string postfix;
	int flag=0;
	char ch;
	int i = 0, top = -1;
	float val_stack[MAX], val1, val2, res;
	cout<<"\n Enter a postfix expression: ";
	cin>>postfix;
	cout<<"\nEvaluation:";
	while((ch = postfix[i]) != '\0')
	{
		if(ch==',')
		{
			flag=0;
		}
		else if(isoperator(ch) == 1)
		{
			flag=0;
			val2= val_stack[top--];
			val1= val_stack[top];
			switch(ch)
			{
				case '+': res = val1 + val2;
						  cout<<"\n"<<val1<<"+"<<val2<<"="<<res;
						  break;
				case '-': res = val1 - val2;
						  cout<<"\n"<<val1<<"-"<<val2<<"="<<res;
						  break;
				case '*': res = val1 * val2;
						  cout<<"\n"<<val1<<"*"<<val2<<"="<<res;
						  break;
				case '/': res = val1 / val2;
						  cout<<"\n"<<val1<<"/"<<val2<<"="<<res;
						  break;
				case '^': res = pow(val1, val2);
					  	  cout<<"\n"<<val1<<"^"<<val2<<"="<<res;	 
						  break;
				case '%': res=( (int)val1)%(int)val2;
 						  cout<<"\n"<<val1<<"%"<<val2<<"="<<res;
						  break;
			}
			val_stack[top] = res;
		}
		else
		{
			if(flag==0)
			{
				top++;
				val_stack[top] = ch-'0';
				flag=1;
			}
			else
			{
				val_stack[top]=val_stack[top]*10 + (ch-'0');
			}
				
		}
		i++;
	}
	cout<<"\n Values of "<<postfix<<" is : "<<val_stack[0];
}
