#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
bool used [51][51];
void go(vector<vector<char>>&arr , int x ,int y )
{
    if(used[x][y])
        return ;
    used[x][y] =1 ;
    int n = sz(arr) , m =sz(arr.front());
    if( x+1 < n)
    {
        char down = arr[x+1][y];
        if(down=='.')
            arr[x+1][y]='V' , go(arr , x+1 , y );
        else if(down =='#')
        {
            if(y-1 >=0)
                arr[x][y-1]='V' , go(arr ,x, y-1);
            if(y+1 <m)
                arr[x][y+1]='V' , go(arr ,x, y+1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m ;cin>>n >> m ;
    vector<vector<char>> arr ; 
    arr.assign(n , vector<char>(m) );
    vector<pair<int,int>>start;
    for(int i =0 ;i < n ;i++)
        for(int j =0 ;j < m ;j++)
        {
            cin>>(arr)[i][j];
            if(arr[i][j]=='V')
                start.push_back({i ,j});
        }
    memset(used , 0 , sizeof used );
    for(auto &i : start)
        go(arr , i.ff ,i.ss);

    
    for(int i =0 ;i < n ;i++)
    {
        for(int j =0 ;j < m ;j++)
            cout<<arr[i][j];
        cout<<endl;
    }        



















    // queue<vector<vector<char>>>q;
    // q.push(arr);
    // set<vector<char>>used ;
    
    // while (!q.empty())
    // {
    //     vector<vector<char>> cur = q.front() ;
    //     q.pop();
    //     if(used.count(conv(cur)))continue;
    //     bool f =0 ;
    //     for(int i = 0 ;i < n-1 ;i++)
    //     {
    //         for(int j =0 ;j < m ;j++)
    //         {
    //             char above= cur[i][j];
    //             char down= cur[i+1][j];
    //             if(above == 'V' && down=='.')
    //             {
    //                 f |=1;
    //                 vector<vector<char>>neww(all(cur)) ;
    //                 neww[i+1][j]='V';
    //                 if(!used.count(conv(neww)))
    //                         q.push(neww) , used.insert(conv(neww));
    //                 q.push(neww);
    //             }
    //             else if(above == 'V' && down=='#')
    //             {
    //                 bool l = (j - 1 >= 0 && cur[i][j-1]=='.');
    //                 bool r = (j+1 < m && cur[i][j+1]=='.');
    //                 f |=l || r ; 
    //                 vector<vector<char>>neww( all(cur)) ;
    //                 if(l) neww[i][j-1]='V';
    //                 if(r) neww[i][j+1]='V';                        
    //                 if(!used.count(conv(neww)))
    //                     q.push(neww) , used.insert(conv(neww));
                
    //             }
    //         }

    //         // for(int i =0 ;i < n ;i++)
    //         // {
    //         //     for(int j =0;j<m ;j++)
    //         //         cout<<cur[i][j];
    //         //     cout<<endl;
    //         // }
    //     }
    //     if(!f)
    //     {
    //         for(int i =0 ;i < n ;i++)
    //         {
    //             for(int j =0;j<m ;j++)
    //                 cout<<cur[i][j];
    //             cout<<endl;
    //         }
    //         break;
    //     }

    // }
    return 0 ; 
}


// vector<char> conv(vector<vector<char>>&arr){
//     vector<char>res ; 
//     for(auto &i : arr)
//         for(auto &j:i)
//             res.pb(j);
//     return res;
// }