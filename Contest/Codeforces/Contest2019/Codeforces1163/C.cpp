#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false)
long long total,ans;

typedef pair<int,int> pii;
map<pii, set<int> > mp;
struct line{
    int a,b,c;
    line(int _a = 0, int _b = 0,int _c = 0):a(_a),b(_b),c(_c){

    }
};


int n;
vector<pii> pt;
vector<line> lines;

int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}

bool line_cmp(line a,line b){
    if(a.a != b.a) return a.a < b.a;
    else if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}

int main()
{
    FAST_IO;

    cin>>n;
    for(int i = 1; i <= n; i++){
        int x,y;
        cin>>x>>y;
        pt.push_back(pii(x,y));
    }

    for(int i = 0; i < (int) pt.size(); i++){
        for(int j = i + 1; j < (int) pt.size(); j++){
            int x1 = pt[i].first, x2 = pt[j].first;
            int y1 = pt[i].second, y2 = pt[j].second;
            int a = y1 - y2;
            int b = x1 - x2;

            int _gcd = gcd(a,b);
            a /= _gcd;
            b /= _gcd;
            if(a < 0 || (a == 0 && b < 0)){
                a = -a;
                b = -b;
            }
            int c = a * x1 - b * y1;

            auto slope = make_pair(a,b);
            if(!mp[slope].count(c)){
                ++total;
                mp[slope].insert(c);
                ans += total - mp[slope].size();
            }

        }
    }

    cout<<ans<<endl;



    return 0;
}
