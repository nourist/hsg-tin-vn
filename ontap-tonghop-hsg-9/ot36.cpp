#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct gift {
	ll a, b;
} v[(int)5e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("gifts.inp", "r", stdin);
	freopen("gifts.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)cin >> v[i].a >> v[i].b;

	sort(v, v + n, [&](gift x, gift y) {
		return x.a - x.b < y.a - y.b;
		});
	ll res = 0;
	for (int i = 0; i < n / 2; i++) {
		res += v[i].b;
	}
	for (int i = n / 2; i < n; i++) {
		res += v[i].a;
	}
	cout << res;
}
