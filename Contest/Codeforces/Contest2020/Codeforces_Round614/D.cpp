#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef unsigned long long ll;
ll x_0,y_0,ax,ay,bx,by;
ll xs,ys,t,T;
ll fx,fy;


inline ll quickpow(ll base, int n){
    ll temp = base;
    ll ret = 1;
    while(n){
        if(n & 1) ret *= temp;
        n >>= 1;
        if(!n) break;
        temp *= temp;
    }
    return ret;
}

ll calc(ll a, ll val, int n, ll b){
    ll ret = 0;
    ret += quickpow(a, n) * val;
    ret += (quickpow(a, n) - 1) * b / (a - 1);
    return ret;
}

ll c(ll a, ll b){
    if(a > b) return a - b;
    return b - a;
}
ll calc_dis(pair<ll,ll> a, pair<ll,ll> b){
    return c(a.first, b.first) + c(a.second,b.second);
}

int find_nearest(){
   int ret = 0;
   ll dis = 1e18;
   for(int i = 0; i <= 64; i++){
       ll coord_x = calc(ax, x_0, i, bx);
       ll coord_y = calc(ay, y_0, i, by);
       ll temp_dis = calc_dis(make_pair(coord_x,coord_y),  make_pair(xs,ys));
       if(temp_dis < dis){
           dis = temp_dis;
           ret = i;
       }
       else break;
   }
   return ret;
}

ll get_diff(int n){
    return quickpow(ax, n - 1) * fx + quickpow(ay, n - 1) * fy;
}


void print_node_list(){
    cout<<"Printing Coordinates!"<<endl;
    for(int i = 0; i <= 5; i++){
       ll coord_x = calc(ax, x_0, i, bx);
       ll coord_y = calc(ay, y_0, i, by);
       cout<<coord_x<<" "<<coord_y<<endl;
    }
}


int solve_n(int _n){
    int ans = 0;
   ll coord_x = calc(ax, x_0, _n, bx);
   ll coord_y = calc(ay, y_0, _n, by);
   ll d = calc_dis(make_pair(coord_x, coord_y), make_pair(xs,ys));
   bool mv = false;
   if(t >= d){
       mv = true;
       t -= d;
       ans++;
        for(int i = _n; i >= 1; i--){
            ll diff = get_diff(i);
            if(t >= diff){
                t -= diff;
                ans++;
            }
            else break;
        }
   }

   coord_x = calc(ax, x_0, _n + 1, bx);
   coord_y = calc(ay, y_0, _n + 1, by);
   d = calc_dis(make_pair(coord_x, coord_y), make_pair(x_0,y_0));
   if(t >= d){
        t -= d;
        ans++;
        for(int i = _n + 2;;i++){
            ll diff = get_diff(i);
            if(t >= diff){
                t -= diff;
                ans++;
            }
            else break;
        }
   }
   return ans;
}

void solve(){
    int _n = find_nearest();
    int ans = 0;
    t = T;
    ans = max(ans, solve_n(_n));
    t = T;
    ans = max(ans, solve_n(_n + 1));
    if(_n){
        t = T;
        ans = max(ans, solve_n(_n - 1));
    }
    cout<<ans<<endl;

}

int main()
{

    FAST_IO;
    cin>>x_0>>y_0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    T = t;

    fx = ax * x_0 - x_0 + bx;
    fy = ay * y_0 - y_0 + by;
    solve();

    return 0;
}

