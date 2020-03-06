#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(char cur_char = 'z'; cur_char >= 'b'; cur_char--){
        while(true){
            bool flag = false;
            for(int i = 0; i < (int) s.size(); i++){
                if(s[i] != cur_char) continue;
                if(i - 1 >= 0){
                    if(s[i - 1] + 1 == cur_char){
                        s.erase(s.begin() + i);
                        flag = true;
                        break;
                    }    
                }
                if(i + 1 < (int) s.size()){
                    if(s[i + 1] + 1 == cur_char){
                        s.erase(s.begin() + i);
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
    }
    cout<<n - (int) s.size()<<endl;

    return 0;
}