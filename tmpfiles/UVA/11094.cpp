#include <bits/stdc++.h>
using namespace std ;
ifstream in ("../in.txt");
ofstream out ("../out.txt");
char s[22][22];
char land ;
int n,m;
int r[]={0,0,-1,1};
int c[]={-1,1,0,0};
vector<int >sum;

int mmax=0;

void myplace(int x, int y )
{

        if (s[x][y]==land)
        {
            s[x][y]='.';
            mmax++;
            for (int i =0 ; i< 4 ;i++)
                myplace((((x+r[i] ) % (n))+(n))%(n),(((y+c[i])  % (m))+(m))%(m));
        }


  /*  for (int i =0 ;i < 4 ;i++)
    {
        myplace (s , x+ re[i] , y+re[(i+1)%3]);
    }*/

}

int main()
{
    int x,y;
    while ((in >> n >>m))
    {
        sum.clear();
        sum.push_back(0);
        for (int i =0 ;i <=21;i++ )
            memset(s[i],'.',22);
        string temp;
        for (int i =0 ;i <n ;i++)
        {
            in>>temp;
            for (int j =0 ; j <m ;j++)
                s[i][j]=temp[j];
        }
        in>>x>>y;
        land=s[x][y];
        myplace(x,y);
        mmax=0;
        for (int i =0 ; i < n ; i++)
        {
            for (int j =0 ;j < m;j++)
            {
                if (s[i][j]==land)
                {
                    myplace(i , j);
                    sum.push_back(mmax);
                    mmax=0;

                }

            }

        }
        out<<*max_element(sum.begin(),sum.end())<<endl;




    }
    return 0;
}

