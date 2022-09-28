//Based on Solutions from VJudge, understood and re-implemented

#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<cd> vcd;

void fft(vcd &v, bool inverse){
	int len = v.size();
	if(len == 1){
		return;
	}
	vcd ve(len / 2), vo(len / 2);
	for(int i = 0; i < len / 2; ++i){
		ve[i] = v[i * 2];
		vo[i] = v[i * 2 + 1];
	}
	fft(ve, inverse);
	fft(vo, inverse);
	double angle = 2 * acos(-1.0) * (inverse * -2 + 1) / (double)len;
	cd a(1), omega(cos(angle), sin(angle));
	for(int i = 0; i < len / 2; ++i){
		double divide = inverse + 1;
		v[i] = (ve[i] + a * vo[i]) / divide;
		v[i + len / 2] = (ve[i] - a * vo[i]) / divide;
		a *= omega;
	}
}

vll poly_mult(vll const& v1, vll const& v2){
	vcd c1(v1.begin(), v1.end()), c2(v2.begin(), v2.end());

	int n = 1, tot = v1.size() + v2.size();
	while(n < tot){
		n <<= 1;
	}

	c1.resize(n);
	c2.resize(n);

	vll res(n);

	fft(c1, false);
	fft(c2, false);

	for(int i = 0; i < n; ++i){
		c1[i] *= c2[i];
	}
	fft(c1, true);
	for(int i = 0; i < n; ++i){
		res[i] = round(c1[i].real());
	}

	return res;
}

int main(){

}