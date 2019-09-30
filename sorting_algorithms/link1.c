#include <stdio.h>
#include <stdlib.h>
//struct node* delete(struct node * r, int value);
struct node{
	int data;
	struct node *next;
};
struct node *dlete(struct node *r, int value)
{   
	struct node *p, *q;
    p =r;
    q = p;
    while(p!=NULL) 
    {
       if (p->data == value)
       {
           if (p==r) 
           	r = p->next;
           else  q->next = p->next;
            p->next = NULL;
           free(p);
            return r;  
        }
      else 
      	{ 
      		q = p;
            p = p->next;  
      	}
   }
   return r;
}
struct node *rverse(struct node *head)
{
	struct node *p = head; 
    struct node *q = NULL, *r = NULL; 
 	while (p!= NULL) 
        { 
            r = p->next; 
  
            // Reverse current node's pointer 
            p->next = q; 
  
            // Move pointers one position ahead. 
            q = p; 
            p = r; 
        } 
        head = q; 
        return head;
}
struct node *front(struct node *head)
{
	struct node *start;
	int x;
	start = (struct node *)malloc(sizeof(struct node));
	printf("\n");
	printf("enter the number that should at the begining ");
	scanf("%d", &x);
	start->data = x;
	start->next = head ;	
}
int main()
{
	int N;
	printf("enter the size of link list ");
	scanf("%d",&N);
	struct node *back,*head = NULL,*p,*q,*start,*end,*nw,*r,*s,*t;
	int x,y,z,k,j;
	for(int i=0 ; i < N; ++i)
	{
		p = (struct node* )malloc(sizeof(struct node));
		printf("enter the number ");
		scanf("%d", &p->data);
		p->next = NULL ;
		if(head == NULL)
			head = p;
		else back->next = p;
		back = p ;
	}
	q = head;
	for( int i=0 ; i < N ; ++i)      // Printing the original link list
	{
		printf("%d ",q->data);
		q = q->next;
	}//https://mail.google.com/mail/u/0/
	start = front(head);             
	end = (struct node *)malloc(sizeof(struct node));        //adding the end elements
	printf("enter the number that should at the end " );
	scanf("%d", &y);
	end->data = y;
	q = start;
	for( int i=0 ; i < N ; ++i)
	{
		q = q->next;
	}
	q->next = end ;
	end->next = NULL;
	N = N + 2 ;
	s = start;
	for( int i=0 ; i < N ; ++i)//-print
	{
		printf("%d ",s->data);
		s = s->next;
	}
	printf("\nenter the k th position ");                    //adding new element at kth position
	scanf("%d",&k);
	printf("enter the data ");
	scanf("%d",&z);
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data = z;
	r = start;
	for( int i=0 ; i < k-2 ; ++i)
	{
		r = r->next;
	}
	t = r->next;
	r->next = nw;
	nw->next = t;
	s = start;
	for( int i=0 ; i < N+1 ; ++i)//-print
	{
		printf("%d ",s->data);
		s = s->next;
	}
	printf("enter the value to be deleted ");
	scanf("%d",&j);
	t = dlete(start,j);
	for( int i=0 ; i < N ; ++i)//-print
	{
		printf("%d ",t->data);
		t = t->next;
	}
	printf("\n");
	printf("Reverse order \n" );
	t = rverse(start);
	for( int i=0 ; i < N ; ++i)//-print
	{
		printf("%d ",t->data);
		t = t->next;
	}
}
