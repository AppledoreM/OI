#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 6e5 + 10;

struct Node{
    int prefix_l, prefix_r;
    int suffix_l, suffix_r;
    int mid_mx;
    int len;

    Node():prefix_l(0), prefix_r(0), suffix_l(0), suffix_r(0), mid_mx(0){};
};

int n,q, a[maxn];
string s;
Node tree[maxn<<2], tree1[maxn<<2], tree2[3];
bool tag[maxn<<2];

void maintain(int cur,int l,int r, Node* tree = tree){
    int left = cur<<1;
    int right = cur<<1|1;
    tree[cur].len = tree[left].len + tree[right].len;
    tree[cur].prefix_l = tree[left].prefix_l;
    tree[cur].prefix_r = tree[left].prefix_r;
    tree[cur].suffix_l = tree[right].suffix_l;
    tree[cur].suffix_r = tree[right].suffix_r;

    tree[cur].mid_mx = max(tree[left].mid_mx, tree[right].mid_mx);
    if(tree[left].suffix_r == 0 || tree[right].prefix_l == 0){
        tree[cur].mid_mx = max(tree[cur].mid_mx, tree[left].suffix_l + tree[left].suffix_r + tree[right].prefix_l + tree[right].prefix_r);
    }
    

    if(tree[left].prefix_l + tree[left].prefix_r == tree[left].len){
        if(tree[right].prefix_l == 0) {
            tree[cur].prefix_r = tree[left].prefix_r + tree[right].prefix_r;
        }
        if(tree[left].prefix_r == 0){
            tree[cur].prefix_l = tree[left].prefix_l + tree[right].prefix_l;
            tree[cur].prefix_r = tree[right].prefix_r;
        }
    }
    

    if(tree[right].prefix_l + tree[right].prefix_r == tree[right].len){
        if(tree[left].suffix_r == 0){
            tree[cur].suffix_l = tree[left].suffix_l + tree[right].prefix_l;
        }
        if(tree[right].suffix_l == 0){
            tree[cur].suffix_r = tree[left].suffix_r + tree[right].suffix_r;
            tree[cur].suffix_l = tree[left].suffix_l;
        }
    }

}

void debug(int cur, int l,int r){
   // cerr<<l<<" "<<r<<" "<<tree[cur].prefix_l<<" "<<tree[cur].prefix_r<<" "<<tree[cur].suffix_l<<" "<<tree[cur].suffix_r<<" "<<tree[cur].mid_mx<<endl;
}
void build(int cur,int l,int r, Node* tree = tree){

    if(l == r){
        tree[cur].prefix_l = a[l];
        tree[cur].prefix_r = (a[l] == 0);
        tree[cur].suffix_l = a[l];
        tree[cur].suffix_r = (a[l] == 0);
        tree[cur].len = r - l + 1;
        tree[cur].mid_mx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(cur<<1,l,mid, tree);
    build(cur<<1 | 1, mid + 1, r, tree);
    maintain(cur, l, r, tree);
}


void rev(int cur){
    tag[cur] ^= 1;
    swap(tree[cur], tree1[cur]);
}

void pushdown(int cur){
    if(tag[cur]){
        tag[cur] = 0;
        rev(cur<<1);
        rev(cur<<1|1);
    }
}
void change(int cur,int l,int r,int a,int b){
    if(a <= l && r <= b){
        rev(cur);
        debug(cur,l ,r);
        return;
    }
    pushdown(cur);
    int mid = (l + r) >>1;
    if(a <= mid) change(cur<<1, l, mid, a, b);
    if(b > mid) change(cur<<1 | 1, mid + 1, r, a, b);
    maintain(cur, l, r);
    debug(cur,l ,r);
    maintain(cur, l, r, tree1);
}


Node combine(Node a, Node b){
    tree2[2] = a;
    tree2[3] = b;
    maintain(1,0,0,tree2); 
    return tree2[1];
}
Node query(int cur,int l,int r, int a,int b){
    if(a <= l && r <= b){
        return tree[cur];
    }
    pushdown(cur);
    int mid = (l + r) >> 1;
    if(b <= mid) return query(cur<<1, l, mid, a, b);
    if(a > mid) return query(cur<<1|1, mid + 1, r, a, b);
    return combine(query(cur<<1,l,mid,a,b), query(cur<<1|1,mid + 1,r,a,b));
}

int solve(Node node){
    return max(node.prefix_l + node.prefix_r, max(node.suffix_l + node.suffix_r, node.mid_mx));
}

int main(){
    cin>>n>>q;
    cin>>s;
    for(int i = 0; i < n; i++){
        if(s[i] == '>') a[i + 1] = 1;
        else a[i + 1] = 0;
    }
    build(1, 1, n);
    for(int i = 1; i <= n; ++i) a[i] ^= 1;
    build(1, 1, n, tree1);

    while(q--){
        int l, r;
        cin>>l>>r;
        change(1,1,n,l,r);
        cout<<solve(query(1,1,n,l,r))<<endl;
    }


    return 0;
}