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
#include <tuple>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
#define DEBUG_VIS(x) cerr<<"vis "<<x<<endl;
#define DEBUG_REACH cerr<<"reach here"<<endl;
#define DEBUG_SEQ(x) cerr<<x<<" ";
#define SET_ZERO(x) memset(x,0,sizeof(x));
#define SET_NEGONE(x) memset(x,-1,sizeof(x));
#define SET_INF(x) memset(x,127,sizeof(x));
#define SET_NEGINF(x) memset(x,128,sizeof(x));
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
const int maxn = 1e6 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
int N;
vector<int> v,ans,cnt;
vector<tuple<int,int,int>> q;
int sum = 0;
void del(int x){
    cnt[x]--;
    if(!cnt[x]) sum--;
}
void add(int x){
    if(!cnt[x]) sum++;
    cnt[x]++;
}

int main(){
    FAST_IO
   // freopen("data.in","r",stdin);
    cin>>N;
    v.assign(N + 1,0);
    for(int i = 1; i <= N; i++) cin>>v[i];
    cnt.assign(maxn,0);
    ans.assign(maxn,0);
    int Q;
    cin>>Q;
    for(int i = 1; i <= Q; i++){
        int l,r;
        cin>>l>>r;
        q.emplace_back(make_tuple(l,r,i));
    }
    sort(q.begin(),q.end(),[](auto x,auto y){
        int l1 = get<0>(x),l2 = get<0>(y);
        if(l1 != l2) return l1 < l2;
        int r1 = get<1>(x),r2 = get<1>(y);
        return r1 < r2;
    });
    int pl = 1,pr = 0;
    for(int i = 0; i < q.size(); i++){
        while(pl < get<0>(q[i])) del(v[pl++]);
        while(pl > get<0>(q[i])) add(v[--pl]);
        while(pr < get<1>(q[i])) add(v[++pr]);
        while(pr > get<1>(q[i])) del(v[pr--]);
        ans[get<2>(q[i])] = sum;
    }
    for(int i = 1; i <= Q; i++) cout<<ans[i]<<endl;
    return 0;
}
