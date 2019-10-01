#include <stdio.h>
#include <stdlib.h>
int count1 = 0 , count2 = 0;
void merge (int *A, int *B, int *C, int m,int n)
{
     int i=0,j=0,k=0;
     while (i<m && j<n)
     {
        if (A[i] < B[j])
        {
         	count2++; 
         	C[k++] = A[i++];
        }
        else
        {
        	count2++;
          	C[k++] = B[j++];
        }
      }
      while (i<m) C[k++] =  A[i++];
      while (j<n) C[k++] =  B[j++];
 }
 void mergesort (int *A, int n)
 {
	  int i, j, *B;
	  if (n <= 1) return;
	  B = (int *)malloc(n*sizeof(int));
	  i = n/2;
	  mergesort(A, i);
	  mergesort(A+i, n-i);
	  merge(A, A+i, B, i, n-i);
	  for (j=0; j<n; j++)
	  { 
	  	A[j] = B[j];
	  	//printf("%d\n", A[j]);
	  }
	  free(B);
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
	int Key , k;
	for(int j=0 ;j < Num ; ++j)
	{
		Key = arr[j];
		while(count1++ && j > 0 && arr[j-1] > Key)
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
	printf("\n" );
	mergesort(arr , Num);
	for(int i=0 ; i < Num ; ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("count1 = %d ",count1);
	printf("count2 = %d ",count2);
	if(count1 > count2)
	{
		printf("run time of insertion sort is more than mergesort\n");
	}
	else if(count1 < count2)
	{
		printf("run time of insertion sort is less than mergesort\n");
	}
	else if(count1 == count2)
	{
		printf("run time of insertion sort is equal to mergesort\n");
	}
}
