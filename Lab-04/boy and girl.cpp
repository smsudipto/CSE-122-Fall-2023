#include<bits/stdc++.h>
using namespace std;
int main()
{
    string r;
    cin>>r;
    int count=0;
    sort(r.begin(),r.end());
    for(int i=0; i<r.size();i++)
    {
        if(r[i]!=r[i+1])
        {
            count++;
        }
    }
    if(count%2==0)
        cout<<"CHAT WITH HER!";
    else
        cout<<"IGNORE HIM!";



return 0;

}
