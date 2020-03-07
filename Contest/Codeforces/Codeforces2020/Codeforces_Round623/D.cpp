#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;
constexpr int maxn = 200005 * 4;
typedef long long ll;
typedef pair<int,int> pii;
int n;
pii a[maxn];
multiset<int> s;

int main(){
    cin>>n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i].first;
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i].second;
    }

    sort(a + 1, a + 1 + n);

    int last = -1;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        while(!s.empty() && last < a[i].first){
            int mx = *s.rbegin();
            ans += sum - mx;
            sum -= mx;
            s.erase(s.find(mx));
            ++last;
        }
        s.insert(a[i].second);
        sum += a[i].second;
        last = a[i].first;
    }

    while(!s.empty()){
        int mx = *s.rbegin();
        ans += sum - mx;
        sum -= mx;
        s.erase(s.find(mx));
        ++last;
    }
        
    cout<<ans<<endl;

    return 0;
}