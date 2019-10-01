#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
}*front,*back;
int count = 0;
// struct node* isempty(struct node* r)
// {
void empty()
{
    if (front == NULL)
        printf("\n queue is empty");
    else
        printf("\n queue is not empty ");
}		
void Enqueue(int value)
{
	count ++;
	struct node *nw ;
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data = value;
	nw->next = NULL;
	if(front == NULL && back == NULL)
	{
		front = nw ;
		back = nw;
	}
	else
	{
		back->next = nw;
		back = nw;
	}
	//return x;
}
void dequeue()
{
	count--;
	struct node *tp , *temp;
	if (count <= 0)
	{
        printf("\n queue is empty");
        return;
	}
	tp = front;
	while(tp->next != back)
	{
		tp = tp->next ;
	}
	//temp = back;
	back = tp;
	tp = tp->next;
	back->next = NULL;
	free(tp);
	//return tp;
}
void display()
{
	struct node *p;
	p = front ;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}
int op()
{
	return front->data;
}
int main()
{
	front = NULL;
	back = NULL;
	int value,val,e;
	while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &value);
 		switch (value)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &val);
            Enqueue(val);
            break;
        case 2:
            dequeue();
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
            if (front == NULL)
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