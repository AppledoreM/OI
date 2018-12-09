#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int CH_SZ = 26;
const int maxn = 255;
vector<string> mat;
int n,m,cnt[maxn * 2][CH_SZ], ones[maxn * 2];

inline int index(char c){ return c - 'a'; }

bool cmp(int x,int y){
    if(ones[x] > 1 || ones[y] > 1) return false;
    for(int i = 0; i < 26; i++){
        if(cnt[x][i] != cnt[y][i]) return false;
    }
    return true;
}

int manacher(){
    int re = 0;
    vector<int> p(maxn * 2 + 5);
    int mx = 0, id = 0;
    for(int i = 1; i < (n + 1) * 2; i++){
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while(i - p[i] > 0 && i + p[i] < (n + 1) * 2 && cmp(i + p[i], i - p[i])) ++p[i];
        if(ones[i] <= 1) re += p[i] / 2 ;
        if(mx < i + p[i]){
            mx = i + p[i];
            id = i;
        }
    }
    return re;
}

int main()
{
    FAST_IO;
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        string tmp;
        cin>>tmp;
        mat.emplace_back(tmp);
    }
    long long ans = 0;
    // Move Left Column 
    for(int i = 0; i < m; i++){
        // Set Zero
        for(int j = 0; j < maxn * 2; j++) memset(cnt[j],0,sizeof(cnt[j]));
        memset(ones,0,sizeof(ones));
        // Move Right Column 
        for(int j = i; j < m; j++){
            for(int k = 0; k < n; k++){
                if(cnt[(k + 1) * 2][index(mat[k][j])] & 1) ones[(k + 1) * 2]--;
                else ones[(k + 1) * 2]++;
                cnt[(k + 1) * 2][index(mat[k][j])]++;
            }
            ans += (long long) manacher();
        }
    }
    cout<<ans<<endl;
    return 0;
}

