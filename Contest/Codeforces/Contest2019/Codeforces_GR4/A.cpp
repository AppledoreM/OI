#include <bits/stdc++.h>
using namespace std;

int n,sum;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    int alic = 0;
    cin>>alic;
    vector<int> v;
    int tot = alic;
    sum = alic;
    for(int i =2; i <= n; i++){
        int x;
        cin>>x;
        if(2 * x <= alic){
            v.emplace_back(i);
            sum += x;
        }

        tot += x;
    }

    if(sum * 2 > tot){
        cout<<(int) v.size() + 1<<endl;
        cout<<1<<" ";
        for(int i  : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else cout<<0<<endl;






    return 0;
}