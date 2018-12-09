#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
const int maxn = 1e6 + 10;
int n;
vector<pii> a;
vector<pii> ans_vec;

int main()
{
    FAST_IO;
    cin>>n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1,a.end());
    bool met = false;
    int ans = 0;
    int fet = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].first >= 2){
            cnt += a[i].first;
            if(met){
                ans_vec.emplace_back(pii(a[i - 1].second,a[i].second));
                a[i - 1].first--;
                a[i].first--;
            }
            else{
                met = true;
                fet = i - 1;
            }
        }
    }
    cnt -= 2 * (n - fet) - 2;
    ans = ans_vec.size();
    int cur = fet;
    if(!met || (cnt < fet)){
        cout<<"NO"<<endl;
        return 0;
    }
    if(fet > 0){
        ans += min(2,fet);
        ans_vec.emplace_back(make_pair(a[fet].second,a[fet + 1].second));
        a[fet + 1].first--;
        if(fet >= 2) {
            ans_vec.emplace_back(make_pair(a[n].second,a[fet - 1].second));
            a[n].first--;
        }
        fet -= min(2,fet);
    }
    for(int i = cur + 1; i <= n && fet >= 1; i++){
        while(a[i].first >= 1 && fet >= 1){
            a[i].first--;
            ans_vec.emplace_back(make_pair(a[i].second,a[fet].second));
            fet--;
        }
    }
    cout<<"YES"<<" "<<ans<<endl;
    cout<<(int) ans_vec.size()<<endl;
    for(int i = 0; i < (int) ans_vec.size(); i++){
        cout<<ans_vec[i].first<<" "<<ans_vec[i].second<<endl;
    }
    return 0;
}

