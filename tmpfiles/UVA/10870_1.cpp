#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1e9 + 7 ;
class Matrix{
public :
    int n ,m ;
    vector<vector<ll>>arr;
public :
    Matrix(int n ,int m ): n(n), m(m){
        arr.assign(n ,vector<ll>(m, 0 ));
    }
    Matrix(vector<vector<ll>> &arr):n(arr.size()), m(arr.front().size()){
        this->arr = arr ; 
    }
    static Matrix I (int n ){
        Matrix res (n , n);
        for(int i =0 ;i < n ;i++)
            res.arr[i][i] =1 ; 
        return res ; 
    }
    static Matrix vec (vector<ll> &arr ){
        Matrix res(arr.size(),1) ;

        for(int i =0 ;i < res.n ;i+=1)
            res.arr[i][0] =arr[i];
        return res ;
    }
    Matrix operator * (const ll x ){
        Matrix res =*this ;
        for(int i =0 ;i < n ; i++)
            for(int j =0 ;j < m ;j++)
                res.arr[i][j] *=x ;
        return res ;

    }
    Matrix operator * (const Matrix &x ){
        Matrix res(this->n ,x.m);
        for(int i =0 ;i < this->n ;i++ )
            for(int j =0 ;j < this->m ;j++)
                for(int k = 0 ;k< this-> m ; k++)
                    res.arr[i][j] += ((ll)this->arr[i][k] *(ll)x.arr[k][j])%MOD; 
        return res ;
    }
    Matrix operator % (ll mod){
        Matrix res (n , m);
        for(int i = 0 ; i < this->n ;i++ )
            for(int j = 0 ; j < this->m ;j++)
                res.arr[i][j] =  this->arr[i][j] %= mod; 
        return res ;
    }
    void print(){
        for(int i =0 ;i < n ;i++)
        {
            for(int j =0 ;j < m ;j++)
                cout<< arr[i][j]<<" ";
            cout<<endl;
        }
    } 

};

Matrix power(Matrix &num, ll exp , ll m) {
    Matrix ret = Matrix::I(num.n) ;
    while (exp) {
        if (exp & 1)
            ret = (ret * num) % m ;
        num = (num * num) % m ;
        exp >>= 1;
    }
    return ret % m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll d , n ,m ;
    while(cin>>d >>n >>m && (d!=0 ||n!=0 || m!=0 ))
    {
        MOD =m ;
        vector<ll>f(d) , a(d);
        for(ll &i : a)cin>>i;
        for(ll &i : f)cin>>i;

        vector<vector<ll>>arr(d ,vector<ll>(d)) ;
        for(int i =0 ;i  <d ;i++)
            arr[0][i] =a[i]%m  ;
        for(int i =1 ;i < d ;i++)
            arr[i][i-1] =1 ;

        reverse(all(f));
        Matrix am(arr);
//        am.print();
        Matrix bm=Matrix::vec(f);
        if( n < d )
            cout << am.arr[d-n][0]<<endl;
        else 
        {
            am = power(am , n-d , m );
            Matrix res = am * bm;
            //res.print();
            cout<<res.arr[0][0] % m <<endl;
        }
    }
    return 0 ; 
}