#include <bits/stdc++.h>
using namespace std;
int n,m;

int rnk[] = {4,1, 3,2};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    int hi = 0;
    int lo = 5;
    for(int i = 0; i < 3; i++){
        if(rnk[(n + i) % 4] < lo){
            lo = rnk[(n + i) % 4];
            hi = i;
        }
    }

    cout<<hi<<" "<<(char)('A' + lo - 1)<<endl;

    


    return 0;
}