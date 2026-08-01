#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b4"

string s;
int k, n;

bool isNa(char ch) {
	return ch == 'u' || ch == 'e' || ch == 'o' || ch == 'a' || ch == 'i';
}

ll solveRange(int u, int v) {
	// Trường hợp: Trái là Nguyên âm, Phải là Phụ âm
	ll res = 0;
	int p1 = u, p2 = u;
	int sum_v1 = 0, sum_v2 = 0;
	int sumY = 0;

	FOR(i, v, n) {
		if (isNa(s[i])) break;
		sumY += s[i];

		while (p1 >= 1 && isNa(s[p1]) && sum_v1 + s[p1] <= k + sumY) {
			sum_v1 += s[p1];
			p1--;
		}
		while (p2 >= 1 && isNa(s[p2]) && sum_v2 + s[p2] < sumY) {
			sum_v2 += s[p2];
			p2--;
		}
		res += (p2 - p1);
	}
	return res;
}

ll solveRange2(int u, int v) {
	ll res = 0;
	int p1 = u, p2 = u;
	int sum_c1 = 0, sum_c2 = 0;
	int sumX = 0;

	FOR(i, v, n) {
		if (!isNa(s[i])) break;
		sumX += s[i];

		while (p1 >= 1 && !isNa(s[p1]) && sum_c1 + s[p1] <= sumX) {
			sum_c1 += s[p1];
			p1--;
		}
		while (p2 >= 1 && !isNa(s[p2]) && sum_c2 + s[p2] < sumX - k) {
			sum_c2 += s[p2];
			p2--;
		}
		res += (p2 - p1);
	}
	return res;
}

ll solve() {
	ll res = 0;
	FOR(i, 2, n) {
		if (isNa(s[i - 1]) && !isNa(s[i])) {
			res += solveRange(i - 1, i);
		}
		else if (!isNa(s[i - 1]) && isNa(s[i])) {
			res += solveRange2(i - 1, i);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> s >> k;

	n = s.size();
	s = "_" + s;

	cout << solve();
}
