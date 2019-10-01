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
void quicksort(int *arr, int p, int r)
{
  int index;
  if(p >= r) 
  return;
  index = partition(arr,p,r);
  quicksort(arr,p,index-1);
  quicksort(arr,index+1,r);
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
  int N;
  printf("enter number of elements in array : ");
  scanf("%d",&N);
  int arr[N + 1];
  for(int i=0 ; i<N ; ++i)
  {
    printf("enter array element : ");
    scanf("%d" , & arr[i]);
  }
  quicksort(arr , 0 , N -1);
  Display(arr , N);
}


 