#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
int n;
string s;



int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s;
    int cntone,cntzero;
    cntone = cntzero = 0;
    for(int i = 0; i <(int) s.size(); i++){
        if(s[i] == '1') cntone++;
        else cntzero++;
    }

    if(cntone != cntzero){
        cout<<1<<endl<<s<<endl;
    }
    else{
        cout<<2<<endl;
        cout<<s[0]<<" "<<s.substr(1)<<endl;
    }


    return 0;
}

