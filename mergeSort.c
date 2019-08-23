#include <stdio.h>
#include <stdlib.h>

// function that will merge two sorted arrays into single array.
void merge(int arr[], int left, int middle, int right){
    // we will create two temporary arrays
    int n1 = (middle-left) + 1, n2 = (right-middle);
    int *temp1 = (int *)malloc(n1*sizeof(int));
    int *temp2 = (int *)malloc(n2*sizeof(int));

    // Copy left subarray into temp1
    int i;
    for(i=0;i<n1;i++){
        temp1[i] = arr[left+i];
    }

    // Copy right subarray into temp2
    int j;
    for(j=0;j<n2;j++){
        temp2[j] = arr[middle+1+j];
    }

    // Now we will use both temp arrays to sort and finally merge these two subarray into one array.
    int k=0;
    i=0;
    j=0;
    // Untill one of the two temp array gets exhausted or both of them gets exhausted simultaniously.
    while(i<n1 && j<n2){
        if(temp1[i]<=temp2[j]){
            arr[left+k] = temp1[i];
            k++;
            i++;
        }
        else{
            arr[left+k] = temp2[j];
            j++;
            k++;
        }
    }
    // If temp1 is not exhausted.
    while(i<n1){
        arr[left+k] = temp1[i];
        i++;
        k++;
    }
    // If temp2 is not exhausted.
    while(j<n2){
        arr[left+k] = temp2[j];
        j++;
        k++;
    }
}

// this will do mergesort
void mergeSort(int arr[], int left, int right){
    if(right>left){
        int middle = (right+left)/2;
        mergeSort(arr, left,middle);// Sorts left subarray
        mergeSort(arr, middle+1, right); // Sorts right subarray
        merge(arr, left, middle, right); // Merges both array into one sorted array.
    }
}

int main(){
    int arr[] = {1,3,6,4,2,0,8,5,11,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, len-1);
    int i;
    for(i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
}