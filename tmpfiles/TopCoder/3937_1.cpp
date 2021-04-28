#include<bits/stdc++.h>
using namespace std ;
class mobile {
public:
    int cost ,feature ,fixtime;
    mobile(int cost , int feature ,int fixtime)
    {
        this->cost = cost;
        this->feature = feature;
        this->fixtime = fixtime;
    }
};
class AutoMarket
{
private:
    int memo[50];
public :

    int LIS(vector<mobile*>&arr ,int ind )
    {
        if(ind == 0 )
            return 1 ; 
        int &stat = memo[ind];
        if(stat !=-1) return stat;
        stat =1 ; 
        for(int i =ind-1 ;i >=0 ;i--)
            if(arr[i]->cost < arr[ind]->cost &&
            arr[i]->feature > arr[ind]->feature &&
            arr[i]->fixtime < arr[ind]->fixtime )
                stat = max(stat , LIS(arr, i )+1);
        return stat;
    }
    int maxSet(vector<int>cost ,vector<int>feature,vector<int>fixTime )
    {
        int n = cost.size();
        vector<mobile*> arr(n);
        for(int i =0 ;i < n ;i++)
            arr[i]=new mobile(cost[i] , feature[i] , fixTime[i]);

        memset(memo , -1 , sizeof(memo));
        int res=  -1 ; 
        for(int i =0 ;i < n ;i++)
            res = max (res , LIS(arr , i ));
        return res;   
    }
};

int main ()
{
    AutoMarket solve;
    vector<int>a{1000, 1000, 1000, 1000, 2000},
b{3,3,4,3,3},
c{3,3,3,4,3};
  
    cout<< solve.maxSet(a , b ,c )<<endl; 
    return 0 ; 
}