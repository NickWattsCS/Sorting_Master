#include <iostream>
#include <vector>
#include <map>

#ifndef NW_COUNTING_SORT_H
#define NW_COUNTING_SORT_H

using namespace std;

class Counting_Sort
{
  public:

    Counting_Sort(bool verbose = false);
    ~Counting_Sort();
    void print();
    void start_sort(vector<int>);

  private:

    map<int, int> Alist;
    map<int, int> Blist;
    vector<int> Clist;
    bool verbose;

    int getMax();
    void counting_sort(int i);
};

#endif
