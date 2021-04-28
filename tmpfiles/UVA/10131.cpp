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

    bool operator < (const elph & other)const
    {
        return this->w <= other.w && this->s > other.s;
    }

};  

int main()
{
    int w , s ;
    vector<elph>arr;
    int t=0;
    while(cin>>w>>s)
        arr.push_back(elph(w ,s, t++));
    int n = arr.size();
    set<elph>ss ;  
    for(int i =0 ;i <n ;i++)
    {
        auto ind = ss.lower_bound(arr[i]);
        if(ind != ss.end())
            ss.erase(ind);
        ss.insert(arr[i]);
    }
    cout<<ss.size() <<endl;
    for(auto i : ss )
        cout<<i.ind+1<<endl;

}