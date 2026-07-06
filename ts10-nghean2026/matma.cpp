#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n;
string s;

void solve1() {
	int res = 0;
	FOR(i, 1, n)res += isdigit(s[i]);
	cout << res << endl;
}

bool p[(int)1e7 + 7];

void solve2() {
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e7; i++)if (p[i])for (int j = i * i; j <= 1e7; j += i)p[j] = 0;

	string cur = "";
	int res = 0;

	s = s + "_";

	FOR(i, 1, n + 1) {
		if (isdigit(s[i])) {
			if (s[i] == '0' && cur.empty())continue;
			cur += s[i];
		}
		else {
			if (!cur.empty() && cur.size() <= 7 && stoi(cur) <= 5e6 && p[stoi(cur)]) {
				res = max(res, stoi(cur));
			}
			cur = "";
		}
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("matma.inp", "r")) {
		freopen("matma.inp", "r", stdin);
		freopen("matma.out", "w", stdout);
	}

	cin >> s;
	n = s.size();
	s = "_" + s;

	solve1();
	solve2();
}
