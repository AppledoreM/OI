#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef complex<double> cd;

void fft(vector<cd> &a, bool invert){
	int n = a.size();
	if(n == 1)
		return;
	vector<cd> a0(n / 2), a1(n / 2);
	for(int i = 0; i < n / 2; ++i){
		a0[i] = a[2 * i];
		a1[i] = a[2 * i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double ang = 2 * acos(-1.0) / n * (invert ? -1 : 1);
	cd w(1), wn(cos(ang), sin(ang));
	for(int i = 0; i * 2 < n; ++i){
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if(invert){
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

vll mult(vll const& a, vll const& b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

	int n = 1;
	while(n < a.size() + b.size()){
		n = n << 1;
	}

	fa.resize(n);
	fb.resize(n);

	vll c(n);
	fft(fa, false);
	fft(fb, false);

	for(int i = 0; i < n; ++i){
		fa[i] *= fb[i];
	}
	fft(fa, true);
	for(int i = 0; i < n; ++i){
		c[i] = round(fa[i].real());
	}

	return c;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		ll n, x, m;
		cin >> n;
		vll a, b;
		for(int i = 0; i <= n; ++i){
			scanf("%lld", &x);
			a.push_back(x);
		}
		cin >> m;
		for(int i = 0; i <= m; ++i){
			scanf("%lld", &x);
			b.push_back(x);
		}
		vll res = mult(a, b);
		cout << n + m << endl;
		cout << res[0];
		for(int i = 1; i <= m + n; ++i){
			printf(" %lld", res[i]);
		}
		cout << endl;
	}
	return 0;
}