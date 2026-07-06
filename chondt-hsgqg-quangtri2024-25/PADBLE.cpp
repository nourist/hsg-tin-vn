#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

struct Hash {
	int mod;
	ll basePow[(int)1e5 + 5];
	ll hashS[(int)1e5 + 5];

	Hash(int _mod) : mod(_mod) {
		basePow[0] = 1;
		FOR(i, 1, 1e5)basePow[i] = basePow[i - 1] * 26 % mod;
	}

	void build(string s) {
		FOR(i, 1, s.size())hashS[i] = (hashS[i - 1] * 26 + s[i - 1] - '0' + 1) % mod;
	}

	int get(int l, int r) {
		return (hashS[r] - hashS[l - 1] * basePow[r - l + 1] % mod + mod) % mod;
	}
}hashS1(1e9 + 7), hashS2(1e9 + 9), hashR1(1e9 + 7), hashR2(1e9 + 9);

int n;
int f[(int)1e5 + 5][26];

bool palindrome(int l, int r) {
	return hashS1.get(l, r) == hashR1.get(n - r + 1, n - l + 1) &&
		hashS2.get(l, r) == hashR2.get(n - r + 1, n - l + 1);
}

bool checkMoreThan2Diff(int l, int r) {
	int cnt = 0;
	FOR(j, 0, 25)cnt += ((f[r][j] - f[l - 1][j]) != 0);
	return cnt >= 2;
}

bool checkRange(int l, int r) {
	int l2 = (l + r) / 2;
	int r2 = l2 + 1;

	return palindrome(l, l2) && palindrome(r2, r) &&
		checkMoreThan2Diff(l, r);
}

int ok(int l) {
	int res = 0;
	FOR(i, l, n) {
		res += checkRange(i - l + 1, i);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("PADBLE.inp", "r")) {
		freopen("PADBLE.inp", "r", stdin);
		freopen("PADBLE.out", "w", stdout);
	}

	string s;
	cin >> s;

	n = s.size();

	FOR(i, 1, s.size()) {
		FOR(j, 0, 25)f[i][j] += f[i - 1][j];
		f[i][s[i - 1] - 'a']++;
	}

	hashS1.build(s);
	hashS2.build(s);

	reverse(s.begin(), s.end());

	hashR1.build(s);
	hashR2.build(s);

	int res = -1, l = 0, r = n / 2;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid * 2)) {
			res = max(res, mid * 2);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res << ' ';
	if (res != -1) {
		cout << ok(res);
	}
}
