#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
constexpr int maxn = 200005;
typedef pair<int,int> pii;
long long tree[maxn<<2], tag[maxn<<2];


int n,m,p;
vector<pii> weapon, armor;
vector<int> discre;
struct Monster{
    int x,y,z;
    Monster(int _x = 0, int _y = 0, int _z = 0):x(_x), y(_y), z(_z){};
    bool operator<(const Monster b) const{ return x < b.x; }
};
vector<Monster> ms;

void maintain(int cur){
    tree[cur] = max(tree[cur<<1], tree[cur<<1|1]);
}
void build(int cur,int l,int r){
    tag[cur] = 0;
    if(l == r){
        tree[cur] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(cur<<1, l, mid);
    build(cur<<1 | 1,mid + 1, r);
    maintain(cur);
}
void push(int cur){
    if(tag[cur]){
        tag[cur<<1] += tag[cur];
        tag[cur<<1|1] += tag[cur];
        tree[cur<<1] += tag[cur];
        tree[cur<<1|1] += tag[cur];
        tag[cur] = 0;
    }
}


void update(int cur,int l,int r,int a,int b, int x){
    if(a <= l && r <= b){
        tree[cur] += x;
        tag[cur] += x;
        return;
    }
    push(cur);
    int mid = (l + r) >> 1;
    if(a <= mid) update(cur<<1,l,mid,a,b,x);
    if(b > mid) update(cur<<1|1,mid + 1,r,a,b,x);
    maintain(cur);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>p;
    weapon.resize(n);
    armor.resize(m);
    ms.resize(p);
    for(int i = 0; i < n; i++){
        cin>>weapon[i].first>>weapon[i].second;
    }
    for(int i = 0; i < m; i++){
        cin>>armor[i].first>>armor[i].second;
        discre.emplace_back(armor[i].first);
    }
    for(int i = 0; i < p; i++){
        cin>>ms[i].x>>ms[i].y>>ms[i].z;
    }
    sort(weapon.begin(), weapon.end());
    sort(armor.begin(), armor.end());
    sort(discre.begin(), discre.end());
    sort(ms.begin(), ms.end());
    discre.erase(unique(discre.begin(), discre.end()), discre.end());
    int len = discre.size();
    build(1,1,len);

    for(int i = 0; i < (int) armor.size(); i++){
        while(i > 0 && i < (int) armor.size() && armor[i].first == armor[i - 1].first){
            i++;
        }
        if(i >= (int) armor.size()) break;
        int def = armor[i].first;
        int cost = armor[i].second;
        int p = lower_bound(discre.begin(), discre.end(), def) - discre.begin();
        update(1,1,len,p + 1, p + 1,-cost);
    }
    int last_monster = 0;
    long long ans = -1e16;
    for(int i = 0; i < (int) weapon.size(); i++){
        while(last_monster < (int) ms.size() && ms[last_monster].x < weapon[i].first){
            int p = upper_bound(discre.begin(), discre.end(), ms[last_monster].y) - discre.begin();
            if(p + 1<= len) update(1,1,len, p + 1, len, ms[last_monster].z);
            last_monster++;
        }    
        ans = max(ans, tree[1] - weapon[i].second);
    }
    cout<<ans<<endl;
    return 0;
}

