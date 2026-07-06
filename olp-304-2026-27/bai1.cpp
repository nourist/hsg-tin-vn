#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

int n, a[(int)2e5 + 5];
int nx[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	set<pii>st;
	FOR(i, 1, n) {
		st.insert({ a[i], i });
		nx[i] = i + 1;
	}

	int res = 0;
	while (!st.empty()) {
		res++;
		int start = st.begin()->Y;
		int end = st.rbegin()->Y;

		if (start > end)swap(start, end);

		int idx = start;
		while (idx <= end) {
			if (st.find({ a[idx], idx }) != st.end())
				st.erase({ a[idx], idx });
			idx = nx[idx];
		}

		FOR(i, start, end) {
			nx[i] = end + 1;
		}
	}
	cout << res;
}
