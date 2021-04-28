#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <pair<int,vector<int>>>res;
    set<int >ch;
    set<vector<int>>sub;
    for (int i =2 ;i < (200) ;i++)
    {
        for (int j =2;j <(200) ;j++)
        {
            for (int k =2 ;k < (200) ;k++)
            {
                long long x =i*i*i + j*j*j  + k*k*k ;
                if (x>200*200*200)break;

                double cub=cbrt(x);
                if (cub-(int)cub <0.000000000000000001)
                   {
                        vector<int>v{i,j,k};
                        sort(v.begin(),v.end());
                        if (!sub.count(v))
                       {
                            res.push_back( { (int)cub , v} );
                            sub.insert(v);
                       }
                   }

            }
        }
    }
    sort(res.begin(),res.end());
    for (auto i : res )
    {
        cout<<"Cube = "<<i.first<<", Triple = (";
        for (int j =0 ;j<i.second.size();j++)
       {
            cout<<i.second[j];
            if (j!=i.second.size()-1)cout<<",";
       }
       cout<<")"<<endl;;

    }
    return 0;
}
