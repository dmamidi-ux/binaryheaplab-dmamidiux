// heap.cpp
// Devesh Mamidi

#include "heap.h"
#include <iostream>
using std::cout;


void Heap::bubbleDown(int index) {
    int n = vdata.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < n && vdata[left] < vdata[smallest])
            smallest = left;
        if (right < n && vdata[right] < vdata[smallest])
            smallest = right;

        if (smallest != index) {
            std::swap(vdata[index], vdata[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}


// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start, end);
  int n = vdata.size();
  for (int i = n/2 - 1; i >= 0; i--) {
    bubbleDown(i);
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int i = vdata.size() - 1;
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (vdata[parent] > vdata[i]) {
      std::swap(vdata[parent], vdata[i]);
      i = parent;
    }
    else {
      break;
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  std::swap(vdata[0], vdata[vdata.size() - 1]);
  vdata.pop_back();
  bubbleDown(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    