#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int n, a[(int)1e6 + 6];

unordered_map<int, int>f;
int cnt = 0;

void add(int x) {
	if (f[x] == 0)cnt++;
	f[x]++;
}

void remove(int x) {
	f[x]--;
	if (f[x] == 0)cnt--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("MINSEG.inp", "r")) {
		freopen("MINSEG.inp", "r", stdin);
		freopen("MINSEG.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	unordered_set<int>s;
	FOR(i, 1, n)s.insert(a[i]);
	int required = s.size();

	int l = 1, r = 1, res = n;
	while (r <= n) {
		add(a[r]);
		while (cnt == required) {
			res = min(res, r - l + 1);
			remove(a[l]);
			l++;
		}
		r++;
	}
	cout << res;
}
