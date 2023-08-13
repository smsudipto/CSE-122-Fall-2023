# include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    int n,k,answer=0;
    cin>>n>>k;
    int ar[n];
    for(int i=0;n>i;i++)
    {
        cin>>ar[i];
    }
    {
        for(int i=0;n>i;i++)
            if(ar[i]>=ar[k-1] && ar[i]>0)
        {
            answer++;
        }
    }
cout<<answer<<endl;
}
