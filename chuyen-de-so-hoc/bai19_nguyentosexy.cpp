#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e7 + 7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai19_nguyentosexy.inp", "r")) {
		freopen("bai19_nguyentosexy.inp", "r", stdin);
		freopen("bai19_nguyentosexy.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e7; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 1e7; j += i)
				p[j] = 0;
		}
	}

	vector<pair<int, int>>res;
	for (int i = 7; i <= 1e7; i++) {
		if (p[i] && p[i - 6])
			res.push_back({ i - 6,i });
	}
	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		cout << res[n - 1].first << ' ' << res[n - 1].second << '\n';
	}
}
