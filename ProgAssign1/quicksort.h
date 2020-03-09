#include <iostream>
#include <string>
#include <vector>
#include <map>

#ifndef NW_QUICK_SORT_H
#define NW_QUICK_SORT_H

using namespace std;

class Quick_Sort
{
  public:
    Quick_Sort(bool verbose = false);
    ~Quick_Sort();
    void print();
    void start_sort(vector<int>);
    
  private:
    map<int, int> vec;
    bool verbose;

    void quicksort(int, int);
    int partition(int, int);
};

#endif
