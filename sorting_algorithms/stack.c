#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
}*top,*tp;
// struct node* isempty(struct node* r)
// {
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty ");
}		
void pop()
{
	tp = top;
	if(tp == NULL)
	{
		printf("stack is empty\n");
		return ;
	}
	struct node *temp;
	temp = tp;
	tp = tp->next;
	free(temp);
	top = tp;
	//return tp;
}
void push(int value)
{
	struct node *nw ;
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data = value;
	nw->next = top;
	top = nw;
	//return x;
}
void display()
{
	struct node *p;
	p = top ;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}
int op()
{
	return top->data;
}
int main()
{
	struct node *p  ;
	top = NULL ;
	int value ,val, e, N , temp;
	// printf("enter the value\n");
	// scanf("%d",&value);
	// top = (struct node *)malloc(sizeof(struct node));
	// top->next = NULL;
	// top->data = value;
	// 
	while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &value);
 		switch (value)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
        	display();
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = op();
                printf("\n Top element : %d", e);
            }
            break;
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}