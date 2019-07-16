#include <bits/stdc++.h>
using namespace std;
int n;
struct line{
    int fix_pos, st, ed;
    line(int _a = 0, int _b = 0,int _c = 0):fix_pos(_a),st(_b),ed(_c){}
};


constexpr int maxn = 10005;
int tree[maxn << 2], tag[maxn<<2];

void change(int cur,int l,int r,int a,int b,int x){
    if(a <= l && r <= b){
        tree[cur] = x;
        return ;
    }
    int mid = (l + r) / 2;
    if(a <= mid) change(cur<<1, l, mid, a, b, x);
    if(b > mid) change(cur<<1|1, mid + 1,r, a, b, x);
    tree[cur] = tree[cur<<1] + tree[cur<<1|1];
}

int query(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        return tree[cur];
    }
    int res = 0;
    int mid = (l + r) / 2;
    if(a <= mid) res += query(cur<<1,l,mid,a,b);
    if(b > mid) res += query(cur<<1|1,mid + 1,r,a,b);
    return res;
}

vector<int> hor_end[maxn];
vector<line> ver[maxn], hor[maxn];

bool cmp(line a,line b){
    return a.fix_pos < b.fix_pos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i = 1; i <= n; i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1 += 5001;
        x2 += 5001;
        y1 += 5001;
        y2 += 5001;
        if(x1 == x2){
            ver[x1].emplace_back(line(x1,min(y1,y2), max(y1,y2)));
        }
        else{
            hor[y1].emplace_back(line(y1, min(x1,x2), max(x1,x2)));
        }
    }
    long long ans = 0;
    int prev = 0;
    for(int hei1 = 1; hei1 <= 10001; hei1++){
        for(int i = 0; i < (int) hor[hei1].size(); i++){
            memset(tree,0,sizeof(tree));
            for(int j = 0; j < maxn; j++) hor_end[j].clear();
            for(int j = hor[hei1][i].st; j <= hor[hei1][i].ed; j++){
                for(line now : ver[j]){
                    if(now.st <= hor[hei1][i].fix_pos && hor[hei1][i].fix_pos < now.ed){
                        change(1,1,10001, j, j, 1);
                        hor_end[now.ed].emplace_back(now.fix_pos);
                    }
                }
            }
            for(int hei2 = hei1 + 1; hei2 <= 10001; hei2++){
                for(auto l : hor[hei2]){
                    int x = query(1,1, 10001, l.st, l.ed);
                    ans += x * (x - 1) / 2;
                }
                for(auto x : hor_end[hei2]) change(1,1, 10001, x,x,0);
            }

        }
    }
    cout<<ans<<endl;


    return 0;
}