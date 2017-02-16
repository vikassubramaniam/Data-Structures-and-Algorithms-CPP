#include<iostream>
#include<string.h>
using namespace std;
int top=-1;
void push(char);
void pop();
void display();
char x;
#define n 100
char a[n];


void push(char x){
	
  if(top!=(n-1))
  {
 top++;
 a[top]=x;
	
}
	else
	{
		printf("stack is full\n");
	}
}
void pop(){
	if(top!=-1)
	{
	
	
		a[top]=x;
		top=top-1;
	
}

else
{
	printf("Not accepted\n");
	
}
}
void display (char a[])
{
int i;
if (top == -1)
{
printf ("Not accepted\n");

}
else
{
printf ("\nThe status of the stack is\n");
for (i = top; i >= 0; i--)
{
printf ("%c\n",a[i]);
}

}

}

int main()
{
int i;
   for(i=0;i<n;i++)
	  {
    scanf("%c",&a[i]);
 		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}
	else if(a[i]=='.')
	{
		break;
	}
	
}
display(a);
}
