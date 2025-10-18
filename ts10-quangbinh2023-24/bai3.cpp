#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, a[5005], l[5005], r[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = -a[i];
	}

	vector<int>lis;
	for (int i = 1; i <= n; i++) {
		if (lis.empty() || a[i] > lis.back())lis.push_back(a[i]);
		else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
		l[i] = lis.size();
	}

	lis.clear();
	for (int i = n; i >= 1; i--) {
		if (lis.empty() || a[i] > lis.back())lis.push_back(a[i]);
		else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
		r[i] = lis.size();
	}

	int res = 0;
	for (int i = 1; i < n; i++) {
		if(a[i]>a[i+1])
		res = max(res, l[i] + r[i + 1]);
	}
	cout << res;
}
