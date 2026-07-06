#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "catdayso"

int n;
string s;
vii num;

int bit[(int)2e3 + 3];

void update(int idx, int v) {
	if (idx == 0)return;
	for (idx; idx <= 2e3; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res = max(res, bit[idx]);
	return res;
}

int nx[(int)2e3 + 3];
int lcp[(int)2e3 + 3][(int)2e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> s;

	s = "_" + s;

	FOR(i, 1, n)
		FOR(j, i, n)
		num.push_back({ i, j });

	nx[n + 1] = n + 1;

	FOD(i, n, 1) {
		if (s[i] == '0')nx[i] = nx[i + 1];
		else nx[i] = i;
	}

	FOD(i, n, 1)FOD(j, n, 1) {
		if (s[i] != s[j])lcp[i][j] = 0;
		else lcp[i][j] = lcp[i + 1][j + 1] + 1;
	}

	sort(num.begin(), num.end(), [&](pii x, pii y) {
		int l1 = x.X;
		int l2 = y.X;

		int r1 = x.Y;
		int r2 = y.Y;

		l1 = min(nx[l1], r1);
		l2 = min(nx[l2], r2);

		if (r1 - l1 == r2 - l2) {
			int c = lcp[l1][l2];

			l1 += c;
			l2 += c;

			if (l1 <= r1)return s[l1] < s[l2];

			return r1 < r2;
		}
		return r1 - l1 < r2 - l2;
		});

	FOR(i, 0, num.size() - 1) {
		update(num[i].Y, query(num[i].X - 1) + 1);
	}

	cout << query(n);
}