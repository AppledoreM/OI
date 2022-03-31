#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct data{
    int u,v,col;
    data(int a = 0,int b = 0,int c = 0):u(a),v(b),col(c){}
    bool operator < (const data &a)const { return u == a.u ? v == a.v ? col < a.col : v < a.v : u < a.u;}
};

map<data,long long> mp;
const int mod = 1e9 + 7;
const int maxn = 50010;
int n,m,tot;
char s[3];
long long ans;
int d[maxn], ls[500];
int head[maxn],cnt,nxt[maxn<<2],val[maxn<<2],opt[maxn<<2],to[maxn<<2];
inline void addedge(int u,int v,int col,int valu){
    to[++cnt] = v; val[cnt] = valu; opt[cnt] = col; nxt[cnt] = head[u]; head[u] = cnt;
}


int col(char c){
    if(c == 'R') return 1;
    else if(c == 'G') return 2;
    return 3;
}

int main(){
    scanf("%d%d",&n,&m);
    int sz = sqrt(m + 0.5);
    for(int i = 1; i <= m; i++){
        int u,v,w;
        scanf("%d%d%d%s",&u,&v,&w,s);
        d[u]++; d[v]++;
        addedge(u,v,col(s[0]),w);
        addedge(v,u,col(s[0]),w);
        (mp[data(u,v,col(s[0]))] += w) %= mod;
        (mp[data(v,u,col(s[0]))] += w) %= mod;
    }

    for(int i = 1; i <= n; i++) if(d[i] >= sz) ls[++tot] = i;
    for(int i = 1; i <= tot; i++){
        for(int j = 1; j <= tot; j++){
            for(int k = 1; k <= tot; k++){
                ans = (ans + mp[data(ls[i],ls[j],1)] * mp[data(ls[j],ls[k],2)] % mod * mp[data(ls[k],ls[i],3)]) % mod;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(d[i] < sz){
            for(int j = head[i]; j; j = nxt[j]){
                if(!(d[to[j]] >= sz || to[j] > i)) continue;
                for(int k = nxt[j]; k; k = nxt[k]){
                    if(!(opt[j] != opt[k] && (d[to[k]] >= sz || to[k] > i))) continue;
                    ans = (ans + mp[data(to[j],to[k],6 - opt[j] - opt[k])] * val[j] % mod * val[k]) % mod;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
