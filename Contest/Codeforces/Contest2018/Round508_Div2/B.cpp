#include "stdafx.h" 
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <assert.h>
#include <stack>
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	if (n <= 2) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		cout << n / 2 << " ";
		for (int i = 2; i <= n; i += 2) {
			cout << i << " ";
		}
		cout << endl << n / 2 + (n & 1) << " ";
		for (int i = 1; i <= n; i += 2) {
			cout << i << " ";
		}
	}
	return 0;
}