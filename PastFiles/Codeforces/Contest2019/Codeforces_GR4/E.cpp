#include <bits/stdc++.h>
using namespace std;
string s;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    
    int j = s.size() - 1;
    int i = 0;
    string A;
    while(j - i >= 3){
        if(s[i] == s[j]){
            A.push_back(s[i]);
            i++;
            j--;
        }
        else if(s[i + 1] == s[j]){
            A.push_back(s[i + 1]);
            i += 2;
            j--;
        }
        else if(s[i] == s[j - 1]){
            A.push_back(s[j - 1]);
            j -= 2;
            i++;
        }
        else{
            A.push_back(s[i + 1]);
            i += 2;
            j -= 2;
        }
    }
    string B = A;
    if(j >= i) A.push_back(s[i]);
    reverse(B.begin(), B.end());
    cout<<A<<B<<endl;
    
}