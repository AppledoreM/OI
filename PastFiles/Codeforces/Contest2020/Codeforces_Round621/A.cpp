#include <iostream>
using namespace std;

int n;
int a[105];
int main(){
    cin>>n;

    while(n--){
        int num, d;
        cin>>num>>d;
        int tot = 0;
        
        for(int i = 1; i <= num; i++){
            cin>>a[i];
            if(i > 1){
                if(d >= a[i] * (i - 1)){
                    d -= a[i] * (i - 1);
                    tot += a[i];
                }
                else if(d) {
                    tot += (int) d / (i - 1);
                    d = 0;
                }
            }
        }
        cout<<a[1] + tot<<endl;
    }


    return 0;
}