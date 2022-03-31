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
int T,N,dp[maxn],fail[maxn];
const int mod = 10007;
string s;

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
	FAST_IO
	cin>>T;
	while(T--){
		cin>>N>>s;
		build(s);
		for(int i = 1; i <= N; i++) dp[i] = 1;
		for(int i = N; i; i--){
			dp[fail[i]] = (dp[fail[i]] + dp[i]) % mod;
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) ans = (ans + dp[i]) % mod;
		cout<<ans<<endl;
	}

	return 0;
}

