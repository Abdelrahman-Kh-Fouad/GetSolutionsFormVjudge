#include<bits/stdc++.h>
using namespace std ;

bool check(string num )
{
    bool res = 1 ; 
    int ones = 0 ;
    for(auto i : num )
    {
        if(i=='1')ones++;
        if(!(i=='1' || i=='0'))
        {
            res =0;
            break;
        }
    }
    return res && ones<=1;
}
int main ()
{
    int n ; cin>>n ; 
    string arr[n];
    vector<string>pp;
    int zeros= 0  ; 

    for(int i =0 ;i < n ;i++)
    {   cin>>arr[i];
        if(arr[i] =="0" )
        {
            cout<<0<<endl;
            return 0 ;
        }
        if(check(arr[i]))
            zeros+=arr[i].size()-1;
        else 
            pp.push_back(arr[i]);
    }
    
    for(string i : pp )cout<<i;
    for(int i =0 ;i < zeros ;i++)
        cout<<0;
    cout<<endl;
}       