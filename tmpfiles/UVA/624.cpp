#include <bits//stdc++.h>
#define f first
#define s second
#define getbit(x,bit) (bool )((x)&(1<<(bit)))
using namespace std;
//ifstream in("../test.txt");
bool cmp(pair<int,vector<int>>&x,pair<int,vector<int>>&y )
{
    if (x.f!=y.f )return x.f>y.f;
    else return x.s.size() < y.s.size();
}
int main() {
    string s ;
    while (getline(cin,s))
    {
        stringstream sin(s);
        int m,n ;sin>>m>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)sin>>v[i];
        vector< pair<int,vector<int>> >res;
        for (int i =0 ;i <= (1<<n)-1 ;i++ )
        {
            vector<int>tmp;int sum=0;
            for (int j =0 ;j < n ;j++)
                if (getbit(i,j))
                    sum+=v[j] , tmp.push_back(v[j]);
            res.push_back({sum,tmp});
        }
        sort(res.begin() , res.end() , cmp);
        for (auto i : res)
        {
            if (i.f<=m)
            {
                for (auto j : i.s)cout<<j<<" ";
                cout<<"sum:"<<i.f<<endl;
                break;
            }
        }
    }
    return 0;
}
