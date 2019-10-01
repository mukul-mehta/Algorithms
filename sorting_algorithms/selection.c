#include <stdio.h>
int index = 0, max;
int min(int arr[], int Num)
{
	int min = arr[0];
	for(int i=0 ; i < Num ; ++i)
	{
		if(min >= arr[i])
		{
			min = arr[i];
			index = i;
		}
	}
	arr[index] = max;
	return min;
}
int main()
{
	int Num;
	printf("enter number of elements");
	scanf("%d",&Num);
	printf("enter the elements");
	int arr[Num+1];
	for(int i=0 ; i < Num ; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sort_arr[Num + 1];
	int Max = arr[0];
	for(int i=1 ; i < Num ; ++i)
	{
		if(Max <= arr[i]) 
		{
			Max = arr[i];
		}
	}
	max = Max;
	for(int i =0 ; i < Num ; ++i)
	{
		sort_arr[i] = min(arr,Num);
		printf("%d ",sort_arr[i] );
	}
}
