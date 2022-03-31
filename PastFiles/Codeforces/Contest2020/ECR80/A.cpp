#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

int calc(int x, int d){
    return x + ceil(1.0 * d / (1.0 * x + 1));
}


int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,d;
        cin>>n>>d;

	int x, y;
	y = sqrt(d) + 10;
	for(x = 0; x < y; x++){
		if(calc(x, d) <= n) break;
	}
	if(x < y) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
    }


    return 0;
}

