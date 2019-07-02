#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
#define pi 3.1415926535897

int t,a,b,p,q;

int solve(){
    double rang = (double) b - a;

    double sin_rang = (double) p / q * pi;
    if(rang >= sin_rang){
        int lo = a, hi = b;
        int ans = 0; 
        double st = 0.5 * pi / ((double) p / q);
        double intv = pi / ((double) p / q);
        while(lo <= hi){
            int mid = (a + b) / 2;
            if(a <= st + (double) mid * intv){
                hi = mid - 1;
                ans = mid;
            }
            else lo = mid + 1;
        }
        return ans;
    }
    else{
        int ans = 0;
        double res = 0.0;
        if(res < abs(sin(1.0 * p / q * pi * a))){
            res = abs(sin(1.0 * p / q * pi * a));
            ans = a;
        }
        else if(res == abs(sin(1.0 * p / q * pi * a))){
            ans = a;
        }
        if(res < abs(sin(1.0 * p / q * pi * b))){
            res = abs(sin(1.0 * p / q * pi * b));
            ans = b;
        }
        else if(res == abs(sin(1.0 * p / q * pi * b))){
            ans = b;
        }

        int lo = a, hi = b;
        double prev = abs(sin(1.0 * p / q * lo));
        while(1){
            int mid = (lo + hi) / 2;
            if(abs(sin(1.0 * p / q * pi * mid) > abs(sin(1.0 * p / q * p))))
        }

        return ans;
    }

}

int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>a>>b>>p>>q;
        cout<<solve()<<endl;
    }


    return 0;
}

