#include <iostream>
#include <vector>
#include <map>

#ifndef NW_INSERTION_SORT_H
#define NW_INSERTION_SORT_H

using namespace std;

class Insertion_Sort
  {
    public:
      Insertion_Sort(bool verbose = false);
      ~Insertion_Sort();
      void start_sort(vector<int>);
      void print();
      bool sorted();
    
    private:
      map<int, int> vec;
      void insertion_sort();
      bool verbose;
  };

#endif
