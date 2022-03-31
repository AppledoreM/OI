#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
int n,m,q;
const int maxn = 1e6 + 5;  
const int N = 1e6;
int tree[maxn<<2], maxr[maxn<<2], tag[maxn<<2];
vector<int> a, b;


void push(int cur){
    if(tag[cur]){
        tree[cur<<1] -= tag[cur];
        tree[cur<<1|1] -= tag[cur];
        tag[cur<<1] += tag[cur];
        tag[cur<<1|1] += tag[cur];
        tag[cur] = 0;
    }
}

void change(int cur,int l,int r,int a,int b,int delta){
    if(a <= l && r <= b){
        tree[cur] += delta; 
        tag[cur] += delta;
        if(l == r) maxr[cur] = max(0, tree[cur]);
        return ;
    }
    push(cur);
    int mid = (l + r) / 2; 
    if(a <= mid) change(cur<<1,l,mid,a,b,delta);
    if(b > mid) change(cur<<1|1,mid + 1,r,a,b,delta);
    tree[cur] = tree[cur<<1] + tree[cur<<1|1];
    maxr[cur] = max(maxr[cur<<1|1], maxr[cur<<1] + tree[cur<<1|1]);
}



int get(int cur,int l,int r,int a,int b){
    if(a <= l) return maxr[cur];
    push(cur);
    int mid = (l + r) / 2;
    int re = -1e8;
    if(a <= mid) re = max(re, max(maxr[cur<<1|1], get(cur<<1,l,mid,a,b) + tree[cur<<1|1]));
    else re = max(re, get(cur<<1|1,mid + 1,r,a,b));
    return re;
}

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    a.resize(n);
    b.resize(m);

    for(int i = 1; i <= n; i++) {
        cin>>a[i - 1];
        change(1,1,N,a[i - 1],a[i - 1],1);
    }
    for(int i = 1; i <= m; i++){
        cin>>b[i - 1];
        change(1,1,N,b[i - 1],b[i - 1],-1);
    }

    cin>>q;

    for(int i = 1; i <= q; i++){
        int op, index, x;
        cin>>op>>index>>x;
        if(op == 1){
            change(1,1,N,a[index - 1],a[index - 1],-1);
            change(1,1,N,x,x,1);
            a[index - 1] = x;
        }
        else{
            change(1,1,N,b[index - 1],b[index - 1],1);
            change(1,1,N,x,x,-1);
            b[index - 1] = x;
        }

        int lo = 1, hi = N;
        int ans = -1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(get(1,1,N,mid,N) > 0){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        cout<<ans<<endl;
    }

    return 0;
}

