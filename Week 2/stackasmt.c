#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sNode
{
char data;
struct sNode *next;
};
void push(struct sNode** top_ref, int new_data)
{
struct sNode* new_node =(struct sNode*) malloc(sizeof(struct sNode));
if (new_node == NULL)
{
	printf("Stack overflow \n");
	getchar();
	exit(0);
}		 
new_node->data = new_data;
new_node->next = (*top_ref); 
(*top_ref) = new_node;
}
int pop(struct sNode** top_ref)
{
char res;
struct sNode *top;
if (*top_ref == NULL)
{
	printf("Stack overflow \n");
	getchar();
	exit(0);
}
else
{
	top = *top_ref;
	res = top->data;
	*top_ref = top->next;
	free(top);
	return res;
}
}
int isMatchingPair(char character1, char character2)
{
if (character1 == '(' && character2 == ')')
	return 1;
else
	return 0;
}
int areParenthesisBalanced(char c[],int length)
{
int i = 0;
struct sNode *stack = NULL;
while (c[i])
{
	
	if ( c[i] == '(')
		push(&stack, c[i]);

		if (c[i] == ')')
	{
			if (stack == NULL)
	     	return 0; 
	     //push(&stack, c[i]);
	     
            if ( !isMatchingPair(pop(&stack), c[i]) )
		return 0;
		
		
	}
	i++;
}
	
if (stack == NULL)
	return 1; 
else
	return 0;
} 
int main()
{

int length;char c[100];
printf("Enter a string of paranthesis: ");
scanf("%s",c);
//printf("%s",c);
length = strlen(c);
//printf("%d",length);

if (areParenthesisBalanced(c,length))
	printf("\n Balanced ");
else
	printf("\n Not Balanced "); 
return 0;
} 


