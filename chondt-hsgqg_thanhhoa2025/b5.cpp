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
#define Name "b5"

int n, k;
int a[(int)3e5 + 5][22];
int m[22];
int stride[22];
int f[(int)3e5 + 5];

int getKey(int d[]) {
	int res = 0;
	FOR(i, 1, k) {
		res += d[i] * stride[i];
	}
	return res;
}

void sub1() {
	FOR(i, 1, n) {
		int res = 0;
		FOR(j, 1, n) {
			int cnt = 0;
			FOR(d, 1, k) {
				if (a[i][d] >= a[j][d]) {
					cnt++;
				}
			}
			res += cnt == k;
		}
		cout << res - 1 << endl;
	}
	exit(0);
}

void sub2() {
	vi v;
	FOR(i, 1, n)v.pb(a[i][1]);
	sort(all(v));
	FOR(i, 1, n)cout << upper_bound(all(v), a[i][1]) - v.begin() - 1 << endl;
	exit(0);
}

int id[(int)3e5 + 5];
int res[(int)3e5 + 5];

int bit[(int)3e5 + 5];

void update(int idx) {
	for (idx += 1; idx <= 3e5 + 1; idx += (idx & (-idx)))bit[idx]++;
}

int query(int idx) {
	int res = 0;
	for (idx += 1; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
	return res;
}

void sub3() {
	FOR(i, 1, n)id[i] = i;

	vi v;
	FOR(i, 1, n)v.pb(a[i][2]);
	sort(all(v));
	v.erase(unique(all(v)), v.end());

	FOR(i, 1, n)a[i][2] = lower_bound(all(v), a[i][2]) - v.begin() + 1;

	sort(id + 1, id + n + 1, [&](int x, int y) {
		if (a[x][1] == a[y][1])return a[x][2] < a[y][2];
		return a[x][1] < a[y][1];
		});

	FOR(i, 1, n) {
		res[id[i]] = query(a[id[i]][2]);
		update(a[id[i]][2]);
	}

	FOR(i, 1, n)cout << res[i] << endl;

	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, k)cin >> m[i];
	FOR(i, 1, n)FOR(j, 1, k)cin >> a[i][j];


	if (n <= 1e3)sub1();
	if (k == 1)sub2();
	if (k == 2)sub3();

	stride[k + 1] = 1;
	FOD(i, k, 1) {
		stride[i] = stride[i + 1] * (m[i + 1] + 1);
	}

	int s = stride[1] * (m[1] + 1);

	FOR(i, 1, n)f[getKey(a[i])]++;
	FOR(d, 1, k) {
		FOR(id, 0, s) {
			int coord = (id / stride[d]) % (m[d] + 1);

			if (coord > 0)
				f[id] += f[id - stride[d]];
		}
	}

	FOR(i, 1, n)cout << f[getKey(a[i])] - 1 << endl;
}