#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll n, a[(int)1e5 + 5], f[(int)1e5 + 5], l[(int)1e5 + 5], r[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("MAXZONE.inp", "r")) {
		freopen("MAXZONE.inp", "r", stdin);
		freopen("MAXZONE.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	stack<int>s;
	FOR(i, 1, n) {
		while (!s.empty() && a[s.top()] < a[i]) {
			r[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) {
		r[s.top()] = n + 1;
		s.pop();
	}
	FOD(i, n, 1) {
		while (!s.empty() && a[s.top()] < a[i]) {
			l[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	FOR(i, 1, n) {
		cout << f[r[i] - 1] - f[l[i]] << ' ';
	}
}
