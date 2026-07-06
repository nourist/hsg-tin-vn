#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "bai3"
#define BIT(m, i) ((m>>i)&1)
#define MASK(m, i) (m|(1<<i))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, k;
	string s;
	cin >> n >> k >> s;

	unordered_map<int, bool>mp;
	vector<int> a = { 0 };

	FOR(i, 1, n) {
		if (s[i - 1] == '1')
			a[0] = MASK(a[0], i);
	}

	mp[a[0]] = 1;
	while (1) {
		int prev = a.back();
		int cur = 0;

		FOR(i, 1, n) {
			int val;
			if (BIT(prev, i - 1) == 1 && BIT(prev, i) == 1 && BIT(prev, i + 1) == 1) {
				val = 1 - BIT(prev, i);
			}
			else if (BIT(prev, i - 1) == 0 && BIT(prev, i) == 0 && BIT(prev, i + 1) == 1) {
				val = 1 - BIT(prev, i);
			}
			else if (BIT(prev, i - 1) == 0 && BIT(prev, i) == 1 && BIT(prev, i + 1) == 0) {
				val = BIT(prev, i);
			}
			else if (BIT(prev, i - 1) == 1 && BIT(prev, i) == 1 && BIT(prev, i + 1) == 0) {
				val = BIT(prev, i);
			}
			else if (BIT(prev, i - 1) == 1 && BIT(prev, i) == 0 && BIT(prev, i + 1) == 1) {
				val = 1;
			}
			else if (BIT(prev, i - 1) == 0 && BIT(prev, i) == 1 && BIT(prev, i + 1) == 1) {
				val = 1;
			}
			else {
				val = 0;
			}

			if (val)
				cur = MASK(cur, i);
		}

		if (mp[cur])break;
		mp[cur] = 1;
		a.push_back(cur);
	}

	k %= a.size();

	FOR(i, 1, n) {
		cout << BIT(a[k], i);
	}
	cout << endl;
}