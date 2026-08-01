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
#define Name "NICE"

int bit[(int)1e5 + 5];

void update(int idx, int val) {
	if (idx == 0)return;
	for (idx; idx <= 1e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], val);
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res = max(res, bit[idx]);
	return res;
}

int a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	reverse(a + 1, a + n + 1);

	FOR(i, 1, n) {
		if (i > a[i]) update(i, query(i - a[i] - 1) + a[i] + 1);
	}
	cout << n - query(n);
}
