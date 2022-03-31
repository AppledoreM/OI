#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 305;
int grid[maxn][maxn];
int t;
int main(){
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int ans;
        if(k % n == 0) ans = 0;
        else ans = 2;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                grid[i][j] = 0;
            }
        }

        int i = 0, j = 0;
        for(int cnt = 0; cnt < k; cnt++){
            grid[i + 1][j + 1] = 1;
            i = i + 1;
            j = (j + 1) % n;
            if(i == n){
                i = 0;
                j = (j + 1) % n;
            }
        } 
        cout<<ans<<endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }


    return 0;
}