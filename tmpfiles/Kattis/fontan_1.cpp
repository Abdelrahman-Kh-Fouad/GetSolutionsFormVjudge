#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
bool eq(vector<vector<char>>x , vector<vector<char>>y)
{
    for(int i =0 ;i < sz(x) ;i++)
        for(int j =0 ;j < sz(x.front()) ;j++)
            if((x)[i][j] != (y)[i][j])
                return 0 ;
           
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m ;cin>>n >> m ;
    vector<vector<char>>prev , cur ; 
    prev .assign(n , vector<char>(m) );
    cur.assign(n , vector<char>(m) );
    char hehe ='1';
    for(int i =0 ;i < n ;i++)
        for(int j =0 ;j < m ;j++)
            cin>>(cur)[i][j];
    while(!eq(cur , prev))
    {
        prev=cur; 
        for(int i = 0 ;i < n-1 ;i++)
        {
            for(int j =0 ;j < m ;j++)
            {
                char &above= (cur)[i][j];
                char &down= (cur)[i+1][j];
                char &left = (j-1 >= 0)? (cur)[i][j-1] : hehe;
                char &right = (j+1 < m)? (cur)[i][j+1] : hehe;
                if(above == 'V' && down=='.') down='V';
                else if(above == 'V' && down=='#')left = 'V' , right='V';
            }
        }
    }
    for(int i =0 ;i < n ;i++)
    {
        string tt (all(cur[i]));
        cout<<tt<<endl;;   
    }


    return 0 ; 
}