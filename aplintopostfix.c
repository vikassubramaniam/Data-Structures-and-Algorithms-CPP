#include<stdio.h>
# include <string.h>
char postfix[100];
char infix[100];
char opstack[100]; /* operator stack */
int i, j, top = 0;
int lesspriority(char op, char op_at_stack)
{
int k;
int pv1; /* priority value of op */
int pv2; /* priority value of op_at_stack */
char operators[] = {'+', '-', '*', '/', '%', '^', '(' };
int priority_value[] = {0,0,1,1,2,3,4};
if( op_at_stack == '(' )
return 0;
for(k = 0; k < 6; k ++)
{
if(op == operators[k])
pv1 = priority_value[k];
}
for(k = 0; k < 6; k ++)
{
if(op_at_stack== operators[k])
pv2 = priority_value[k];
}
if(pv1 < pv2)
return 1;
else
return 0;
}

void push(char op) 
{
if(top == 0)
{
opstack[top] = op;
top++;
}
else
{
if(op != '(' )
{
while(lesspriority(op, opstack[top-1]) == 1 && top > 0)
{
postfix[j] = opstack[--top];
j++;
}
}
opstack[top] = op; 
top++;
}
}
pop()
{
while(opstack[--top] != '(' ) 
{
postfix[j] = opstack[top];
j++;
}
}
void main()
{
char ch;
printf("\n Enter Infix Expression : ");
gets(infix);
while( (ch=infix[i++]) != '\0')
{
switch(ch)
{
case ' ' : break;
case '(' :
case '+' :
case '-' :
case '*' :
case '/' :
case '^' :
case '%' :
push(ch); 
break;
case ')' :
pop();
break;
default :
postfix[j] = ch;
j++;
}
}
while(top >=0)
{
postfix[j] = opstack[--top];
j++;
}
postfix[j] = '\0';
printf("\n Infix Expression : %s ", infix);
printf("\n Postfix Expression : %s ", postfix);

}

