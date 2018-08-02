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
const int maxn = 51000100; 
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
string s;
int p[maxn];
int mx,id,tot;
char str[maxn * 2];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("data.in","r",stdin);
    #endif
    FAST_IO
    cin>>s;
    for(int j = 0; j < s.size(); j++){
        str[++tot] = '#';
        str[++tot] = s[j];
    }
    str[++tot] = '#';
    str[0] = '$';
    id = 1,mx = 0;
    int ans = 0;
    for(int i = 1; i <= tot; i++){
        p[i] = mx > i ? min(p[2 * id - i],mx - i) : 1;
        while(str[i + p[i]] == str[i - p[i]]) p[i]++;
        if(mx < i + p[i]){
            mx = i + p[i];
            id = i;
        }
        if(ans < p[i] - 1) ans = p[i] - 1;
    }
    cout<<ans<<endl;
    return 0;
}
