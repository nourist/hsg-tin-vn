#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

pii s, t;
int n;
pii a[(int)1e5 + 5];

void compressX() {
	map<int, int>mp;

	FOR(i, 1, n)mp[a[i].X] = 1;
	mp[s.X] = 1;
	mp[t.X] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->second = cnt++;

	FOR(i, 1, n)a[i].X = mp[a[i].X];
	s.X = mp[s.X];
	t.X = mp[t.X];
}

void compressY() {
	map<int, int>mp;

	FOR(i, 1, n)mp[a[i].Y] = 1;
	mp[s.Y] = 1;
	mp[t.Y] = 1;

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->second = cnt++;

	FOR(i, 1, n)a[i].Y = mp[a[i].Y];
	s.Y = mp[s.Y];
	t.Y = mp[t.Y];
}

void swapX() {
	FOR(i, 1, n)a[i].X = n - a[i].X + 3;
	s.X = n - s.X + 3;
	t.X = n - t.X + 3;
}

void swapY() {
	FOR(i, 1, n)a[i].Y = n - a[i].Y + 3;
	s.Y = n - s.Y + 3;
	t.Y = n - t.Y + 3;
}

void swapXY() {
	FOR(i, 1, n)swap(a[i].Y, a[i].X);
	swap(s.Y, s.X);
	swap(t.Y, t.X);
}

void getInside() {
	vector<pii>res;
	FOR(i, 1, n) {
		if (a[i].X >= s.X && a[i].X <= t.X && a[i].Y >= s.Y && a[i].Y <= t.Y) {
			res.push_back(a[i]);
		}
	}
	n = res.size();
	FOR(i, 1, n)a[i] = res[i - 1];
}

struct BIT {
	int bit[(int)2e5 + 5];

	void update(int idx, int v) {
		for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx))) res = max(res, bit[idx]);
		return res;
	}
}bit;

int dp[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("path.inp", "r")) {
		freopen("path.inp", "r", stdin);
		freopen("path.out", "w", stdout);
	}

	cin >> s.X >> s.Y >> t.X >> t.Y >> n;

	FOR(i, 1, n)cin >> a[i].X >> a[i].Y;

	compressX();
	compressY();

	if (s.X > t.X)swapX();
	if (s.Y > t.Y)swapY();

	if (t.Y - s.Y > t.X - s.X)swapXY();

	getInside();

	sort(a + 1, a + n + 1, [&](pii a, pii b) {
		if (a.Y == b.Y) {
			return a.X < b.X;
		}
		return a.Y < b.Y;
		});

	a[0] = s;
	a[n + 1] = t;

	dp[0] = 1;

	FOR(i, 1, n + 1) {
		FOR(j, 0, i - 1) {
			if ()
		}
	}
}

/*
d(s) + c(s, t) = d(t)

c(s, t) = max(t.x-s.x, t.y-s.y)

*/
