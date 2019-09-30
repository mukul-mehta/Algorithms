#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int partition(int *arr, int p, int r)
{
  int x, pivot, i,j,temp;
  while(x > p )
  {
  	x = rand();
  	x = x % r ;
  } 
  pivot = arr[x];
  i = x;  j = r;
  while(i < j)
  {
    while(arr[i] <= pivot && i<=r) 
      i++;
    while(arr[j] > pivot) 
      j--;
      if (i < j)
      {
        temp = arr[i]; 
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
      }
  }
  temp = arr[j];
  arr[j] = arr[x]; 
  arr[x] = temp;
  return j;
}
void quicksort(int *arr, int p, int r , int k)
{
  	int index;
  	if(p >= r)
  	{ 
  		printf("Kth  element is : %d \n",arr[p] );
  		return;
  	}
  	index = partition(arr,p,r);
 	if(index > k)
  	quicksort(arr,p,index-1,k);
  	else if(index < k)
  	quicksort(arr,index+1,r,k);
  	else
  	{
  		printf("Kth  element is : %d \n",arr[index] );
  	}
}
void Display(int *arr , int N)
{
  for(int i=0 ; i<N ; ++i)
  {
    printf("%d " , arr[i]);
  }
  printf("\n");
}
int main()
{
  int N , k;
  printf("enter number of elements in array : ");
  scanf("%d",&N);
  printf("enter Kth position : ");
  scanf("%d",&k);
  int arr[N + 1];
  for(int i=0 ; i<N ; ++i)
  {
    printf("enter array element : ");
    scanf("%d" , & arr[i]);
  }
  k = N - k;
  quicksort(arr , 0 , N -1 , k);
  //Display(arr , N);
}