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
#define Name "SEQCP"

int p[(int)1e5 + 5];
vi v[(int)7e4 + 4];

vi factorial(int n) {
	vi res;
	while (n != 1) {
		int cur = p[n];
		int cnt = 0;
		while (n % cur == 0) {
			n /= cur;
			cnt++;
		}
		if (cnt % 2 == 1)res.pb(cur);
	}
	return res;
}

int f[(int)7e4 + 4];
int cnt = 0;

void toggle(int x) {
	f[x] ^= 1;

	if (f[x] == 0)cnt--;
	else cnt++;
}

void add(int i) {
	for (auto x : v[i])toggle(x);
}

struct Query {
	int id, l, r, res;
}qr[(int)7e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	FOR(i, 1, 1e5)p[i] = i;
	for (int i = 2; i * i <= 1e5; i++)if (p[i] == i)for (int j = i * i; j <= 1e5; j += i)if (p[j] == j)p[j] = i;

	int n, q;
	cin >> n >> q;

	FOR(i, 1, n) {
		int x;
		cin >> x;
		v[i] = factorial(x);
	}

	FOR(i, 1, q) {
		cin >> qr[i].l >> qr[i].r;
		qr[i].id = i;
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		if (x.r / 260 == y.r / 260) {
			if (x.r / 260 % 2 == 0)return x.l < y.l;
			else return x.l > y.l;
		}
		return x.r < y.r;
		});

	int curR = 0, curL = 1;
	FOR(i, 1, q) {
		while (curR < qr[i].r) {
			add(++curR);
		}
		while (curR > qr[i].r) {
			add(curR--);
		}
		while (curL < qr[i].l) {
			add(curL++);
		}
		while (curL > qr[i].l) {
			add(--curL);
		}
		qr[i].res = cnt == 0;
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.id < y.id;
		});

	FOR(i, 1, q)cout << (qr[i].res ? "YES" : "NO") << '\n';
}
