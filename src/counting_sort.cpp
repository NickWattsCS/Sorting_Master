#include "counting_sort.h"

using namespace std;

Counting_Sort::Counting_Sort(bool print) : verbose{print}, Clist{0} 
{}

Counting_Sort::~Counting_Sort()
{
  if(!Alist.empty())
    Alist.clear();
  if(!Blist.empty())
    Blist.clear();
  if(!Clist.empty())
    Clist.clear();
}

void Counting_Sort::print()
{
  for(auto& item: Blist)
    cout << item.second << " ";
  cout << endl;
}

void Counting_Sort::start_sort(vector<int> unsorted)
{
  for(int i = 0; i < unsorted.size(); i++)
    Alist[i] = unsorted.at(i);

  counting_sort(getMax());

  if(verbose)
    print();

  if(!sorted())
  {
    cout << "Error: array not sorted with counting sort.\n";
    exit(1);
  }
}

int Counting_Sort::getMax()
{
  int max = 0;
  for(auto& item: Alist)
  {
    if(item.second > max)
    {
      max = item.second;
    }
  }
  return max + 1;
}

void Counting_Sort::counting_sort(int k)
{
  Clist.resize(k);

  for(int j = 0; j < Alist.size(); j++)
  {
    Clist.at(Alist.at(j)) += 1;
  }

  for(int i = 0; i < Clist.size(); i++)
  {
    if(i > 0)
    {
      Clist.at(i) = Clist.at(i) + Clist.at(i - 1);
    }
  }

  for(int j = Alist.size() - 1; j >= 0; j--)
  {
    Blist[Clist.at(Alist.at(j))] = Alist.at(j);
    Clist.at(Alist.at(j)) = Clist.at(Alist.at(j)) - 1;
  }
}

bool Counting_Sort::sorted()
{
  int current = 0, next = 0;
  for(map<int, int>::iterator itr = Blist.begin(); itr != Blist.end(); ++itr)
  {
    if((++itr)-- != Blist.end())
    {
      current = (itr++)->second;
      next = (itr--)->second;
        if(current > next)
          return false;
    }
  }
  return true;
}
