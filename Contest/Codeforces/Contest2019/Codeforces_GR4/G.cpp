#include <bits/stdc++.h>
#include <cmath>
using namespace std;
constexpr int maxn = 2e5 + 10;
typedef long long ll;
typedef pair<ll,ll> pll;
int n,q, tot_id, in[maxn], out[maxn];
ll a[maxn], b[maxn];
ll suma[maxn],sumb[maxn];
vector<int> G[maxn];

bool cmp(long double a, long double b,long double c,long double d){
    return a * d >= b * c;
}

void dfs(int u,int fa){
    in[u] = ++tot_id;
    suma[u] = suma[fa] + a[u];
    sumb[u] = sumb[fa] + b[u];
    for(int x : G[u]){
        if(x == fa) continue;
        dfs(x, u);
    }
    out[u] = tot_id;
}

struct Upper{
    pll q[2005];
    int line_cnt = 0, now = 1;
    ll x_value = 0;
   
    
    
    void insert(ll k,ll b){
        while(line_cnt >= 2 && cmp(q[line_cnt - 1].second - q[line_cnt].second, q[line_cnt].first - q[line_cnt - 1].first, q[line_cnt].second - b, k - q[line_cnt].first)) line_cnt--;
        q[++line_cnt] = make_pair(k, b);
    }
    
    void add(ll x){
        x_value += x;
        while(now < line_cnt && x_value * q[now + 1].first + q[now + 1].second > x_value * q[now].first + q[now].second) now++;
    }
    
    ll get_max_value(){
        return q[now].first * x_value + q[now].second;
    }
    
    void clear(){
        x_value = line_cnt = 0;
        now = 1;
    }
    
};

struct block{
public:
    int L, R;
    Upper U;
    vector<pair<pll,int>> lines;
    ll offset = 0;
    bool binit = false;
    void init(int _l,int _r){
        if(!lines.empty()){
            binit = true;
            sort(lines.begin(), lines.end());
            build();
            L = _l;
            R = _r;
        }
    }
    void build(){
        U.clear();
        for(int i = 0; i < (int) lines.size(); i++) U.insert(lines[i].first.first, lines[i].first.second);
        U.add(0);
    } 
    void add(ll x,int l, int r){
        if(r < L || l > R) return;
        if(l <= L && R <= r){
            U.add(x);
            offset += x;
        }
        else{
            for(int i = 0; i <(int) lines.size(); i++){
                lines[i].first.second += offset * lines[i].first.first;
                if(l <= lines[i].second && lines[i].second <= r){
                    lines[i].first.second += x * lines[i].first.first;
                }
            }
            offset = 0;
            U.clear();
            build();
        }
    }
    
    ll get(int l,int r){
        if(r < L || l > R) return numeric_limits<ll>::min();
        if(l <= L && R <= r){
            return U.get_max_value();
        }
        else{
            ll ans = numeric_limits<ll>::min();
            for(int i = 0; i < (int) lines.size(); i++){
                if(l <= lines[i].second && lines[i].second <= r){
                    ans = max(ans, lines[i].first.first * offset + lines[i].first.second);
                }
            }
            return ans;
        }
        return 0;
    }
} blocks[2005];






int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for(int i = 2; i <= n; i++){
        int p;
        cin>>p;
        G[p].emplace_back(i);
        G[i].emplace_back(p);
    }
    
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];
    
    int block_sz = max(1, (int) sqrt(n / 6));
    
    dfs(1,1);
    
    for(int i = 1; i <= n; i++){
        int block_id = ((in[i] - 1) / block_sz) + 1;
        blocks[block_id].lines.emplace_back(make_pair(pll(sumb[i], suma[i] * sumb[i]),in[i]));
        if(suma[i] < 0 || sumb[i] < 0) blocks[block_id].lines.emplace_back(make_pair(-sumb[i], -suma[i] * sumb[i]), in[i]);
    }
    
    int tot_block = 0;
    for(tot_block = 1;;tot_block++){
        blocks[tot_block].init((tot_block - 1) * block_sz + 1, min(tot_block * block_sz, n));
        if(!blocks[tot_block].binit){
            tot_block--;
            break;
        }
    }
    
    for(int i = 1; i <= q; i++){
        int opt;
        cin>>opt;
        if(opt == 1){
            int v;
            ll x;
            cin>>v>>x;
            for(int j = 1; j <= tot_block; j++){
                blocks[j].add(x, in[v], out[v]);
            }
        }
        else {
            int v;
            cin>>v;
            ll ans = numeric_limits<ll>::min();
            for(int j = 1; j <= tot_block; j++){
                ans = max(ans, blocks[j].get(in[v],out[v]));
            }
            cout<<ans<<endl;
        }
    }
    
    
    
    return 0;
}