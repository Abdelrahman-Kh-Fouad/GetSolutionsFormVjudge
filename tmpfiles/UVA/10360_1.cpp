#include <bits/stdc++.h>
#define p pair<int,int>
#define f first
#define s second
using namespace std;
int d ;set<p>ch;
map<p ,int>node;
int xx[]={0,0,1,-1,1,-1,1,-1};
int yy[]={1,-1,0,0,1,-1,1,-1};
void go(p start,p now )
{
    if (max(abs(start.f-now.f ),abs(start.s-now.s))>=d ||
        !(now.f >=0 && now.s<=1025 && now.s >=0 && now.s<=1025)
        ||ch.count(now))
        return ;
    else
    {
        ch.insert(now);
        if (start!=now)
            node[now]+=node[start];
        for (int i =0 ;i < 8 ;i++)
            go(start,{now.f+xx[i],now.s+yy[i]});

    }
}
int main()
{
    int t ; cin>>t;
    while (t--)
    {
        cin>>d;
        int q ; cin>>q;
        int tmp1,tmp2,tmp3;
        set<p>will;
        for (int i =0 ;i < q ;i++)
        {
            cin>>tmp1>>tmp2>>tmp3;
            will.insert({tmp1 ,tmp2});
            node[{tmp1,tmp2}]=tmp3;
        }
        vector<pair<int , p >>res;
        for(auto i :will)
                go({i.f,i.s},{i.f,i.s}) ,ch.clear();
        int sum=0;
        for(auto i : node)
            /*cout<<i.f.f<<" "<<i.f.s<<" "<<i.s<<endl,*/sum=max(sum,i.s);
        for (auto i : node)
            if (i.s==sum)
            {
                cout<<i.f.f-1<<" "<<i.f.s-1<<" "<<sum<<endl;
                break;
            }
        node.clear();
    }
    return 0;
}
