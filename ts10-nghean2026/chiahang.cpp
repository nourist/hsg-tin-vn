#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "CHIAHANG"

int a[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];
	sort(a + 1, a + n + 1);

	multiset<int>st;

	FOR(i, 1, n) {
		if (!st.empty()) {
			auto it = upper_bound(st.begin(), st.end(), a[i] - k);
			if (it != st.begin()) {
				it--;
				st.erase(it);
			}
		}
		st.insert(a[i]);
	}

	ll res = 0;
	for (auto i : st)res += i;
	cout << res;
}