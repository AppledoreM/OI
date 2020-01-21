#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false)

const int maxn = 1e5 + 10;
int arr[3][maxn], bloc;

bool check(int r,int c){
    int oth = (r % 2) + 1;
    if(arr[oth][c]) bloc++;
    if(arr[oth][c - 1]) bloc++;
    if(arr[oth][c + 1]) bloc++;
    if(arr[oth][c] || arr[oth][c - 1] || arr[oth][c + 1]) return true;
    return false;
}

void change(int r, int c){
    int oth = (r % 2) + 1;
    if(arr[oth][c]) bloc--;
    if(arr[oth][c - 1]) bloc--;
    if(arr[oth][c + 1]) bloc--;
}

int main()
{

    FAST_IO;
    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= q; i++){
        int r,c;
        cin>>r>>c;
        if(arr[r][c] == 0){
            check(r,c);
        }
        else{
            change(r,c);
        }
        arr[r][c] = !arr[r][c];

        if(bloc) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}

