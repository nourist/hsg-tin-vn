#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,b,a) for(int i = b; i >= a; i--)
#define A first
#define B second
#define Name ""
int n, d[10], x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> x, d[x]++;
	int res = d[4];
	res += (d[2] + 1) / 2;
	if (d[2] % 2 == 1) {
		d[1] -= min(d[1], 2);
	}

	if (d[1] > d[3]) {
		res += d[3];
		res += (d[1] - d[3] + 3) / 4;
	}
	else {
		res += d[3];
	}
	cout << res;
}
