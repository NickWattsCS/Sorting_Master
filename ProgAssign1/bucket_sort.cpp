#include "bucket_sort.h"

using namespace std;

Bucket_Sort::Bucket_Sort(bool print) : verbose{print}
{ }

Bucket_Sort::~Bucket_Sort()
{
  if(!Alist.empty())
    Alist.clear();

  if(!Blist.empty())
    Blist.clear();

  if(!vec.empty())
    vec.clear();
}

void Bucket_Sort::print()
{
  cout << fixed << showpoint << setprecision(5);
  for(auto& item: vec)
    cout << item << " ";
  cout << endl;
}

void Bucket_Sort::start_sort(vector<float> unsorted)
{
  vector<float> temp{0};
  for(int i = 0; i < unsorted.size(); i++)
  {
    Alist[i] = unsorted.at(i);
  } 

  bucket_sort();

  if(verbose)
    print();
}

vector<float> Bucket_Sort::get_random_floats(int size)
{
  vector<float> floats;
  random_device randseed;
  mt19937 mount(randseed());
  uniform_real_distribution<float> range(0.0, 1.0);
 
  for(int i = 0; i < size; i++)
  {
    floats.push_back(range(mount));
  }

  return floats;
}

void Bucket_Sort::bucket_sort()
{
  for(auto& item: Alist)
  {
    if(item.second >= 0.0 && item.second < 0.1)
    {
      Blist[0].push_back(item.second);
    }
    else if(item.second >= 0.1 && item.second < 0.2)
    {
      Blist[0.1].push_back(item.second);
    }
    else if(item.second >= 0.2 && item.second < 0.3)
    {
      Blist[0.2].push_back(item.second);
    }
    else if(item.second >= 0.3 && item.second < 0.4)
    {
      Blist[0.3].push_back(item.second);
    }
    else if(item.second >= 0.4 && item.second < 0.5)
    {
      Blist[0.4].push_back(item.second);
    }
    else if(item.second >= 0.5 && item.second < 0.6)
    {
      Blist[0.5].push_back(item.second);
    }
    else if(item.second >= 0.6 && item.second < 0.7)
    {
      Blist[0.6].push_back(item.second);
    }
    else if(item.second >= 0.7 && item.second < 0.8)
    {
      Blist[0.7].push_back(item.second);
    }
    else if(item.second >= 0.8 && item.second < 0.9)
    {
      Blist[0.8].push_back(item.second);
    }
    else if(item.second >= 0.9 && item.second < 1.0)
    {
      Blist[0.9].push_back(item.second);
    }
  }

  for(auto& item: Blist)
  {
    bucket_insertion_sort(item.second);
  }

  bucket_dump();
}

void Bucket_Sort::bucket_insertion_sort(vector<float>& bucket)
{
  float key = 0.0;
  int i = 0;

  if(bucket.size() > 1)
  {
    for(int j = 1; j < bucket.size(); j++)
    {
      key = bucket.at(j);
      i = j - 1;
      while(i > -1 && bucket.at(i) > key)
      {
        bucket.at(i + 1) = bucket.at(i);
        i -= 1;
      }
      bucket.at(i + 1) = key;
    }
  }
}

void Bucket_Sort::bucket_dump()
{
  for(auto& item: Blist)
  {
    for(int i = 0; i < item.second.size(); i++)
    {
      vec.push_back(item.second.at(i));
    }
  }
}

