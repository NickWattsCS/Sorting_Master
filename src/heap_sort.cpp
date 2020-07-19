#include "heap_sort.h"

using namespace std;

Heap_Sort::Heap_Sort(bool print) : verbose{print}, heap_size{0}
{ }

Heap_Sort::~Heap_Sort()
{
  if(!vec.empty())
    vec.clear();
}

void Heap_Sort::print()
{
  for(auto& item: vec)
    cout << item.second << " ";
  cout << endl;
}

void Heap_Sort::start_sort(vector<int> unsorted)
{
  for(int i = 0; i < unsorted.size(); i++)
    vec[i] = unsorted[i];

  heapsort();

  if(verbose)
    print();

  if(!sorted())
  {
    cout << "Error: array not sorted by heap sort.\n";
    exit(1);
  }
}

int Heap_Sort::parent(int i)
{
  return i/2;
}

int Heap_Sort::left(int i)
{
  if(i == 0)
    return 1;
  else if(2*i < vec.size())
    return 2*i;
  else
    return -1;
}

int Heap_Sort::right(int i)
{
  if(i == 0)
    return 2;
  else if(2*i + 1 < vec.size())
    return 2*i + 1;
  else
    return -1;
}

void Heap_Sort::heapsort()
{
  int temp = 0;
  build_max_heap();
  for(int i = (vec.size() - 1); i > 0; i--)
  {
    temp = vec[0];
    vec[0] = vec[i];
    vec[i] = temp;
    heap_size-=1;
    max_heapify(0);
  }
}

void Heap_Sort::build_max_heap()
{
  heap_size = vec.size();
  for(int i = vec.size()/2; i >= 0; i--)
    max_heapify(i);
}

void Heap_Sort::max_heapify(int i)
{
  int l, r, max, temp = 0;
  l = left(i);
  r = right(i);

  if(l != -1 && l < heap_size && vec[l] > vec[i])
  {
    max = l;
  }
  else
  {
    max = i;
  }

  if(r != -1 && r < heap_size && vec[r] > vec[max])
  {
    max = r;
  }

  if(max != i)
  {
    temp = vec[i];
    vec[i] = vec[max];
    vec[max] = temp;
    max_heapify(max);
  }
}

bool Heap_Sort::sorted()
{
  for(int i = 0; i < vec.size(); i++)
    if(i + 1 < vec.size())
      if(vec.at(i) > vec.at(i + 1))
        return false;
  return true;
}