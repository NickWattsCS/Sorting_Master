#include "merge_sort.h"

using namespace std;

Merge_Sort::Merge_Sort(bool print)
{
  verbose = print;
}

Merge_Sort::~Merge_Sort()
{
  if(!vec.empty())
    vec.clear();
}

void Merge_Sort::print()
{
  for(auto& item: vec)
    cout << item.second << " ";
  cout << endl;
}

void Merge_Sort::start_sort(vector<int> unsorted)
{
  for(int i = 0; i < unsorted.size(); i++)
    vec[i] = unsorted[i];
  merge_sort(0, vec.size() - 1);
  if(verbose)
    print();
}

void Merge_Sort::merge_sort(int p, int r)
{
  int q = 0;
  if(p < r)
  {
    q = (p + r)/2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
  }
}

void Merge_Sort::merge(int p, int q, int r)
{
  int i, j = 0;
  int n = q - p + 1;  //first pass: n = 0 - 0 + 1 = 1
  int m = r - q;      //first pass: m = 1 - 0 = 1
  int* lArray = new int [n + 1];  //size = 1
  int* rArray = new int [m + 1];  //size = 1

  for(i = 0; i < n; i++)
  {
    lArray[i] = vec[p + i];
  }

  for(j = 0; j < m; j++)
  {
    rArray[j] = vec[q + j + 1];
  }

  i = 0;
  j = 0;
  lArray[n] = -1;
  rArray[m] = -1;

  for(int k = p; k <= r; k++)
  {
    if(lArray[i] != -1 && rArray[j] != -1)
    {
      if(lArray[i] <= rArray[j])
      {
        vec[k] = lArray[i];
        i++;
      }
      else
      {
        vec[k] = rArray[j];
        j++;
      }
    }
    else
    {
      if(lArray[i] == -1 && rArray[j] != -1)
      {
        vec[k] = rArray[j];
        j++;
      }
      else if(rArray[j] == -1 && lArray[i] != -1)
      {
        vec[k] = lArray[i];
        i++;
      }
    }
  }

  delete[] lArray;
  delete[] rArray;
}
