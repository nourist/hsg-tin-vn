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

int n;
int a[(int)1e5 + 5];
int b[(int)1e5 + 5];
vi vA, vB;

void compress() {
	FOR(i, 1, n)vA.pb(a[i]);
	sort(all(vA));
	vA.erase(unique(all(vA)), vA.end());

	FOR(i, 1, n)vB.pb(b[i]);
	sort(all(vB));
	vB.erase(unique(all(vB)), vB.end());
}

pair<pii, pii>getRect(pii x, pii y) {
	return { {
lower_bound(all(vA), x.X) - vA.begin() + 1,
upper_bound(all(vA), x.Y) - vA.begin()
	},
{
	lower_bound(all(vB), y.X) - vB.begin() + 1,
upper_bound(all(vB), y.Y) - vB.begin()
} };
}

pii getPos(pii pos) {
	return {
		lower_bound(all(vA), pos.X) - vA.begin() + 1,
		lower_bound(all(vB), pos.Y) - vB.begin() + 1,
	};
}

int stY[(int)2.6e7 + 7];
int L[(int)2.6e7 + 7];
int R[(int)2.6e7 + 7];
int cnt = 0;

void updateY(int& id, int l, int r, int idx, int v) {
	if (!id)
		id = ++cnt;

	if (l == r) {
		stY[id] = max(stY[id], v);
		return;
	}

	int mid = l + r >> 1;
	if (idx <= mid) {
		updateY(L[id], l, mid, idx, v);
		stY[id] = max(stY[id], stY[L[id]]);
	}
	else {
		updateY(R[id], mid + 1, r, idx, v);
		stY[id] = max(stY[id], stY[R[id]]);
	}
}

int queryY(int id, int l, int r, int u, int v) {
	if (!id || r < u || l > v)return 0;

	if (u <= l && r <= v)return stY[id];

	int mid = l + r >> 1;
	return max(queryY(L[id], l, mid, u, v), queryY(R[id], mid + 1, r, u, v));
}

int stX[(int)4e5 + 5];

void update(int id, int l, int r, int x, int y, int v) {
	if (x<l || x>r)return;

	updateY(stX[id], 1, n, y, v);
	if (l == r)return;

	int mid = l + r >> 1;
	update(id * 2, l, mid, x, y, v);
	update(id * 2 + 1, mid + 1, r, x, y, v);
}

int query(int id, int l, int r, int x, int y, int u, int v) {
	if (y<l || x>r)return 0;

	if (x <= l && r <= y) {
		return queryY(stX[id], 1, n, u, v);
	}

	int mid = l + r >> 1;
	return max({
		query(id * 2,l,mid,x,y,u,v),
		query(id * 2 + 1,mid + 1,r,x,y,u,v)
		});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int d;
	cin >> n >> d;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];

	compress();

	FOR(i, 1, n) {
		auto pos = getPos({ a[i], b[i] });
		auto rect = getRect({ a[i] - d, a[i] + d }, { b[i] - d, b[i] + d });
		update(1, 1, n, pos.X, pos.Y, query(1, 1, n, rect.X.X, rect.X.Y, rect.Y.X, rect.Y.Y) + 1);
	}
	cout << query(1, 1, n, 1, n, 1, n);
}

/*
d + aj >= ai >= aj - d
d + bj >= bi >= bj - d
*/
