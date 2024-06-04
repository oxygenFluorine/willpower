#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int lengthstring(string s);
int main()
{
  string chars;
  cout<<"please input char"<<endl;
  cin>>chars;
  cout<<lengthstring(chars)<<endl;
  return 0;

}
int lengthstring(string s)
{
    int res = 0;//结果
    int s_length = s.length();
    unordered_set<char> set;
    int max_length = 0;//当前长度范围
    for ( int start=0,end=0;end<s_length;++end)
    {
      while(start<end&&set.count(s[end]))
      {
        set.erase(s[start]);
        ++start;
        --max_length;
      }
      /* code */
    
    set.insert(s[end]);
    ++max_length;
    res=max(res,max_length);
    }
    return res;
}

