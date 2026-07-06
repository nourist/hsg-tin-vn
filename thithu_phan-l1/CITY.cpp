#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int x, y, z, n;
ll l[(int)1e5 + 5], r[(int)1e5 + 5];

struct Rect {
	int a, b, c;
}v[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("CITY.inp", "r")) {
		freopen("CITY.inp", "r", stdin);
		freopen("CITY.out", "w", stdout);
	}

	cin >> x >> y >> z;
	n = x + y + z;

	FOR(i, 1, n)cin >> v[i].a >> v[i].b >> v[i].c;

	sort(v + 1, v + n + 1, [&](Rect x, Rect y) {
		return (x.a - x.c) - (x.b - x.c) > (y.a - y.c) - (y.b - y.c);
		});

	{
		priority_queue<int, vector<int>, greater<int>>q;
		ll sum = 0;
		FOR(i, 1, x) {
			sum += v[i].a - v[i].c;
			q.push(v[i].a - v[i].c);
		}

		l[x] = sum;

		FOR(i, x + 1, n) {
			if (v[i].a - v[i].c > q.top()) {
				sum -= q.top();
				q.pop();

				sum += v[i].a - v[i].c;
				q.push(v[i].a - v[i].c);
			}
			l[i] = sum;
		}
	}

	{
		priority_queue<int, vector<int>, greater<int>>q;
		ll sum = 0;
		FOD(i, n, n - y + 1) {
			sum += v[i].b - v[i].c;
			q.push(v[i].b - v[i].c);
		}

		r[n - y + 1] = sum;

		FOD(i, n - y, 1) {
			if (v[i].b - v[i].c > q.top()) {
				sum -= q.top();
				q.pop();

				sum += v[i].b - v[i].c;
				q.push(v[i].b - v[i].c);
			}
			r[i] = sum;
		}
	}

	ll sum = 0;
	FOR(i, 1, n)sum += v[i].c;

	ll res = 0;
	FOR(i, x, n - y) {
		res = max(res, sum + l[i] + r[i + 1]);
	}
	cout << res;
}
