#include<bits/stdc++.h>
using namespace std ;

int main ()
{
    freopen("in", "r" , stdin);
    int n , m ; 
    int t = 0;
    while(cin>>n>>m && n!=0 || m!=0)
    {
        string a , b ;
        int w ; 
        map<string , int >names ;
        int cntnames =0 ; 
        int best[n][n];
        for(int i =0 ;i <n ;i++ )
        {
            for(int j =0 ;j <n ;j++)
            {
                best[i][j]=0;
             
            }
        }
        for(int i =0 ;i < m ;i++)
        {
            cin>>a>>b>>w;
            if(!names.count(a))
                names[a]=cntnames++;
            if(!names.count(b))
                names[b]=cntnames++;
            best[names[a]][names[b]] =w ;
            best[names[b]][names[a]] =w ;

        }

         for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    best[j][i] = best[i][j] = max ( best[i][j], min (best[i][k] , best[k][j]));
        
        cin >>a>>b;
        printf("Scenario #%d\n%d tons\n" , ++t , best[names[a]][names[b]]);
            
    

    }
}