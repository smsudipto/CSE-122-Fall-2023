#include<bits/stdc++.h>
using namespace std;

bool isValid(const string& s)
{
    if(s.empty())
        return false;
    if(!(isalpha(s[0])|| s[0]=='_'))
        return false;
    for(int i=1; i<s.size(); i++)
    {
        if(!(isalnum(s[i])||s[i]=='_'))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        string s;
        cin>>s;
        if(isValid(s))
        {
            cout<<"Valid"<<endl;
        }
        else
        {
            cout<<"InValid"<<endl;
        }

    }
}


