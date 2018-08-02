#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 1e6 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
inline void DEBUG_REACH(){cerr<<"Reach Here"<<endl;}
string s1,s2;
int fail[maxn];
void build(string s){
	int i = 0,j = -1;
	fail[0] = j;
	while(i < s.size()){
		if(j == -1 || s[i] == s[j]){
			fail[++i] = ++j;
		}
		else j = fail[j];
	}
}
int dp[maxn],cnt[maxn];

int main(){
	FAST_IO
	cin>>s1>>s2;
	build(s2);
	for(int i = s2.size() - 1; i < s1.size(); i++){
		bool ok = true;
		for(int j = 0; j < s2.size(); j++) {
			if(s2[s2.size() - j - 1] != s1[i - j] && s1[i - j] != '?'){
				ok = false;
				break;
			}
		}
		dp[i] = dp[i - 1];
		if(ok){
			cnt[i] = dp[i - s2.size()];
			for(int j = fail[s2.size()]; ~j; j = fail[j]){
				cnt[i] = max(cnt[i],cnt[i - (s2.size() - j)]);
			}
			cnt[i]++;
			dp[i] = max(dp[i],cnt[i]);
		}
	}
	cout<<dp[s1.size() - 1]<<endl;
	return 0;
}

