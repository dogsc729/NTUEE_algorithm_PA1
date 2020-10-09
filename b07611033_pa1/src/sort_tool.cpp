// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for(int j=1;j<=data.size();j++){
        int key = data[j];
        int i = j-1;
        while(i>0&&data[i]>key){
            data[i+1] = data[i];
            i = i-1;
        }
        data[i+1] = key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if(low<high){
        int mid = Partition(data,low,high);
        QuickSortSubVector(data,low,mid-1);
        QuickSortSubVector(data,mid+1,high);
    }
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int x = data[high];
    int i = low-1;
    for(int j = low;low<high;j++){
        if(data[j]<=x){
            i++;
            swap(data[i],data[j]);
        }
    }
    swap(data[i+1],data[high]);
    return (i+1); 
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    // test base case; size of vector equals 1
  if ( ( high - low ) >= 1 ) // if not base case
    {
      int middle1;  // calculate middle of vector
      int middle2;  // calculate next element over
      middle1 = (low + high)/2;
      middle2 = middle1 + 1;

      //TODO : recursive function call to split vector in half; sort each half (recursive calls)
      MergeSortSubVector(data,low,middle1);              // first half of vector      
      MergeSortSubVector(data,middle2,high);               // second half of vector    
      
     
      // merge two sorted vectors after split calls return
      Merge( data,low, middle1, middle2, high );
   } // end if
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int leftIndex = low; // index into left subvector              
  int rightIndex = middle2; // index into right subvector         
  int combinedIndex = low; // index into temporary working vector
  vector< int > combined( data.size() ); // working vector              
      
  while ( leftIndex <= middle1 && rightIndex <= high )
    {
      // place smaller of two current elements into result
      // and move to next space in vector
      if(data[leftIndex] <= data[rightIndex]){
        combined[combinedIndex] = data[leftIndex];
        combinedIndex++;
        //combined[combinedIndex] = data[rightIndex];
        leftIndex++;
      }
      else{
        combined[combinedIndex] = data[rightIndex];
        combinedIndex++;
        //combined[combinedIndex] = data[leftIndex];
        rightIndex++;
      }
    } // end while
  
  if ( leftIndex == middle2 ) // if at end of left vector          
    {                                                               
      // copy in rest of right vector
      while(rightIndex <= high){
        combined[combinedIndex] = data[rightIndex];
        combinedIndex++;
        rightIndex++;
      }
    } // end if                                                     
  else // at end of right vector                                   
    {                                                               
       // copy in rest of left vector
       while(leftIndex <= middle1){
         combined[combinedIndex] = data[leftIndex];
         combinedIndex++;
         leftIndex++;
       }
    } // end else                                                   
  
  //TODO : copy values back into original vector
  for(int i=low;i<=high;i++){
    data[i] = combined[i];
  }
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
}
