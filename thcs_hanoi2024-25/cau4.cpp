#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int mx[30008], my[30008];
int n;

int idx(int x) {
	if (x >= 1 && x <= n)return x;
	if (x > n)return x - n;
	return x + n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	int q, p, x, y;
	cin >> n >> q;
	while (q--) {
		cin >> p >> x >> y;

		int px = (p - 1) / n + 1;//hang
		int py = (p - 1) % n + 1;//cot

		py = idx(py + my[px]);
		px = idx(px + mx[py]);

		int dx = x-px;
		int dy = y-py;

		if (abs(dx) > n / 2) {
			if (dx >= 1)dx -= n;
			else dx += n;
		}
		if (abs(dy) > n / 2) {
			if (dy >= 1)dy -= n;
			else dy += n;
		}

		cout << abs(dx) + abs(dy) << endl;

		// mx[py] += dx;
		// my[idx(px + dx)] += dy;

		my[px] += dy;
		mx[idx(py + dy)] += dx;

		cerr << my[idx(px + dx)] << ' ' << mx[py] << endl;
	}
}