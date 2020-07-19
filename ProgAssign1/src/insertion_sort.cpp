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

  if(!sorted())
  {
    cout << "Error: array not sorted by insertion sort.\n";
    exit(1);
  }
}

void Insertion_Sort::print()
{
  for(int i = 0; i < vec.size(); i++)
    cout << vec.at(i) << " ";
  cout << endl;
}

void Insertion_Sort::insertion_sort()
{
  int key, j = 0; 
  for(int i = 1; i < vec.size(); i++)
  {
    key = vec.at(i);
    j = i - 1;
    while(j > -1 && vec.at(j) > key)
    {
      vec.at(j + 1) = vec.at(j);
      j = j - 1;
    }
    vec.at(j + 1) = key;
  }
}

bool Insertion_Sort::sorted()
{
  for(int i = 0; i < vec.size(); i++)
  {
    if(i + 1 < vec.size())
    {
      if(vec.at(i) > vec.at(i + 1))
      {
        return false;
      }
    }
  }
  return true;
}
