#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n ; cin>>n;
    vector<int>ne , po ;
    int zeros =0 , tmp;
    for (int i =0 ;i < n ;i++)
    {
        cin>>tmp;
        if(tmp==0)zeros++;
        if (tmp > 0 )po.push_back(tmp);
        if (tmp < 0 )ne.push_back(tmp);
    }
    if (ne.size() && po.size())
    {
        if (ne.size() % 2==0)
            swap (*(po.end()-1) , *(ne.end()-1));
    }
    else
    {
        if (!po.size() && ne.size()>2)
        {
            po.push_back(ne.back());
            ne.pop_back();
            po.push_back(ne.back());
            ne.pop_back();
        }

    }
    cout << ne.size()<<" ";
    for (auto i : ne)cout<<i<<" ";cout<<endl;
    cout << po.size()<<" ";
    for (auto i : po)cout<<i<<" ";cout<<endl;
    cout<<zeros<<" ";
    for (int i =0 ;i < zeros ;i ++)
        cout<<0<<" ";

    return 0;
}
