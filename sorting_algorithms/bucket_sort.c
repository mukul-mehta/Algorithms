#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min , max ;
void Display(int *arr , int N)
{
  for(int i=0 ; i<N ; ++i)
  {
    printf("%d " , arr[i]);
  }
  printf("\n");
}
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
void bucket_sort(int *arr ,int n , int k)
{
	int count[n];
	int result[n] , x = 0 ,z = 0;
	for(int y = min  ; y <= max ; y = y + k)
	{
		x = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			if(arr[i] >= y && arr[i] < y + k)
			{
				count[x] = arr[i];
				x++;
			}	
		}
		int t = 0;
		quicksort(count , 0 , x - 1);
		//Display(count , x );
		for(int j = z ; j < x + z ; ++ j)
		{
			result[j]=count[t];
			t++;
		}
		//Display(result , n);
		z = z + x ;
	}
	Display(result , n);
}
int main()
{
	int N , T;
  	printf("enter number of elements in array : ");
 	scanf("%d",&N);
 	printf("enter number of buckets : ");
 	scanf("%d",&T);
  	int arr[N + 1];
  	for(int i=0 ; i<N ; ++i)
  	{
    	//printf("enter array element : ");
    	scanf("%d" , & arr[i]);
  	}
  	max = arr[0];
	for(int i = 0 ; i < N ; ++i)
	{
		if(max < arr[i])
			max = arr[i];
	}
	min = arr[0];
	for(int i = 0 ; i < N ; ++i)
	{
		if(min > arr[i])
			min = arr[i];
	}
	int k = (max - min) / T;
	printf("%d\n", k);
  	bucket_sort(arr , N , k);
}