#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define V first
#define ID second

pair<int, int>a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("LAMDEP.inp", "r")) {
		freopen("LAMDEP.inp", "r", stdin);
		freopen("LAMDEP.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i].V;
	FOR(i, 1, n)a[i].ID = i;

	sort(a + 1, a + n + 1);

	int res = 1e9, pos = 0;
	FOR(i, 4, n) {
		if (a[i].V - a[i - 3].V <= res) {
			res = a[i].V - a[i - 3].V;
			pos = i;
		}
	}
	vector<int>v;
	FOR(i, pos - 3, pos) {
		v.push_back(a[i].ID);
	}
	sort(v.begin(), v.end());
	cout << res << endl;
	for (int i : v)cout << i << ' ';
}
