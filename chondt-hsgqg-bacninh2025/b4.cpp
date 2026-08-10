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

int n, q;
int a[(int)5e4 + 4];

struct Query {
	ll id, u, v, delta, res = 0;
}qr[(int)2e5 + 5];

ll res[(int)5e4 + 4];
int f1[(int)5e4 + 4];
int f2[(int)5e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, q) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		qr[(i - 1) * 4 + 1] = { i, y, v, 1 };
		qr[(i - 1) * 4 + 2] = { i, y, u - 1, -1 };
		qr[(i - 1) * 4 + 3] = { i, x - 1, v, -1 };
		qr[(i - 1) * 4 + 4] = { i, x - 1, u - 1, 1 };
	}

	const int block = 222;
	sort(qr + 1, qr + q * 4 + 1, [&](Query x, Query y) {
		if (x.u / block == y.u / block) {
			if (x.u / block % 2) {
				return x.v < y.v;
			}
			else {
				return x.v > y.v;
			}
		}
		return x.u / block < y.u / block;
		});

	ll curRes = 0;
	int curR = 0, curL = 0;
	FOR(i, 1, q * 4) {
		while (curR < qr[i].v) {
			curR++;
			curRes += f1[a[curR]];
			f2[a[curR]]++;
		}
		while (curR > qr[i].v) {
			curRes -= f1[a[curR]];
			f2[a[curR]]--;
			curR--;
		}
		while (curL < qr[i].u) {
			curL++;
			curRes += f2[a[curL]];
			f1[a[curL]]++;
		}
		while (curL > qr[i].u) {
			curRes -= f2[a[curL]];
			f1[a[curL]]--;
			curL--;
		}
		res[qr[i].id] += curRes * qr[i].delta;
	}
	FOR(i, 1, q)cout << res[i] << endl;
}

/*
(f(i, y) - f(i, x-1))*(f(i, v) - f(i, u-1))
f(i, y) * f(i, v) - f(i, x-1) * f(i, v) - f(i, y) * f(i, u-1) + f(i, x-1) * f(i, u-1)
*/