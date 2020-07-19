/*
Nicholas Watts
sort.cpp: A main file that parses flags to determine which sort to use before
evoking that sort's class functions.
*/

#include <ctime>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <unistd.h>
#include <getopt.h>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "quicksort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"

using namespace std;

static int size;

void initMapFlags(map<string, bool>&);
void usage();
bool flagCheck(map<string, bool>&);
void getVectorFromFile(vector<int>&, fstream&);
void randomIntVec(vector<int>&, int);
void sortMaster(vector<int>&, map<string, bool>, int);

int main(int argc, char** argv)
{

  map<string, bool> flags;
  static int size_flag;
  static int list_flag;
  static int print_flag;
  static int usage_flag;

  int curflag = 0;
  vector<int> vec;

  opterr = 0;

  initMapFlags(flags);
  while(1)
  {
    static struct option long_options[] =
    {
      {"list",            required_argument,   &list_flag,  1},
      {"size",            required_argument,   &size_flag,  1},
      {"verbose",         no_argument,         &print_flag, 1},
      {"help",            no_argument,         &usage_flag, 1},
      {"insertion_sort",  no_argument,         0,          'i'},
      {"merge_sort",      no_argument,         0,          'm'},
      {"heap_sort",       no_argument,         0,          'h'},
      {"quicksort",       no_argument,         0,          'q'},
      {"counting_sort",   no_argument,         0,          'c'},
      {"radix_sort",      no_argument,         0,          'r'},
      {"bucket_sort",     no_argument,         0,          'b'},
      {0, 0, 0, 0}
    };

    int option_index = 0;

    curflag = getopt_long(argc, argv, "imhqcrbvn:", long_options, &option_index);

    if(curflag == -1)
      break;

    if(size_flag)
    {
      !list_flag;
      flags["list"] = false;
    }
    else if(list_flag)
    {
      !size_flag;
      flags["random"] = false;
    }

    switch(curflag)
    {

      case 0:
        if(long_options[option_index].name == "list")
        {
          fstream fin;
          fin.open(optarg);
          getVectorFromFile(vec, fin);
          fin.close();  
          flags["list"] = true;
        }
        else if(long_options[option_index].name == "size")
        {
          if(optarg)
            size = atoi(optarg);
          else
          {
            cout << "Error: size expected, not given." << endl;
            usage();
            return 1;
          }
          list_flag = 0;
          flags["list"] = false;
          flags["random"] = true;
        }
        else if(long_options[option_index].name == "verbose")
          flags["print"] = true;
        else if(long_options[option_index].name == "help")
        {
          usage();
          return 0;
        }
        break;

      case 'i':
        flags["i"] = true;
        break;
      case 'm':
        flags["m"] = true;
        break;
      case 'h':
        flags["h"] = true;
        break;
      case 'q':
        flags["q"] = true;
        break;
      case 'c':
        flags["c"] = true;
        break;
      case 'r':
        flags["r"] = true;
        break;
      case 'b':
        flags["b"] = true;
        break;
      case 'v':
        print_flag = 1;
        flags["print"] = true;
        break;
      case 'n':
        if(optarg)
          size = atoi(optarg);
        else
        {
          cout << "Error: size expected, not given\n";
          usage();
          return 1;
        }
        size_flag = 1;
        list_flag = 0;
        flags["random"] = true;
        flags["list"] = false;
        break;
      case '?':
        break;
      default:
        cout << "Error: undefined behavior" << endl;
        usage();
        return 1;
    }

  }

  if(size_flag && list_flag)
  {
    cout << "Error: size flag is only set for random input." << endl;
    usage();
    return 1; 
  }
  else if (size <= 0 && size_flag)
  {
    cout << "Error: size must be positive" << endl;
    usage();
    return 1;
  }
  else if(!flagCheck(flags))
  {
    cout << "Error: the program accepts exactly one sort flag." << endl;
    usage();
    return 1;
  }
  else
    sortMaster(vec, flags, size);

  return 0;
}

void initMapFlags(map<string, bool>& flags)
{
  flags["i"] = false;
  flags["m"] = false;
  flags["h"] = false; 
  flags["q"] = false; 
  flags["c"] = false; 
  flags["r"] = false; 
  flags["b"] = false;
  flags["list"] = false;
  flags["random"] = false;
  flags["print"] = false;
}

void usage()
{
  cout << "How to use the command line arguments for 'sort':" << endl;
  cout << "./sort [--help] | [ [ [-i] | [-m] | [-h] | [-q] | [-c] | [-r] | [-b] ] [-v | --verbose] [ [-n num | --size num] | [--list textfile] ] ]";
  cout << endl;
  cout << "num > 0, textfile != NULL" << endl;
}

bool flagCheck(map<string, bool>& flags)
{
  int total = 0;
  for(auto& item: flags)
  {
    if(item.second)
    {
      if(item.first == "i" || item.first == "m" || item.first == "h" || item.first == "q" 
        || item.first == "c" || item.first == "r" || item.first == "b")
      {
          total++;
      }

      if(total > 1)
        return false;
    }
  }
  if(total == 0)
    return false;
  return true;
}

void getVectorFromFile(vector<int>& vec, fstream& fin)
{
  int hold;
  while(fin >> hold)
    vec.push_back(hold);
}

void randomIntVec(vector<int>& vec, int size)
{
//rewrite this using the random C++11 library
  srand(time(0));
  int cur_num = 0;
  for(int i = 0; i < size; i++)
  {
    cur_num = rand() % 65536 + 1;
    vec.push_back(cur_num);
    cur_num = 0;
  }
}

void sortMaster(vector<int>& unsorted, map<string, bool> flags, int size)
{
  if(flags["b"] == true)
  {
    Bucket_Sort bsort(flags["print"]);
    vector<float> unsorted = bsort.get_random_floats(size);
    bsort.start_sort(unsorted);
    return;
  }

  if(flags["random"])
    randomIntVec(unsorted, size);

  if(flags["i"])
  {
    Insertion_Sort isort(flags["print"]);
    isort.start_sort(unsorted);
  }
  else if(flags["m"])
  {
    Merge_Sort msort(flags["print"]);
    msort.start_sort(unsorted);
  }
  else if(flags["h"])
  {
    Heap_Sort hsort(flags["print"]);
    hsort.start_sort(unsorted);
  }
  else if(flags["q"])
  {
    Quick_Sort qsort(flags["print"]);
    qsort.start_sort(unsorted);
  }
  else if(flags["c"])
  {
    Counting_Sort csort(flags["print"]);
    csort.start_sort(unsorted);
  }
  else if(flags["r"])
  {
    Radix_Sort rsort(flags["print"]);
    rsort.start_sort(unsorted);
  } 
}
