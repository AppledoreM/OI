#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
vector<int> v, a;
int n,m;

void output_pt(int a,int b){
    printf("%d %d\n",a,b);
}



int main()
{
    FAST_IO;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        v.emplace_back(i);
    }

    bool is_front = true;
    for(int i = 1; i <= n; i++){
        if(is_front){
            a.emplace_back(v[0]);
            v.erase(v.begin());
        }
        else{
            a.emplace_back(v.back());
            v.erase(v.end() - 1);
        }
        is_front ^= 1;
    }

    for(int i = 1; i * 2 <= n; i++){
        for(int j = 1; j <= m; j++){
            output_pt(a[i * 2 - 2], j);
            output_pt(a[i * 2 - 1], m - j + 1);
        }
    }
    if(n % 2 == 1){
        v.clear();
        for(int i = 1; i <= m; i++) v.emplace_back(i);

        int row = n / 2 + 1;
        is_front = true;
        for(int i = 1; i <= m; i++){
            if(is_front){
                output_pt(row, v[0]);
                v.erase(v.begin());
            }
            else{
                output_pt(row, v.back());
                v.erase(v.end() - 1);
            }
            is_front ^= 1;
        }
    }



    return 0;
}

