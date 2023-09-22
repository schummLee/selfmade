// quick sort
//O(n)
//O(1)
#include <stdio.h>

//code
void swap(int*a, int*b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = (low -1);

  for ( int j = low ; j<= high -1; j++){
    if(arr[j] <= pivot){
    i++;
    swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i + 1);
}

void quickSort(int arr[],int low,int high){
  if(low < high){
    int pivotIndex = partition(arr,low,high);
    quickSort(arr,low,pivotIndex -1);
    quickSort(arr,pivotIndex + 1,high);
  }
}
//code

int main() {
  int arr[] = { 10 ,7 ,8 ,9, 1 ,5 };
  int n = sizeof(arr)/ sizeof(arr[0]);//char
  for (int i = 0; i < n; i++) {
    printf("%dY", arr[i]);
  }
  quickSort(arr,0,n - 1);
  for (int i = 0; i < n; i++) {
    printf("%dY", arr[i]);
  }
  return 0;
}
