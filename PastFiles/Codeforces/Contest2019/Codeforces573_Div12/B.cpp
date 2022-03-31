#include <bits/stdc++.h>
using namespace std;
vector<string> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0; i < 3; i++){
        string tmp;
        cin>>tmp;
        s.emplace_back(tmp);
    }
    bool all_equal = true;
    for(int i = 1; i < 3; i++){
        if(s[i] != s[i - 1]){
            all_equal = false;
            break;
        }
    }
    if(all_equal){
        cout<<0<<endl;
        exit(0);
    }
    bool all_one_dif = true;
    vector<int> v;
    for(int i = 1; i < 3; i++){
        if(s[i][1] != s[i - 1][1]) all_one_dif = false;
    }
    for(int i = 0; i < 3; i++) v.emplace_back(s[i][0] - '0');
    sort(v.begin(), v.end());
    for(int i = 1; i < 3; i++){
        if(v[i] - v[i - 1] != 1){
            all_one_dif = false;
        }
    }
    if(all_one_dif){
        cout<<0<<endl;
        exit(0);
    }

    bool one_move = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != j){
                int num1 = s[i][0] - '0';
                int num2 = s[j][0] - '0';
                char suit1 = s[i][1];
                char suit2 = s[j][1];
                if(suit1 == suit2 && abs(num1 - num2) <= 2){
                    one_move = true;
                }
            }
        }
    }
    if(one_move){
        cout<<1<<endl;
        exit(0);
    }
    cout<<2<<endl;
    


    return 0;
}