#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)3e3], f1[(int)3e3], f2[(int)3e3];


unordered_map<int, int>mp;


int maxgcd(int n) {
	int res = 1;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			mp[i]++;
			if (i * i != n)
				mp[n / i]++;
			if (mp[i] > 1)res = max(res, i);
			if (mp[n / i] > 1)res = max(res, n / i);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("MAXGCD.INP", "r", stdin);
	freopen("MAXGCD.OUT", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		f1[i] = max(maxgcd(a[i]), f1[i - 1]);
	}
	mp.clear();
	for (int i = n - 1; i >= 0; i--) {
		f2[i] = max(maxgcd(a[i]), f2[i - 1]);
	}

	int res = 0;
	for (int i = 1; i < n - 2; i++) {
		res = max(res, f1[i] + f2[i + 1]);
	}

	cout << res;
}
