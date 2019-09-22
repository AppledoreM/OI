#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2005;
int a[maxn][maxn];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int cnt = n / 4;
    int tot = 0;
    for(int i = 1; i <= n / 2; i++){
        for(int j = 1; j <= n / 2; j++){
            a[i][j] = tot++;
        }
    }
    for(int i = n / 2 + 1; i <= n; i++){
        for(int j = 1; j <= n / 2; j++){
            a[i][j] = a[i - n / 2][j];
        }
    }
    for(int i = n / 2 + 1; i <= n; i++){
        for(int j = n / 2 + 1; j <= n; j++){
            a[i][j] = a[i - n / 2][j - n / 2];
        }
    }
    for(int i = 1; i <= n / 2; i++){
        for(int j = n / 2 + 1; j <= n; j++){
            a[i][j] = a[i][j - n / 2];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] *= 4;
            if(i <= n / 2 && j <= n / 2) a[i][j] += 2;
            else if(i > n / 2 && j <= n / 2) a[i][j] += 1;
            else if(i <= n / 2 && j > n / 2) a[i][j] += 3;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}