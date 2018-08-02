#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <cmath>
#include <math.h>
#include <array>
#include <bitset>
#include <functional>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
#define DEBUG_VIS(x) cerr<<"vis "<<x<<endl;
#define DEBUG_REACH cerr<<"reach here"<<endl;
#define DEBUG_SEQ(x) cerr<<x<<" ";
#define SET_ZERO(x) memset(x,0,sizeof(x));
#define SET_NEGONE(x) memset(x,-1,sizeof(x));
#define SET_INF(x) memset(x,127,sizeof(x));
#define SET_NEGINF(x) memset(x,128,sizeof(x));
#define IS_INF(x) x < 2100000000
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 1e6 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
string s;
int fail[maxn];
ll num[maxn];
ll mod = 1e9 + 7;

void build(string s){
    int i = 0,j = -1;
    fail[0] = -1;
    while(i < (int) s.size()){
        if(j == -1 || s[i] == s[j]){
            fail[++i] = ++j;
            num[i] = num[j] + 1;
        }
        else j = fail[j];
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("data.in","r",stdin);
    #endif
    FAST_IO
    int T;
    cin>>T;
    while(T--){
        SET_ZERO(fail)
        cin>>s;
        num[0] = 0,num[1] = 1;
        build(s);
        long long ans = 1;
        int i = 0,j = 0;
        while(i < (int) s.size()){
            if(j == -1 || s[i] == s[j]){
                i++,j++;
                while(j * 2 > i) j = fail[j];
                ans = ans * (num[j] + 1) % mod;
            }
            else j = fail[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
