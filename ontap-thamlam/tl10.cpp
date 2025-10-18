#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

pair<int, int> v[(int)5e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, n;
	cin >> s >> n;

	FOR(i, 1, n)cin >> v[i].first >> v[i].second;

	sort(v + 1, v + n + 1);

	FOR(i, 1, n) {
		if (s > v[i].first)s += v[i].second;
		else {
			cout << "NO" << endl;
			cout << n - i + 1;
			return 0;
		}
	}
	cout << "YES" << endl;
}
