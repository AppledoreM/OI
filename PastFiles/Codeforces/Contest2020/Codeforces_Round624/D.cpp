#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int t;

vector<int> fac[20005];

void init(){
    for(int i = 1; i <= 20000; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                fac[i].emplace_back(j);
                fac[i].emplace_back(i / j);
            }
        }
        sort(fac[i].begin(), fac[i].end());
    }
}

void solve(int a,int b,int c){
    int ans = INT_MAX;
    int ans_a,ans_b,ans_c;
    ans_a = ans_b = ans_c = 0;
    for(int i = 1; i <= 20000; i++){
        for(int j : fac[i]){
            for(int k : fac[j]){
                int step = abs(i - c) + abs(j - b) + abs(k - a);
                if(ans > step){
                    ans = step;
                    ans_a = k;
                    ans_b = j;
                    ans_c = i;
                }
            }
        }
    }
    cout<<ans<<endl;
    cout<<ans_a<<" "<<ans_b<<" "<<ans_c<<endl;

}
int main(){
    cin>>t;
    init();
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        solve(a,b,c);
    }


    return 0;
}