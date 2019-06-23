#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 55;
const int maxt = 2505;
const int mod = 1e9 + 7;
int n,T,a[maxn][maxt],b[maxn][maxn][maxt],way[maxn][maxn][maxn][4];
int dur[3], permu[55];
vector<int> song[3];

void preprocess(){
    permu[0] = 1;
    for(int i = 1; i <= 50; i++){
        long long re = (long long)(permu[i - 1]) * i % mod;
        permu[i] = (int)(re);
    } 
}

void inc(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}


int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    preprocess();

    cin>>n>>T;

    a[0][0] = b[0][0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        int minute, gen;
        cin>>minute>>gen;
        gen--;

        if(gen == 0){
            for(int j = (int) song[0].size(); j >= 0; j--){
                for(int k = 0; k <= dur[0]; k++){
                    inc(a[j + 1][k + minute], a[j][k]);
                }
            }
        }
        else{
            for(int j = (int) song[1].size(); j >= 0; j--){
                for(int k = (int) song[2].size(); k >= 0; k--){
                    for(int p = 0; p <= dur[1] + dur[2]; p++){
                        inc(b[j + (gen == 1)][k + (gen == 2)][p + minute], b[j][k][p]);
                    }
                }
            }
        }
        song[gen].emplace_back(minute);
        dur[gen] += minute;
    }

    way[0][0][0][3] = 1;
    vector<int> c(3);
    for(c[0] = 0; c[0] <= (int) song[0].size(); c[0]++){
        for(c[1] = 0; c[1] <= (int) song[1].size(); c[1]++){
            for(c[2] = 0;  c[2] <= (int) song[2].size(); c[2]++){
                for(int lst = 0; lst < 4; lst++){
                    if(way[c[0]][c[1]][c[2]][lst]){
                        for(int nxt = 0; nxt < 3; nxt++){
                            if(nxt != lst && c[nxt] + 1 <= (int) song[nxt].size()){
                               vector<int> tmp(c);
                               tmp[nxt]++;
                               inc(way[tmp[0]][tmp[1]][tmp[2]][nxt],way[c[0]][c[1]][c[2]][lst]); 
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(c[0] = 0; c[0] <= (int) song[0].size(); c[0]++){
        for(int t = 0; t <= dur[0]; t++){
            if(T - t < 0) continue;
            for(c[1] = 0; c[1] <= (int) song[1].size(); c[1]++){
                for(c[2] = 0; c[2] <= (int) song[2].size(); c[2]++){
                    long long extra = (long long)(a[c[0]][t]) * b[c[1]][c[2]][T - t] % mod;

                    for(int i = 0; i < 3; i++){
                        extra = extra * permu[c[i]] % mod; 
                    }
                    for(int lst = 0; lst < 3; lst++){
                        if(c[lst] == 0) continue;
                        inc(ans, extra * way[c[0]][c[1]][c[2]][lst] % mod);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}

