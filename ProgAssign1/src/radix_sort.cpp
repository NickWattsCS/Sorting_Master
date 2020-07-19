#include "radix_sort.h"

using namespace std;

Radix_Sort::Radix_Sort(bool print) : verbose{print}, Tlist{0}
{ }

Radix_Sort::~Radix_Sort()
{
  if(!vec.empty())
    vec.clear();
  if(!Rlist.empty())
    Rlist.clear();
  if(!Slist.empty())
    Slist.clear();
  if(!Tlist.empty())
    Tlist.clear();
}

void Radix_Sort::print()
{
  for(auto& item: vec)
  {
    cout << item.second << " ";
  }
  cout << endl;
}

void Radix_Sort::start_sort(vector<int> unsorted)
{
  int max_digit = 0;
  for(int i = 0; i < unsorted.size(); i++)
  {
    Rlist[i] = unsorted.at(i);

    if(get_num_digits(Rlist.at(i)) > max_digit)
      max_digit = get_num_digits(Rlist.at(i));

  }
  radix_sort(max_digit);

  if(verbose)
    print();

  if(!sorted())
  {
    cout << "Error: array is not sorted by radix sort.\n";
    exit(1);
  }
}

int Radix_Sort::get_num_digits(int value)
{
  if(value >= 0 && value < 10)
    return 1;
  else if(value >= 10 && value < 100)
    return 2;
  else if(value >= 100 && value < 1000)
    return 3;
  else if(value >= 1000 && value < 10000)
    return 4;
  else if(value >= 10000 && value < 65536)
    return 5;
}

int Radix_Sort::digit_at(int value, int place)
{
  int digit = 0;
  double d_place = static_cast<double> (place);
  int base_ten_plus = static_cast<int> (pow(10.00,(d_place + 1.0)));
  int base_ten = static_cast<int> (pow(10.00, d_place));
  if(place > 0)
  {
    digit = value % base_ten_plus;
    digit /= base_ten;
  }
  else
    digit = value % base_ten_plus;
  return digit;
}

int Radix_Sort::get_max(int place)
{
  int max = 0;
  int cur_digit = 0;

  for(auto& item: Rlist)
  {
    cur_digit = digit_at(item.second, place);

    if(cur_digit > max)
      max = cur_digit;

  }
  return max;
}

void Radix_Sort::radix_sort(int digits)
{
  for(int place = 0; place < digits; place++)
  {
    radix_counting_sort(place);
    Rlist = Slist;
  }
  vec = Slist;
}

void Radix_Sort::radix_counting_sort(int place)
{
  int tVal = 0;

  Tlist.resize(get_max(place) + 1);

  for(int i = 0; i < Rlist.size(); i++)
  {
    tVal = digit_at(Rlist.at(i), place);
    Tlist.at(tVal) += 1;
  }

  for(int j = 0; j < Tlist.size(); j++)
  {
    if(j > 0)
      Tlist.at(j) += Tlist.at(j - 1);
  }

  for(int j = Rlist.size() - 1; j >= 0; j--)
  {
    tVal = digit_at(Rlist.at(j), place);
    Slist[Tlist.at(tVal) - 1] = Rlist.at(j);
    Tlist.at(tVal) -= 1;
  }

  if(!Tlist.empty())
    Tlist.clear();
}

bool Radix_Sort::sorted()
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
