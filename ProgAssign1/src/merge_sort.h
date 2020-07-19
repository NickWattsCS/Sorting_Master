#include <iostream>
#include <vector>
#include <map>

#ifndef NW_MERGE_SORT_H
#define NW_MERGE_SORT_H

using namespace std;

class Merge_Sort
{
  public:
    Merge_Sort(bool verbose = false);
    ~Merge_Sort();
    void start_sort(vector<int>);
    void print();
    bool sorted();

  private:
    map<int, int> vec;
    bool verbose;
    void merge(int, int, int);
    void merge_sort(int, int);
};

#endif
