#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
int prime[MAXN],v[5*MAXN];
int m=0;
int n;
void primes()
{
    for(int i=2;i<MAXN ;i++)
    {
        if(v[i]==0)
        {
            v[i] = i;
             prime[++m] = i;
        }
        for(int j = 1;j<=m;j++)
        {
            if(prime[j] > v[i] || prime[j] > MAXN/i) break;
            v[i*prime[j]] = prime[j];
        }
    }
}

bool solve(){

    for(int i = 0; i < m; i++){
        if(prime[i] > n * (n - 1) / 2) break;
        if(prime[i] >= n){
            if(n == prime[i]){
                cout<<n<<endl;
                for(int k = 2; k <= n; k++){
                    cout<<k - 1<<" "<<k<<endl;
                }
                cout<<1<<" "<<n<<endl;
                return true;
            }

            for(int j = 0; j < m; j++){
                if(prime[j] >= n) break;
                if(prime[i] - n <= n / 2){

                    cout<<prime[i]<<endl;
                    for(int k = 2; k <= n; k++){
                        cout<<k - 1<<" "<<k<<endl;
                    }
                    cout<<1<<" "<<n<<endl;

                    for(int k = 1; k <= prime[i] - n; k++){
                        cout<<k<<" "<<k + n / 2<<endl;
                    }
                    return true;
                }
            }
        }
    }
    return false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    primes();
    

    if(!solve()) cout<<-1<<endl;



    return 0;
}