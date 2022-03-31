#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)



int main()
{
    int n,k;
    cin>>n>>k;
    if(k == 0){
        cout<<1<<endl;
    }
    else if(k < n / 2){
        cout<<k<<endl;
    }
    else if(k == n / 2){
        cout<<k<<endl;
    }
    else{
        cout<<n - k<<endl;
    }

    return 0;
}
