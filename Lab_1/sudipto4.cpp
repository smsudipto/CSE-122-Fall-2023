#include <iostream>
using namespace std;
int main()
{
  int x;
  cin>>x;
  if(x>=0)
  {
      cout<<"x value is Positive"<<endl;
      if(x%2==0)
      {
          cout<<"x value is .........."<<endl;
          if(x>99 & x<10000)
          {
              cout<<"x value contains four digit"<<endl;
          }
      }
  }


    return 0;
}

