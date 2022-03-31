#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

struct node{
    int tp, l,r;
    node(int _tp, int _l,int _r):tp(_tp),l(_l),r(_r){}
};

bool cmp(node a,node b){
    return a.tp > b.tp;
}
const int maxn = 1005;
int n,m,dif[maxn], sorted[maxn];;
vector<node>v;

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    memset(dif,-1,sizeof(dif));
    for(int i = 1; i <= m; i++){
        int tp,l,r;
        cin>>tp>>l>>r;
        if(tp){
            for(int j = l; j < r; j++){
                dif[j] = 1;
            }
        }
        v.emplace_back(node(tp,l,r));
    }
    sorted[1] = n;
    for(int i = 2; i <= n; i++){
        sorted[i] = sorted[i - 1] + dif[i - 1];
    }

    for(int i = 0; i < (int) v.size(); i++){
        if(v[i].tp == 1){
            bool flag = true;
            for(int j = v[i].l + 1; j <= v[i].r; j++){
                if(sorted[j] < sorted[j - 1]){
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                cout<<"NO"<<endl;
                exit(0);
            }
        }
        else{
            bool flag = false;
            for(int j = v[i].l + 1; j <= v[i].r; j++){
                if(sorted[j - 1] > sorted[j]){
                    flag = true;
                }
            }
            if(!flag){
                cout<<"NO"<<endl;
                exit(0);
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++){
        cout<<sorted[i]<<" ";
    }


    


    return 0;
}

