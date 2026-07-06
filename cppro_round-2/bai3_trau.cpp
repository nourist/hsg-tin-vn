#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "bai3"

bool special[255];

bool f[255];
string s, t;
int n, k, L, R;


bool ok(int l, int r) {
	memset(f, 0, sizeof f);
	FOR(i, l, r) {
		if (special[s[i]])
			f[s[i]] = 1;
	}
	int sum = 0;
	FOR(i, 'a', 'z')if (f[i])sum++;

	return L <= sum && sum <= R;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	cin >> n >> k >> L >> R >> s >> t;

	s = "_" + s;

	for (auto i : t)special[i] = 1;

	int res = 0;

	FOR(i, 1, n)FOR(j, 1, i)res += ok(j, i);

	cout << res;
}