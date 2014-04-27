#include <iostream>
#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  // class as Compare
  std::map<char,int,classcomp> fourth(first.begin(),first.end());  

  //delete in for
  std::map<char,int,classcomp>::iterator iter = fourth.begin();
  while(iter != fourth.end())
  {
	if(iter->second < 50)
	{
		fourth.erase(iter++);
	}
	else
	{
		iter++;
	}
  }
  
  iter = fourth.begin();
  while(iter != fourth.end())
  {
	std::cout<<iter->first<<"\t"<<iter->second<<std::endl;
	iter++;
  }
  return 0;
}
