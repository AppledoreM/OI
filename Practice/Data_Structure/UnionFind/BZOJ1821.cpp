#include <bits/stdc++.h>
using namespace std;
int n,k;
const int maxn = 2005;
typedef pair<int,int> pii;
pii a[maxn];
int f[maxn];
typedef pair<double,pii> pt;
vector<pt> v;
double ans;

bool cmp(pt a,pt b){
	return a.first < b.first;
}

void init(){
    for(int i = 1; i <= n; i++) f[i] = i;
}

int find_fa(int u){
    if(f[u] == u) return u;
    return f[u] = find_fa(f[u]);

}

inline double get_dis(int i,int j){
    return sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second));
}


int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++) scanf("%d%d",&a[i].first,&a[i].second);
    init();
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            v.push_back(pt(get_dis(i,j),pii(i,j)));
        }
    }
    sort(v.begin(),v.end(),cmp);
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        int u = v[i].second.first, m = v[i].second.second;
        if(find_fa(u) != find_fa(m)){ f[find_fa(u)] = find_fa(m); cnt++;}
        if(cnt == n - k + 1) {ans = v[i].first; break;}
    }
    printf("%.2lf\n",ans);

    return 0;
}
