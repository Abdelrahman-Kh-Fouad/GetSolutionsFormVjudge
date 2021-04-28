#include <bits/stdc++.h>
using namespace std;
#define p pair<int,int>
#define f first
#define s second
int n,m;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int go (vector<vector<char>>&grid , p node)
{
    if(grid[node.f][node.s] == '.' ||grid[node.f][node.s]=='G')
    {
        int sum =(grid[node.f][node.s]=='G')? 1:0;
        grid[node.f][node.s]='*';

        for(int i =0 ; i< 4 ;i++)
            if(grid[node.f+xx[i]][node.s+yy[i]]=='T')
                return sum;
        for(int i =0 ;i < 4 ;i++)
            sum+=go(grid , {node.f+xx[i],node.s+yy[i]});
        return sum;
    }
}
int main() {
    int cnt =1;
    while(cin>>m>>n)
    {
        vector<vector<char>>grid(n, vector<char>(m));
        p player;
        for(int i = 0 ;i <n; i++)
            for(int j =0 ;j <m ;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='P')
                    player={i,j};
            }
        grid[player.f][player.s]='.';
        cout<<go(grid , player )<<endl;
    }
    return 0;
}
