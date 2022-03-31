#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)
int n;
typedef pair<int,int> pii;
vector<pii>  lev[20];


int main()
{
    FAST_IO;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        lev[1].emplace_back(pii(x,0));
    }

    int cur = 1;
    for(int i = 2; (1 << (i - 1)) <= n; i++){
        cur *= 2;
        for(int j = 0; j + cur / 2< (int) lev[i - 1].size(); j++){
            int candie1 = lev[i - 1][j].second;
            int candie2 = lev[i - 1][j + cur / 2].second;
            int dig1 = lev[i - 1][j].first;
            int dig2 = lev[i - 1][j + cur / 2].first;
            
            int new_candie = candie1 + candie2 + (int)(dig1 + dig2 >= 10);
            int new_dig = (dig1 + dig2) % 10;

            lev[i].emplace_back(pii(new_dig,new_candie));
        }
    }

    int q;
    cin>>q;
    for(int i = 1; i <= q; i++){
        int l,r;
        cin>>l>>r;
        int len = r - l + 1;
        int dep = 1;
        while(len / 2){
            len /= 2;
            dep++;
        }

        cout<<lev[dep][l - 1].second<<endl;
        
    }



    return 0;
}

