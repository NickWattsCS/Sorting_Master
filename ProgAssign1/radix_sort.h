#include <iostream>
#include <cmath>
#include <vector>
#include <map>

#ifndef NW_RADIX_SORT_H
#define NW_RADIX_SORT_H

using namespace std;

class Radix_Sort
{
  public:

    Radix_Sort(bool verbose = false);
    ~Radix_Sort();
    void print();
    void start_sort(vector<int>);

  private:

    map<int, int> vec;
    map<int, int> Rlist;
    map<int, int> Slist;
    vector<int> Tlist;
    bool verbose;

    int get_max(int);
    int get_num_digits(int);
    int digit_at(int, int);
    void radix_sort(int);
    void radix_counting_sort(int);    
};

#endif
