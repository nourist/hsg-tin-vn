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

int a[(int)1e5 + 5];
vi divisors[(int)1e5 + 5];

struct Query {
	ll id, l, r, res;
}qr[(int)1e5 + 5];

int f[(int)1e5 + 5];
int fd[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	for (int i = 1; i * i <= 1e5; i++) {
		divisors[i * i].pb(i);
		for (int j = i * (i + 1); j <= 1e5; j += i) {
			divisors[j].pb(i);
			divisors[j].pb(j / i);
		}
	}

	int n, q;
	cin >> n >> q;

	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, q) { cin >> qr[i].l >> qr[i].r; qr[i].id = i; }

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		if (x.l / 300 == y.l / 300) {
			if (x.l / 300 % 2 == 0)return x.r > y.r;
			else return x.r < y.r;
		}
		return x.l / 300 < y.l / 300;
		});

	ll res = 0;
	int curL = 1, curR = 0;
	FOR(i, 1, q) {
		while (curR < qr[i].r) {
			curR++;
			f[a[curR]]++;
			res += fd[a[curR]];
			for (int d : divisors[a[curR]]) {
				res += f[d];
				fd[d]++;
			}
		}
		while (curR > qr[i].r) {
			f[a[curR]]--;
			res -= fd[a[curR]];
			for (int d : divisors[a[curR]]) {
				res -= f[d];
				fd[d]--;
			}
			curR--;
		}
		while (curL < qr[i].l) {
			f[a[curL]]--;
			res -= fd[a[curL]];
			for (int d : divisors[a[curL]]) {
				res -= f[d];
				fd[d]--;
			}
			curL++;
		}
		while (curL > qr[i].l) {
			--curL;
			f[a[curL]]++;
			res += fd[a[curL]];
			for (int d : divisors[a[curL]]) {
				res += f[d];
				fd[d]++;
			}
		}
		qr[i].res = res;
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.id < y.id;
		});

	FOR(i, 1, q)cout << qr[i].res << endl;
}
