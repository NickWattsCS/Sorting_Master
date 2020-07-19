#include "quicksort.h"

using namespace std;

Quick_Sort::Quick_Sort(bool print) : verbose{print}
{ }

Quick_Sort::~Quick_Sort()
{
  if(!vec.empty())
    vec.clear();
}

void Quick_Sort::print()
{
  for(auto& item: vec)
    cout << item.second << " ";
  cout << endl;
}

void Quick_Sort::start_sort(vector<int> unsorted)
{
  for(int i = 0; i < unsorted.size(); i++)
    vec[i] = unsorted[i];

  quicksort(0, vec.size() - 1);

  if(verbose)
    print();

  if(!sorted())
  {
    cout << "Error: array is not sorted by quicksort.\n";
    exit(1);
  }
}

void Quick_Sort::quicksort(int p, int r)
{
  int q = 0;
  q = partition(p, r);

  if(p < r)
  {
    if(q - 1> -1)
      quicksort(p, q - 1);
    quicksort(q, r);
  }
}

int Quick_Sort::partition(int p, int r)	
{
  int x, i, temp = 0;
  x = vec.at(r);
  i = p - 1;

  for(int j = p; j < r; j++)
  {
      if(vec.at(j) <= x)
      {
        i += 1;
        temp = vec.at(i);
        vec.at(i) = vec.at(j);
        vec.at(j) = temp;
      }
  }
  if(i + 1 != vec.size())
  {
    temp = vec.at(i + 1);
    vec.at(i + 1) = vec.at(r);
    vec.at(r) = temp;
    return i + 1;	
  }
  else
    return i;
}

bool Quick_Sort::sorted()
{
  for(int i = 0 ; i < vec.size(); i++)
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