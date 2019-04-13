#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<long long,long long> pii;
typedef long long ll;
int n;
vector<pii> v,ch;


ll Cross_Product(pii a, pii b, pii c){
    return ((ll) b.first - a.first) * ((ll) c.second - a.second) - ((ll) c.first - a.first) * ((ll) b.second - a.second);
}

ll dis(pii a, pii b){
    return ((ll) b.first - a.first) * (b.first - a.first) + ((ll)b.second - a.second) * (b.second - a.second);
}


int main()
{
    FAST_IO; 
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;

    for(int i = 0; i < n; i++){
        ll x,y;
        cin>>x>>y;

        y -= x * x;
        v.emplace_back(make_pair(x,y));
    }
    
    sort(v.begin(),v.end());    
    vector<pii> p;
    for(int i = 0; i < (int) v.size(); i++){
        if(i == (int) v.size() - 1 || v[i].first != v[i + 1].first) p.emplace_back(v[i]);
    }

    
    for(int i = 0; i < (int) p.size(); i++){
        while((int) ch.size() >= 2 && Cross_Product(ch[(int)ch.size() - 2], ch[(int)ch.size() - 1], p[i]) >= 0) ch.pop_back();
        ch.emplace_back(p[i]);
    }

    cout<<ch.size() - 1<<endl;

    return 0;
}

