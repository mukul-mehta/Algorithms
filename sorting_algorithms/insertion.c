#include <stdio.h>
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
	int Key , k;
	for(int j=0 ;j < Num ; ++j)
	{
		Key = arr[j];
		while(j > 0 && arr[j-1] > Key)
		{
			arr[j] = arr[j-1];
			j = j-1;
		}
		arr[j] = Key;
	}
	for(int i=0 ; i < Num ; ++i)
	{
		printf("%d ",arr[i]);
	}
}
