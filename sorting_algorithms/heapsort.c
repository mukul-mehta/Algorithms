#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Display(int *arr , int N)
{
  for(int i=0 ; i<N ; ++i)
  {
    printf("%d " , arr[i]);
  }
  printf("\n");
}
void max_heapify(int *arr , int n , int i)
{
	int Max = i; 
    int left = 2*i + 1;  
    int right = 2*i + 2; 
    if (left < n && arr[left] > arr[Max]) 
        Max = left; 
    if (right < n && arr[right] > arr[Max]) 
        Max = right; 
    if (Max != i) 
    { 
        int temp = arr[i] ;
		arr[i] = arr[Max] ;
		arr[Max] = temp ; 
        max_heapify(arr, n, Max); 
    } 
}
void build_max_heap(int *arr , int N)
{
	for (int i = N / 2 - 1; i >= 0; i--) 
        max_heapify(arr, N, i); 
}
void heapsort(int *arr , int N)
{
	build_max_heap(arr, N);
	//max_heapify(arr , N -1 , 0);
	//Display(arr , N);
	int  temp;
	for(int size = N -1 ;  size >= 0 ; size--)
	{
		temp = arr[0] ;
		arr[0] = arr[size] ;
		arr[size] = temp ;
		max_heapify(arr , size , 0) ;
		//Display(arr , N);
	}
}
int main()
{
	int N;
  	printf("enter number of elements in array : ");
  	scanf("%d",&N);
  	int arr[N + 1];
  	for(int i=0 ; i<N ; ++i)
  	{
    	printf("enter array element : ");
    	scanf("%d" , & arr[i]);
  	}
  	heapsort(arr , N);
  	Display(arr , N);
}