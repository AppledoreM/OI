#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn = 500005;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
int n,m,q,c[maxn];
vector<pii> a;
vector<pll> que;


int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin>>tmp;
        c[tmp]++;
    }
    
    for(int i = 1; i <= m; i++){
        a.emplace_back(pii(c[i],i));
    }
    for(int i = 1; i <= q; i++){
        ll tmp;
        cin>>tmp;
        tmp -= n;
        que.emplace_back(pll(tmp,i));
    }

    sort(a.begin(),a.end());
    a.insert(a.begin(),pii(0,-1));
    sort(que.begin(),que.end());
    ll cnt = 0, pre = 0, tmp = 0;
    for(int i = 0, j = 1; i < (int) que.size(); i++){
        ll k = que[i].first;
        while(j <= m && 1ll * (a[j].first - pre) * cnt + tmp < k){
            tmp += 1ll * (a[j].first - pre) * cnt;
            pre = a[j].first;
            cnt++;
            T.insert(a[j].second);
            j++;
        }
        k -= tmp;
        k %= cnt;
        if(!k) k = cnt;
        que[i].first = (int)*T.find_by_order(k - 1);
    }
    sort(que.begin(), que.end(), [](auto x, auto y){ return x.second < y.second;});
    for(int i = 0; i < (int) que.size(); i++) cout<<que[i].first<<endl;


    return 0;
}


