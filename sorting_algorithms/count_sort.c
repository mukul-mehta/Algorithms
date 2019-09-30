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
void count_sort(int *arr , int n)
{
	int max = arr[0];
	for(int i = 0 ; i < n ; ++i)
	{
		if(max < arr[i])
			max = arr[i];
	}
	int temp[max+1] , re[n];
	for(int i = 0 ; i <= max ; ++i)
	{
		temp[i]=0;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		temp[arr[i]] = temp[arr[i]] + 1;
	}
	int x = 0;
	for(int i = 0 ; i <= max ; ++i)
	{
		while(temp[i] != 0)
		{
			re[x] = i;
			x++;
			temp[i]--;
		}
	}
	Display(re , n);
}
int main()
{
	int N;
  	printf("enter number of elements in array : ");
 	scanf("%d",&N);
  	int arr[N + 1];
  	for(int i=0 ; i<N ; ++i)
  	{
    	//printf("enter array element : ");
    	scanf("%d" , & arr[i]);
  	}
  	count_sort(arr ,N);
}