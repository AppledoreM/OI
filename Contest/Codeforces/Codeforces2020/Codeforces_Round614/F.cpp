#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <array>
#include <climits>
#include <assert.h>
#include <map>
using namespace std;
constexpr int maxn = 1000005;
const int maxk = 5005;
typedef pair<int,int> pii;
int n;
vector<int> arr;
array<int, maxk> count_pf, sumk;
array<bool, maxk> is_prime;
vector<int> prime_list;
vector<pii> facs[maxn], temp[maxn];
int prime_cnt[maxk][maxk];
int cnt[maxk];
long long ans = 0;



// This function preprocess prime number
void preprocess(){
	for (int i = 2; i <= 5000; i++) {
		for (int j = 0; j <= 5000; j++) {
			prime_cnt[i][j] = prime_cnt[i - 1][j];
		}
		int tmp = i;
		for (int x = 2; x * x <= tmp; x++) {
			while (tmp % x == 0) {
				tmp /= x;
				prime_cnt[i][x]++;
			}
		}
		if (tmp > 1) prime_cnt[i][tmp]++;
	}
}

void solve(){
    
	vector<int> biggestPrime(5001, 1);
	for (int i = 1; i <= 5000; i++) {
		if (!cnt[i]) { biggestPrime[i] = 1; continue; }
		for (int j = 1; j <= 5000; j++) {
			ans += 1ll * prime_cnt[i][j] * cnt[i];
			if (prime_cnt[i][j]) biggestPrime[i] = j;
		}
	}

	while (*max_element(biggestPrime.begin(), biggestPrime.end()) > 1) {
		vector<int> frequency(5001, 0);
		for (int i = 0; i <= 5000; i++) frequency[biggestPrime[i]] += cnt[i];
		int bestloc = max_element(frequency.begin(), frequency.end()) - frequency.begin();
		int sz = frequency[bestloc];
		if (sz * 2 <= n) break;
		if (bestloc == 1) break;
		ans = ans + n - 2 * sz;

		for (int i = 0; i <= 5000; i++) {
			if (biggestPrime[i] != bestloc) biggestPrime[i] = 1;
			if (biggestPrime[i] == 1) continue;
			prime_cnt[i][biggestPrime[i]]--;
			while (biggestPrime[i] > 1 && prime_cnt[i][biggestPrime[i]] == 0) biggestPrime[i]--;
		}
	}
	cout << ans << endl;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		arr.emplace_back(x);
	}
    preprocess();
    solve();
  
    return 0;
}
