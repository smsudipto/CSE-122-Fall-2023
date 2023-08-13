# include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    long long int m,n,a,total;
    double hight;
    double width;
    cout<<"rectangular shape and flagstone size is:";
    cin>>m>>n>>a;
    hight=ceil((double)m/(double)a);
    width=ceil((double)n/(double)a);
    cout<<"hight is:"<<hight<<endl;
    cout<<"Width is :"<<width<<endl;
 total=(hight*width);
    cout<<"Total flagstone is :"<<total;
    return 0;



}
