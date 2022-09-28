//by Xifan Yu -- https://github.com/XifanYu/templates-ICPC-2020/blob/master/arithmetic/CRT_xifan.cpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db; 

// In case of pairwise coprime remainders:

// Extended Euclidean Algorithm
// Input: a, b, x, y
// Output: gcd(a, b), with x & y being set so that ax + by = 1
ll Exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b) 
    {
        x=1;y=0;
        return a;
    }
    ll d=Exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

// Chinese Remainder Theorem Algorithm
// Input: 'a' for array of remainders, 'm' for array of coprime modulos, n is the length of the array
// Output: smallest positive ans that satisfies ans % m[i] = a[i], 0 <= i < n
ll CRT(ll *a,ll *m,int n) 
{  
    ll M=1;  
    ll ans=0;  
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++)
    {  
        ll x=0, y=0;  
        ll Mi=M/m[i];  
        Exgcd(Mi,m[i],x,y); //x=inverse(Mi)
        ans=(ans+a[i]*Mi%M*x%M)%M;  
    }  
    if(ans<0) ans+=M;
    return ans;  
}  

int main()
{
    return 0;
}