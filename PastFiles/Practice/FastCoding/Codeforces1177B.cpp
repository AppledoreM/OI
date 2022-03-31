#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

typedef long long ll;
ll k;


int main()
{
    FAST_IO;
    cin>>k;
    int i_len = 0;
    while(k - 9 * pow(10, i_len) * (i_len + 1) >= 1){
        k -= 9 * pow(10, i_len) * (i_len + 1);
        i_len++;
    }
    i_len++;
    ll lo = 1, hi = 9 * pow(10, i_len - 1);
    ll low = pow(10, i_len - 1);
    ll ans_pos = 0;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(k - mid * i_len >= 1){
            lo = mid + 1;
            ans_pos = mid;
        }
        else hi = mid - 1;
    }
    ans_pos += low;

    ll num_pos = k - (ans_pos - low) * i_len;
    while(i_len - num_pos > 0){
        num_pos++;
        ans_pos /= 10;
    }
    cout<<ans_pos % 10<<endl;
    return 0;
}

