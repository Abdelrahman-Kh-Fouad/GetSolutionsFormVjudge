#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <pair<int,vector<int>>>res;
    set<int >ch;
    for (int i =1 ;i < (200) ;i++)
    {
        for (int j =1 ;j <(200) ;j++)
        {
            for (int k =1 ;k < (200) ;k++)
            {
                long long x =i*i*i + j*j*j  + k*k*k ;
                if (x>200*200*200)break;

                double cub=cbrt(x);
                if (cub-(int)cub <0.000000000000001)
                    if (!ch.count((int)cub))
                    {
                        vector<int>v{i,j,k};
                        res.push_back( { (int)cub , v} );
                        ch.insert((int)cub);
                    }
            }
        }
    }
    sort(res.begin(),res.end());
    for (auto i : res )
    {
        cout<<"Cube = "<<i.first<<" , Triple = (";
        for (int j =0 ;j<i.second.size();j++)
       {
            cout<<i.second[j];
            if (j!=i.second.size()-1)cout<<",";
       }
       cout<<")"<<endl;;

    }
    cout<<ch.size()<<endl;
    return 0;
}
