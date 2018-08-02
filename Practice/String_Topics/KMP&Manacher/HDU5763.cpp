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
int T,dp[maxn],fail[maxn];
string s1,s2;
int used[maxn];
void build(string s){
	int i = 0,j = -1;
	fail[0] = j;
	while(i < (int) s.size()){
		if(j == -1 || s[i] == s[j]){
			fail[++i] = ++j;
		}
		else j = fail[j];
	}
}

int main(){
	FAST_IO;
	cin>>T;
	int cnt = 0;
	while(T--){
		memset(fail,0,sizeof(fail));
		memset(dp,0,sizeof(dp));
		cin>>s1>>s2;
		build(s2);
		int i = 0,j = 0;
		while(i < s1.size()){
			if(j == -1 || s1[i] == s2[j]){
				i++,j++;
				used[i] = j;
				if(j == s2.size()) j = fail[j];
			}
			else j = fail[j];
		}
		dp[0] = 1;
		for(int i = 1; i <= s1.size(); i++){
			dp[i] = dp[i - 1];
			if(used[i] == s2.size()) dp[i] = (dp[i] + dp[i - s2.size()]) % 1000000007;
		}
		cout<<"Case #"<<++cnt<<": "<<dp[s1.size()]<<endl;
	}
	
	return 0;
}

