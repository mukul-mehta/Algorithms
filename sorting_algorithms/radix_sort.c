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
void count_sort(int *arr , int n , int exp)
{
	
	int temp[10] , re[n];
	for(int i = 0 ; i < 10 ; ++i)
	{
		temp[i]=0;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		temp[(arr[i] / exp ) % 10] = temp[(arr[i] / exp ) % 10] + 1;
	}
	for(int i = 1 ; i < 10 ; ++i)
	{
		temp[i] = temp[i] + temp[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) 
    { 
        re[temp[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        temp[ (arr[i]/exp)%10 ]--; 
    } 
	// int x = 0;
	// for(int i = 0 ; i <= max ; ++i)
	// {
	// 	while(temp[i] != 0)
	// 	{
	// 		re[x] = i;
	// 		x++;
	// 		temp[i]--;
	// 	}
	// }
	for(int  i = 0 ; i < n ; ++i)
		arr[i] = re[i];
}
void radix_sort(int *arr , int n)
{
	int max = arr[0];
	for(int i = 0 ; i < n ; ++i)
	{
		if(max < arr[i])
			max = arr[i];
	}
	for (int exp = 1; max/exp > 0; exp *= 10) 
        count_sort(arr, n, exp); 	
    Display(arr, n);
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
  	radix_sort(arr ,N);
}





