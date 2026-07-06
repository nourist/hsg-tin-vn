#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("danhtu.inp", "r")) {
		freopen("danhtu.inp", "r", stdin);
		freopen("danhtu.out", "w", stdout);
	}

	string s;
	int cnt1 = 0, cnt2 = 0;
	while (cin >> s) {
		if (s[0] >= '2' && s[0] <= '9') {
			if (s.back() == 's' || s.back() == 'x' || s.back() == 'z' || s.back() == 'y' || (s.size() >= 2 && s[s.size() - 2] == 'c' && s.back() == 'h') || (s.size() >= 2 && s[s.size() - 2] == 's' && s.back() == 'h')) {
				cnt1++;
			}
			cnt2++;
		}
	}
	cout << cnt1 << ' ' << cnt2;
}
