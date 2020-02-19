#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char charset[3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	string s;
	cin>>n;
	charset[0] = 'a';
	charset[1] = 'b';
	charset[2] = 'c';
	while(n--){
		cin>>s;
		bool flag = false;
		for(int i = 1; i < (int) s.size(); i++){
			if(s[i] == s[i - 1] && s[i] != '?') {
				cout<<-1<<endl;
				flag = true;
				break;
			}
		}
		if(flag){
			continue;
		}
		for(int i = 0; i < (int) s.size(); i++){
			if(s[i] == '?'){
				char left;
				if(i == 0) left = '?';
				else left = s[i - 1];
				char right;
				if(i == (int) s.size() - 1) right = '?';
				else right = s[i + 1];
				for(int j = 0; j < 3; j++){
					if(charset[j] != left &&  charset[j] != right){
						s[i] = charset[j];
					}
				}
			}
		}
		cout<<s<<endl;

	}

	return 0;
}
