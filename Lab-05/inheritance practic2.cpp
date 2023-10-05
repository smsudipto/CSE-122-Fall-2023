#include<iostream>
using namespace std;
class car
{
  public:
      int wheels;
      int range;
      int passenger;
      void display1()
      {
          cout<<"Wheels:"<<wheels<<endl;
          cout<<"Range:"<<range<<endl;
          cout<<"Passenger:"<<passenger<<endl;
      }
};
class truck:public car
{
   public:

      int weight;
      void display2()
      {
         display1();
      }
};
int main()
{
    car c1;
    truck t1;
    c1.wheels= 4;
    c1.range= 500;
    c1.passenger=5;
    c1.display1();
    t1.wheels= 12;
    t1.range= 1200;
    t1.weight=300;
    t1.display2();

}
