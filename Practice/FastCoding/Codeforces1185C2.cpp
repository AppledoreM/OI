#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
const int maxn = 2e5 + 10;

int n,M, cnt[maxn][105], sum[maxn];
vector<int> v;



int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>M;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        sum[i - 1] = x;
        v.emplace_back(x);
    }

    for(int i = 0; i < (int) v.size(); i++){
        if(i){
            sum[i] = sum[i] + sum[i - 1];
            for(int j = 1; j <= 100; j++){
                cnt[i][j] = cnt[i - 1][j];
            }
        }
        cnt[i][v[i]]++;
    }
    for(int i = 0; i < n; i++){
        int count_ans = 0;
        if(sum[i] <= M) {
            cout<<0<<endl;
            continue;
        }
        for(int j = 100; j >= 1; j--){
            if(sum[i] - j * cnt[i - 1][j] > M){
                count_ans += cnt[i - 1][j];
                sum[i] -= j * cnt[i - 1][j];
            }
            else{
                cout<<count_ans + ceil(1.0 * (sum[i] - M) / j)<<endl;
                break;
            }
        }
    }


    return 0;
}

