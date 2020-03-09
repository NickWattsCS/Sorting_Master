#include "insertion_sort.h"

using namespace std;

Insertion_Sort::Insertion_Sort(bool print)
{ 
  verbose = print;
}

Insertion_Sort::~Insertion_Sort()
{
  if(!vec.empty())
    vec.clear();
}

void Insertion_Sort::start_sort(vector<int> unsorted)
{
  for(int i = 0; i < unsorted.size(); i++)
  {
    vec[i] = unsorted[i];
  }
  insertion_sort();
  if(verbose)
    print();
}

void Insertion_Sort::print()
{
  for(int i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << endl;
}

void Insertion_Sort::insertion_sort()
{
  int key, j = 0; 
  for(int i = 1; i < vec.size(); i++)
  {
    key = vec[i];
    j = i - 1;
    while(j > -1 && vec[j] > key)
    {
      vec[j + 1] = vec[j];
      j = j - 1;
    }
    vec[j + 1] = key;
  }
}

//2, 9, 4, 3, 7, 5, 10
