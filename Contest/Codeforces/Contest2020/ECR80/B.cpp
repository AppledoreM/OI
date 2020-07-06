#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int A,B;
        cin>>A>>B;
        int C = B + 1;
        bool flag = false;
        for(int i = 1; i <= 9; i++){
            if(C == pow(10,i)){
                flag = true;
                break;
            }
        }
        int cnt = 0;
        if(flag) cnt++;
        while(B){
            cnt++;
            B /= 10;
        }
        cnt--;
        cout<< 1ll * A * cnt<<endl;
    }
}