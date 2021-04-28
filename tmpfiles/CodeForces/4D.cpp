#include<bits/stdc++.h>
using namespace std ;
class op{
public :
    int w ,h ,ind;
    op(int w ,int h ,int ind )
    {
        this->w =w ;
        this->h =h ;
        this->ind=ind ;
    }
};
bool cmp (op& x , op& y )
{
    if(x.w == y.w)return x.h <y.h;
    else  return x.w<y.w;
}
int main ()
{
    int n ; cin>>n;
    int W ,H;cin>>W>>H;
    int w ,h ;
    vector<op>arr;
    int t =0 ;
    for(int i =0 ;i < n ;i++)
    {
        cin>>w>>h;
        if(w <=W || h<=H)continue;
        arr.push_back(op(w ,h , i));
    }   
    sort(arr.begin() ,arr.end(),cmp);
    n=arr.size();

    vector<int>lis(n, 1 );
    for(int i =0 ;i < n ;i++)
    {
        for(int j = i-1 ; j>=0 ; j--)
        {
            if(arr[i].w >arr[j].w && arr[i].h > arr[j].h)
                lis[i]=max (lis[j]+1 , lis[i]);
        }
    }
    int cnt =1;
    vector<int>res;
    for(int i =0 ;i < n ;i++)
        if(cnt==lis[i])
            res.push_back(arr[i].ind),cnt++;
    cout<<res.size() <<endl;
    for(auto i : res )cout<<i+1<<" ";
    return 0;

}