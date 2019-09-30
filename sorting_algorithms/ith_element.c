#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int grp[] = {3,5,7};
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}   
int partition(int arr[], int l, int r, int Med) 
{ 
    // Search for x in arr[l..r] and move it to end 
    int i; 
    for (i = l; i < r; i++) 
        if (arr[i] == Med) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    // Standard partition algorithm 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= Med) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int findMedian(int arr[], int n) 
{ 
    qsort(arr, n , sizeof(int) , compare);  
    return arr[n/2];    
}    
int find_kth_Smallest(int *arr, int l, int r, int k, int flag) 
{
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r - l + 1 ; 
        int i, median[n];  
        for (i = 0; i < n/grp[flag]; i++) 
            median[i] = findMedian(arr + l + i * grp[flag], grp[flag]); 
        if (i * grp[flag] < n) 
        { 
            median[i] = findMedian(arr + l + i * grp[flag], n % grp[flag]);  
            i++; 
        }
        int Med; 
        if(i == 1)
        	Med = median[i - 1];
        else 
        	Med = findMedian(median , i );
  		int position = partition(arr, l, r, Med); 
        if (position - l == k-1) 
            return arr[position]; 
        if (position - l > k-1)  
            return find_kth_Smallest(arr, l, position - 1, k , flag); 
        return find_kth_Smallest(arr, position + 1, r, k - (position - l) - 1 , flag); 
    } 
    return 0; 
} 
int main()
{
	int N , k;
	printf("Number of elements");
	scanf("%d",&N);
	printf("Enter k");
	scanf("%d",&k);
	int arr[N];
	printf("Enter all numbers\n");
	for(int i = 0 ; i < N ; ++i)
	{
		int x;
		scanf("%d",&x);
		arr[i] = x;
	}
	for(int flag = 0 ; flag < 3 ; ++flag)
	{
		int ans = find_kth_Smallest(arr,0,N - 1,k ,flag);
		printf("\n %d th smallest number in the arrat using grouping of %d is %d\n",k , flag , ans);
	}
}