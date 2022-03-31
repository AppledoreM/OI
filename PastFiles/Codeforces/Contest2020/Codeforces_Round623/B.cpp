#include <iostream>
#include<string> 
using namespace std;
 
#define MAX 1001
#define INF 0x3F3F3F3F
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
 
int a, b, p;
string s;
 
bool f(int pos){
    if(pos == s.length() - 1)
        return true;
    int res = (s[pos] == 'A' ? a : b);
    for(int i = pos + 1; i < s.length() - 1; i++){
        if(s[i] != s[i - 1]){
            (s[i] == 'A') ? res += a : res += b;
        }
    }
    return res <= p;
}   
 
signed main(){
    fast;
    int t; cin >> t; 
    while (t--)
    {
        cin >> a >> b >> p;
        cin >> s;
        int l = 0, r = s.length() - 1;
        while(r - l > 0){
            int mid = (r + l) / 2;
            if(f(mid)){
                r = mid;
            }
            else l = mid + 1;
        }
        cout << l + 1 << endl;
    }
    
 
}