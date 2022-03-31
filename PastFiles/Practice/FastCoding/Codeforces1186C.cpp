#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
string a,b;
const int maxn = 1e6 + 10;

int sum[maxn];

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b;

    int cnt_ones = 0;
    for(int i = 0 ; i <(int) b.size(); i++){
        if(b[i] == '1') cnt_ones++;
    }
    for(int i = 0; i < (int) a.size(); i++){
        sum[i + 1] = sum[i] + (a[i] == '1');
        
    }
    int ans = 0;
    for(int i = 0; i + (int) b.size() - 1< (int) a.size(); i++){
        int sum_one = sum[i + (int) b.size()] - sum[i]; 
        if((sum_one + cnt_ones)%2==0){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}

