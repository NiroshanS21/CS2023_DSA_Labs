#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int high = root;
   int left = 2*root +1;
   int right = 2* root +2;

   if (left < n && arr[left]>arr[high]){
      high = left;
   }
   if (right < n && arr[right]>arr[high]){
      high = right;
   }
   if (high!= root){
      swap(arr[root], arr[high]);
      heapify(arr,n,high);
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i =n/2 - 1; i>=0;i--){
      heapify(arr,n,i);
   }

   // extracting elements from heap one by one
   for(int j =n-1; j>=0; j--){
      swap(arr[0],arr[j]);
      heapify(arr,j,0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int len;
   cout<<"Enter the length of elements: ";
   cin>>len;
   int heap_arr[len];
   cout<<"Enterthe elements: ";
   for (int i=0; i<len; i++){
      cin>>heap_arr[i];
   }
   cout<<"Input array is: "<<endl;
   displayArray(heap_arr,len);
   heapSort(heap_arr, len);
   cout << "Sorted array is: "<<endl;
   displayArray(heap_arr, len);
   return 0;
}