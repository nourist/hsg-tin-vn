#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>
#define X first 
#define Y second 

int a[(int)1e5 + 5];
int b[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("MaxofMins.inp", "r")) {
		freopen("MaxofMins.inp", "r", stdin);
		freopen("MaxofMins.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];

	multiset<pipii>st;

	ll res = 0;
	FOR(i, 1, n) {
		int cnt = 1;
		for (auto it = st.rbegin(); it != st.rend() && cnt <= 200; it++, cnt++) {
			res = max(res, min(1LL * a[i] * (it->Y.X), 1LL * b[i] * (it->Y.Y)));
		}
		st.insert({ min(a[i], b[i]), {a[i], b[i]} });
	}
	cout << res;
}
