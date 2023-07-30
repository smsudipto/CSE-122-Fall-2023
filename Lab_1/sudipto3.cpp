#include <iostream>
using namespace std;
int main()
{
  int num1,num2,num3;
  cout<<"Enter your three number"<<endl;
  cin>>num1>>num2>>num3;
  if(num1>num3)
  {
      cout<<"Number-1  is MAX ";
  }
   else if(num2>num3)
  {
      cout<<"Number-2  is MAX ";
  }
  else
  {
      cout<<"Number-3 is MAX";
  }

    return 0;
}

