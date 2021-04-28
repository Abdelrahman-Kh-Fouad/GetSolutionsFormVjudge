#include<bits/stdc++.h>
using namespace std ;
class elph
{
public :
    int w ,s ; 
    int ind ; 
    elph(int w , int s ,int ind  )
    {
        this->w =w ;
        this->s =s ;    
        this->ind=ind;
    }
    // arr[ind] > arr[j]
    bool operator < (const elph & other)const
    {
        return this->w >= other.w && this->s < other.s;
    }

};  
bool cmp(elph &x , elph &y)
{
    if(x.w == y.w)return x.s> y.s; 
    else return x.w < y.w;
}
int main()
{
    int w , s ;
    vector<elph>arr;
    int t=0;
    while(cin>>w>>s)
        arr.push_back(elph(w ,s, t++));
    
    // set<elph>ss;
    // sort(arr.begin() ,arr.end());
    // for(int i =0 ;i < t ;i++)
    // {
    //     auto ind = ss.lower_bound(arr[i]);
    //     if(ind != ss.end() )
    //         ss.erase(ind);
    //     ss.insert(arr[i]);
    // }
    // cout<<ss.size()<<endl;
    // for(auto i : ss )
    //     cout<<i.ind<<endl;
    sort(arr.begin() ,arr.end(),cmp);
    vector<int>lis(t,1 );
    vector<int>res ;
    for(int i =0 ;i < t ;i++)
    {
        for(int j =i-1;  j>=0 ; j--)
        {
            if( arr[i].s <  arr[j].s )
                lis[i]=max(lis[j]+1 ,lis[i] );
        }
    }
    int cnt  =1 ;
    for(int i =0 ;i < t ; i++)
        if(lis[i]==cnt )
            res.push_back(arr[i].ind),cnt++;
    cout<<res.size()<<endl;
    for(auto i : res )
        cout<<i+1<<endl;
}