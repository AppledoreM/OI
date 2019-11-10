#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
constexpr int maxn = 1e6 + 10;

using namespace std;
int q,c,m,x;


bool okay(int num){

    if(num > c || num > m) return false;

    int tmpc = c - num;
    int tmpm = m - num;
    int rest = tmpc + tmpm + x;
    return rest >= num;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>q;
    while(q--){
        cin>>c>>m>>x;
        
        int ans = 0;
        int lo = 0, hi = max(max(c,m),x); 
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(okay(mid)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}