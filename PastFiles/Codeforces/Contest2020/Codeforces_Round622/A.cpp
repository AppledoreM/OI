#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int t;

void debug(int x){
    cout<<x<<endl;
}

int process1(vector<int>& v){

    int sum = 0;
    for(int& x : v){
        if(x >= 1) {
            x--;
            sum++;
        }
    }
    return sum;
}
int process2(vector<int>& v){
    int sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            if(v[i] >= 1 && v[j] >= 1){
                v[i]--;
                v[j]--;
                
                sum++;
            }
        }
    }
    return sum;
}

int process3(vector<int>& v){
    int sum = 1;
    for(int x : v){
        if(x < 1) sum = 0;
    }
    return sum;
}

int main(){

    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> v = {a,b,c};
        sort(v.begin(), v.end(), greater<int>());
        if(v[2] >= 4) {
            cout<<7<<endl;
            continue;
        }
        int ans = 0;
        ans += process1(v);
        ans += process2(v);
        ans += process3(v);
        cout<<ans<<endl;
    }

    return 0;
}