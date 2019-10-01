#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
struct node
{
	char data;
	struct node* next;
}*top;
char st[1000];
int count = 0;
// void push(int value)
// {
// 	struct node *nw ;
// 	nw = (struct node *)malloc(sizeof(struct node));
// 	nw->data = value;
// 	nw->next = top;
// 	top = nw;
// 	//return x;
// }
void pop()
{
	struct node *temp ,*tp;
	tp = top;
	if(tp == NULL)
	{
		//printf("stack is empty\n");
		exit(0);
	}
	
	temp = tp;
	tp = tp->next;
	printf("%c" , temp->data);
	free(temp);
	top = tp;

	//return tp;
}
void display()
{
	struct node *p;
	p = top ;
	while(p != NULL)
	{
		printf("%c ",p->data);
		p = p->next;
	}
}
int main()
{
	struct node *p ,*back ;
	top = NULL ;
	char str[1000];
	scanf("%s" ,str);

	for(int i=0 ;str[i] != '\0' ; ++i)
	{
		p = (struct node* )malloc(sizeof(struct node));
		p->data = str[i] ;
		//st[i] = str[i] ;
		//printf("%c",p->data );
		p->next = NULL;
		if(top == NULL)
			top = p;
		else back->next = p;
		back = p ;
		count++;
	}
	//strrev(str);
	// for(int i=0 ;st[i] != '\0' ; ++i)
	// {
	// 	printf("%c " ,st[count - i- 1]);
	// }
	//display();
	while(1)
	{
		pop();
		count++;
		//printf("%c" , top->data);
	}
	//printf("count\n");
}