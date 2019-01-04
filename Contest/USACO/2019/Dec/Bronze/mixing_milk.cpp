#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
typedef pair<int,int> pii;
pii buc[4];


int main()
{
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    FAST_IO;
    for(int i = 1; i <= 3; i++){
        cin>>buc[i].first>>buc[i].second;
    }

    for(int i = 1; i <= 33; i++){
        if(buc[1].second + buc[2].second <= buc[2].first){
            buc[2].second += buc[1].second;
            buc[1].second = 0;
        }
        else {
            buc[1].second -= (buc[2].first - buc[2].second); 
            buc[2].second = buc[2].first;
        }

        if(buc[2].second + buc[3].second <= buc[3].first){
            buc[3].second += buc[2].second;
            buc[2].second = 0;
        }
        else {
            buc[2].second -= (buc[3].first - buc[3].second); 
            buc[3].second = buc[3].first;
        }
        if(buc[1].second + buc[3].second <= buc[1].first){
            buc[1].second += buc[3].second;
            buc[3].second = 0;
        }
        else {
            buc[3].second -= (buc[1].first - buc[1].second); 
            buc[1].second = buc[1].first;
        }
    }
        
    if(buc[1].second + buc[2].second <= buc[2].first){
        buc[2].second += buc[1].second;
        buc[1].second = 0;
    }
    else {
        buc[1].second -= (buc[2].first - buc[2].second); 
        buc[2].second = buc[2].first;
    }
    for(int i = 1; i <= 3; i++) cout<<buc[i].second<<endl;
    return 0;
}

