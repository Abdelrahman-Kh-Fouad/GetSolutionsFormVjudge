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
    
    vector<elph>lis (t, elph(0,0,0));
    int limit =0; 
    int l [t];
    
    for(int i =0; i < t;i++)
    {
        int ind = lower_bound(lis.begin(), lis.begin()+limit, arr[i])-lis.begin();
        lis[ind]=arr[i];
        if(ind==limit)limit++;
        l[i] = ind+1;
    }
    cout<<limit<<endl;
    for(int i =0 ;i <limit ;i++)
        cout<<lis[i].ind+1<<endl;


}