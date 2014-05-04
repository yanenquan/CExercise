/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: STL set 操作
*  date: 2014-04-22
*  other: 无
******************************************************************************/

#include <iostream>
#include <set>

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  std::set<int> first;                           // empty set of ints

  int myints[]= {10,20,30,40,50};
  std::set<int> second (myints,myints+5);        // range
  //find and delete
  std::set<int>::iterator it;
  it = second.find (50);
  second.erase (it);
  
  //insert
  second.insert(1);
  

  std::set<int> third (second);                  // a copy of second

  std::set<int> fourth (second.begin(), second.end());  // iterator ctor.

  bool(*fn_pt)(int,int) = fncomp;
  std::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
	  
  std::set<int,classcomp> fifth(myints,myints+5);                 // class as Compare
  std::set<int,classcomp>::iterator iter = fifth.begin();
  while(iter != fifth.end())
  {
	  std::cout<<*iter<<std::endl;
	  iter++;
  }

  return 0;
}
