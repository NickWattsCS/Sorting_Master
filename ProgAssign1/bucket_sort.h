#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <random>

#ifndef NW_BUCKET_SORT_H
#define NW_BUCKET_SORT_H

using namespace std;

class Bucket_Sort
{
  public:

    Bucket_Sort(bool verbose = false);
    ~Bucket_Sort();
    void print();
    void start_sort(vector<float>);
    vector<float> get_random_floats(int);

  private:

    vector<float> vec;
    map<int, float> Alist;
    map<float, vector<float>> Blist;
    bool verbose;

    void bucket_sort();
    void bucket_insertion_sort(vector<float>&);
    void bucket_dump();

};

#endif
