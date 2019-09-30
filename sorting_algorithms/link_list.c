#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
int main()
{
	int N;
	printf("enter the size of link list ");
	scanf("%d",&N);
	struct node *back,*head = NULL,*p,*q,*start,*end,*nw,*r,*s,*t;
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
	for( int i=0 ; i < N ; ++i)//-print
	{
		printf("%d ",q->data);
		q = q->next;
	}
	start = (struct node *)malloc(sizeof(struct node));
	printf("enter the number that should at the begining");
	int x,y,z,k;
	scanf("%d", &x);
	start->data = x;
	start->next = head ;
	end = (struct node *)malloc(sizeof(struct node));
	printf("enter the number that should at the end" );
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


	printf("enter the k th position");
	scanf("%d",&k);
	printf("enter the data");
	scanf("%d",&z);
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data = z;


	r = start;
	for( int i=0 ; i < k ; ++i)
	{
		r = r->next;
	}
	t = r->next;
	printf("a" );
	
	nw->next = t;
	r->next = nw;
	

	s = start;
	for( int i=0 ; i < N+1 ; ++i)//-print
	{
		printf("%d ",q->data);
		q = q->next;
	}




	r = start;
	for( int i=0 ; i < N+2 ; ++i)//-print
	{
		printf("%d ",r->data);
		r = r->next;
	}
}