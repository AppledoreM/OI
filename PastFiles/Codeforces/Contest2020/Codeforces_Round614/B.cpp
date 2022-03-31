#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)



int main()
{
    FAST_IO;
    int n;
    cin>>n;
    double result = 0.0;
    for(int i = 1; i <= n; i++){
        result += (double) 1 / (double) i; 
    }

    cout<<result<<endl;



    return 0;
}

