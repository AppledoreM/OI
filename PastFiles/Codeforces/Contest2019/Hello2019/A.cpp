#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
string a;


int main()
{
    cin>>a;
    for(int i = 0; i < 5; i++){
        string tmp;
        cin>>tmp;
        if(tmp[0] == a[0] || tmp[1] == a[1]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}

