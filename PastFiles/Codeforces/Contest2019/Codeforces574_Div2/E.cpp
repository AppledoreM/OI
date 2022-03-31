#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3005;
typedef long long ll;
int n,m,a,b;
ll g,x,y,z;
ll que[maxn];
ll matrix[maxn][maxn], row_mn[maxn][maxn], matrix_mn[maxn][maxn];



int main(){
    cin>>n>>m>>a>>b>>g>>x>>y>>z;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
           matrix[i][j] = g;
           g = (g * x + y) % z;
        }
    }
    int head = 1, tail = 0;
    for(int i = 1; i <= n; i++){
        head = 1;
        tail = 0;
        memset(que, 0, sizeof(que));
        for(int j = 1; j <= m; j++){
            while(head <= tail && j - que[head] >= b) head++;
            while(tail >= head && matrix[i][que[tail]] >= matrix[i][j]) tail--;
            que[++tail] = j; 
            if(j >= b){
                row_mn[i][j - b + 1] = matrix[i][que[head]];
            }
        }
    }

    for(int j = 1; j <= m - b + 1; j++){
        head = 1;
        tail = 0;
        memset(que, 0, sizeof(que));
        for(int i = 1; i <= n; i++){
            while(head <= tail && i - que[head] >= a) head++;
            while(tail >= head && row_mn[que[tail]][j] >= row_mn[i][j]) tail--;
            que[++tail] = i;
            if(i >= a){
                matrix_mn[i - a + 1][j] = row_mn[que[head]][j];
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n - a + 1; i++){
        for(int j = 1; j <= m - b + 1; j++){
            ans += matrix_mn[i][j];
        }
    }
    cout<<ans<<endl;

    return 0;
}