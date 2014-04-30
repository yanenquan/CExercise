#include <iostream>
#include <vector>
#include <algorithm>

bool isRemove(const int &i)
{
	return i < 600;
}

int main ()
{
  // constructors
  std::vector<int> first;                                
  std::vector<int> second (4,700);                       
  std::vector<int> third (second.begin(),second.end());  
  std::vector<int> fourth (third);                      

  //construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  
  //insert
  std::vector<int>::iterator iter = fifth.begin();
  fifth.insert(iter,100);
  fifth.insert(fifth.begin(),3,200);
  fifth.insert(fifth.begin(),second.begin(),second.end());
  fifth.push_back(900);
  
  //modify
  fifth[0] = 600;
  //find
  iter = std::find(fifth.begin(),fifth.end(),900);
  if(iter != fifth.end())
  {
	  std::cout<<*iter<<std::endl;
  }
  
  //remove
  fifth.erase(fifth.begin());
  fifth.erase(fifth.begin(),fifth.begin()+1);
  fifth.erase(std::remove_if(fifth.begin(),fifth.end(),isRemove),fifth.end());
  
  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
