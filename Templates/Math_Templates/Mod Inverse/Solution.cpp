#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extended_euclidean(ll a,ll b,ll &x,ll &y)
{
    if(!b) 
    {
        x=1;y=0;
        return a;
    }
    ll d=extended_euclidean(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

//inv for one number
int mod(int a, int m){
    ll x, y;
    ll g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        cout << "No solution!";
    }
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}

//inv of all numbers in an array: Average O(1) run time for each
std::vector<int> invs(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    ll x, y;
    extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

int main(){
    return 0;
}