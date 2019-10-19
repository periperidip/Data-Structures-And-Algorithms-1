#include<iostream>
using namespace std;
  
void merge(int arr[], int start, int mid, int end) 
{ 
    int i, j, k; 
    int n1 = mid - start + 1; 
    int n2 =  end - mid; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[start + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
	L[n1]=numeric_limits<int>::max();
	R[n2]=numeric_limits<int>::max();
  
    i = 0;  
    j = 0; 
    k = start; 
    while (i<n1||j<n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
} 
  
void mergeSort(int arr[], int start, int end) 
{ 
    if (start < end) 
    { 
        // Same as (start+end)/2, but avoids overflow for 
        // large start and h 
        int mid = start+(end-start)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, start, mid); 
        mergeSort(arr, mid+1, end); 
  
        merge(arr, start, mid, end); 
    } 
} 
  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}
