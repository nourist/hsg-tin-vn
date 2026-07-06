#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int f[255];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("kcha.inp", "r")) {
		freopen("kcha.inp", "r", stdin);
		freopen("kcha.out", "w", stdout);
	}

	string str;
	int k;
	cin >> str >> k;

	int l = 0, r = 0, cnt = 0, res = 0;
	while (r < str.size()) {
		f[str[r]]++;
		if (f[str[r]] == 1)cnt++;
		while (cnt > k) {
			f[str[l]]--;
			if (f[str[l]] == 0)cnt--;
			l++;
		}
		res = max(res, r - l + 1);
		r++;
	}
	cout << res;
}
