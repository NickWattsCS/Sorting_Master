#include <iostream>
#include <string>
#include <vector>
#include <map>

#ifndef NW_HEAP_SORT_H
#define NW_HEAP_SORT_H

using namespace std;

class Heap_Sort
{
  public:

    Heap_Sort(bool verbose = false);
    ~Heap_Sort();
    void print();
    void start_sort(vector<int>);
    int parent(int);
    int left(int);
    int right(int);
    bool sorted();

  private:

    map<int, int> vec;
    bool verbose;
    int heap_size;

    void heapsort();
    void build_max_heap();
    void max_heapify(int);
};

#endif
