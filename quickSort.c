#include <stdio.h>
#include <stdlib.h>

// ******Approach********
// Take the last element and search from start of array to last(n-1 th) element.
// try to bring all the elements smaller then last element to left side and keep aan index pointing to this.

// This function will partition on last element. Which means it will find the place of last element in sorted array 
int partition(int arr[], int left, int right){
    int x = arr[right];
    int j = left, i = left-1;// points to the index till where we have smaller elements than x.
    int temp=0;
    
    // this will scan all the elements and bring elements smaller than x to the left side.
    for(j;j<right;j++){
        if(arr[j]<=x){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Now we will place the last element at index i+1 as all elements till i is less than x.
    temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp; 
    
    // return i+1 as left of this contains elements smaller than x and in right elements are greater than x.
    return i+1;
}

void quickSort(int arr[], int left, int right){
    if(left<right){
        int part = partition(arr, left, right);
        quickSort(arr, left,part-1);
        quickSort(arr, part+1, right);
    }
}

int main(){
    int arr[] = {1,3,6,7,2,4,9,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,len-1);
    int i;
    for(i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}