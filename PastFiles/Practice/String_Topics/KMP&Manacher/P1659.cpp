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
ll N,K,tot,p[maxn << 1];
string s;
char str[maxn<<1];
ll BIT[maxn << 1];
void add(int x,int delta){
    while(x <= N){
        BIT[x] += delta;
        x += x & -x;
    }
}
ll query(int x){
    ll res = 0;
    while(x){
        res += BIT[x];
        x -= x & -x;
    }
    return res;
}
void manacher(){
    ll id = 1,mx = 0;
    for(int i = 1; i <= tot; i++){
        p[i] = mx > i ? min(p[2 * id - i],mx - i) : 1;
        while(str[i + p[i]] == str[i - p[i]]) ++p[i];
        if(mx < i + p[i]){
            mx = i + p[i];
            id = i;
        }
    }
}
ll mod = 19930726;
ll fast_pow(int val,int tim){
    ll base = val,ans = 1;
    while(tim){
        if(tim & 1) ans = ans * base % mod;
        base = base * base % mod;
        tim >>= 1;
    }
    return ans % mod;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("data.in","r",stdin);
    #endif
    FAST_IO
    cin>>N>>K;
    cin>>s;
    for(int j = 0; j < s.size(); j++){
        str[++tot] = '#';
        str[++tot] = s[j];
    }
    str[++tot] = '#';
    str[0] = '$';
    manacher();
    for(int i = 2; i <= tot; i += 2){
        int num = p[i] / 2;
        add(1,1);
        add(num + 1,-1);
    }
    ll ans = 1;
    for(int i = (N + 1) / 2; i >= 1; i--){
        ll num = query(i);
        if(!num) continue;
        if(K < num){
            ans = ans * fast_pow(i * 2 - 1,K) % mod;
            K = 0;
            break;
        }
        else {
            K -= num;
            ans = ans * fast_pow(i * 2 - 1,num) % mod;
        }
    }
    if(K) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
