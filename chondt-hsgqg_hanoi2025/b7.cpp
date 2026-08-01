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
#define Name "b7"

pii a[(int)2e5 + 5];

struct Query {
	int id, a, b, res;
}qr[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n;
	FOR(i, 1, n)cin >> a[i].X >> a[i].Y;
	cin >> q;
	FOR(i, 1, q) {
		cin >> qr[i].a >> qr[i].b;
		qr[i].id = i;
	}

	sort(a + 1, a + n + 1, [&](pii x, pii y) {
		if (x.Y == y.Y)return x.X > y.X;
		return x.Y < y.Y;
		});
	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.b < y.b;
		});

	vi lis;
	int cur = 0;
	FOR(i, 1, q) {
		while (cur + 1 <= n && a[cur + 1].Y <= qr[i].b) {
			cur++;
			if (lis.empty() || lis.back() >= a[cur].X) {
				lis.push_back(a[cur].X);
			}
			else {
				*upper_bound(all(lis), a[cur].X, greater<int>()) = a[cur].X;
			}
		}
		qr[i].res = upper_bound(all(lis), qr[i].a, greater<int>()) - lis.begin();
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.id < y.id;
		});
	FOR(i, 1, q)cout << qr[i].res << endl;
}
