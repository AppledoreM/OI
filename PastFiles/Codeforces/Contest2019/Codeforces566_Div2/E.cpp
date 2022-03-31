#include <iostream>
#include <stdio.h> 
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef long long ll;
ll n,f1,f2,f3,co;
const ll mod = 1e9 + 7;
typedef vector<vector<ll> > matrix;
matrix multiply(matrix &a,matrix &b){
    assert(!a.empty() && !b.empty() && a[0].size() ==  b.size());
    matrix c((ll)a.size(), vector<ll>((int) b[0].size(), 0));
    for(int i = 0; i < (int) a.size(); i++){
        for(int j = 0; j < (int) b[0].size(); j++){
            for(int k = 0; k < (int) b.size(); k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % (mod - 1);
            }
        }
    }
    return c;
}

void identi(matrix &a){
    assert(a.size() == a[0].size());

    for(int i = 0; i < (int) a.size(); i++){
        for(int j = 0; j < (int) a.size(); j++){
            if(i == j) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
}

ll fast_pow(ll a, ll num){
    ll base = a;
    ll res = 1;
    while(num){
        if(num & 1){
            res = res * base % mod;
        }
        base = base * base % mod;
        num >>= 1;
    }
    return res;

}

int main()
{
    cin>>n>>f1>>f2>>f3>>co;


    matrix tmp(3,vector<ll>(3,0));
    matrix now(3,vector<ll>(3,0));
    matrix tmp1(5,vector<ll>(5,0));
    matrix now1(5,vector<ll>(5,0));

    identi(now);
    identi(now1);

    tmp[0][0] = 1;
    tmp[0][1] = 1;
    tmp[0][2] = 1;
    tmp[1][0] = 1;
    tmp[1][1] = 0;
    tmp[1][2] = 0;
    tmp[2][0] = 0;
    tmp[2][1] = 1;
    tmp[2][2] = 0;
    
    for(int i = 0; i < 5; i++) tmp1[0][i] = 1;
    tmp1[1][0] = 1;
    tmp1[2][1] = 1;
    tmp1[3][3] = tmp1[3][4] = 1;
    tmp1[4][4] = 1;

    ll num1 = n - 3;
    while(num1){
        if(num1 & 1){
            now = multiply(now, tmp);             
            now1 = multiply(now1, tmp1);
        }
        tmp = multiply(tmp, tmp);
        tmp1 = multiply(tmp1,tmp1);
        num1 >>= 1;
    }


    matrix a(3,vector<ll> (1,0));
    a[0][0] = 0;
    a[1][0] = 0;
    a[2][0] = 1;

    a = multiply(now, a);

    matrix b(3,vector<ll> (1,0));
    b[0][0] = 0;
    b[1][0] = 1;
    b[2][0] = 0;

    b = multiply(now, b);

    matrix c(3,vector<ll>(1,0));

    c[0][0] = 1;
    c[1][0] = 0;
    c[2][0] = 0;

    c = multiply(now, c);
    matrix w(5, vector<ll>(1,0));
    w[4][0] = 2;
    w = multiply(now1, w);

    ll ans = fast_pow(co, w[0][0]) * fast_pow(f1, a[0][0]) % mod * fast_pow(f2, b[0][0]) % mod * fast_pow(f3, c[0][0]) % mod;
    cout<<ans<<endl; 
    
    return 0;
}

