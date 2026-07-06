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

	if (fopen("p2.inp", "r")) {
		freopen("p2.inp", "r", stdin);
		freopen("p2.out", "w", stdout);
	}

	int n, k;
	string s;
	cin >> n >> k >> s;

	s = "_" + s;

	FOR(i, 1, n - 1) {
		if (s[i] == '4' && s[i + 1] == '7') {
			if (i != 1 && s[i - 1] == '4' && i % 2 == 0) {//447
				if (k % 2 == 1) {
					s[i] = '7';
					break;
				}
			}
			else if (i != n - 1 && s[i + 2] == '7' && i % 2 == 1) {//477
				if (k % 2 == 1) {
					s[i + 1] = '4';
					break;
				}
			}
			else {
				if (i % 2 == 0) {
					s[i] = '7';
				}
				else {
					s[i + 1] = '4';
				}
				k--;
			}
		}
		if (k == 0)break;
	}

	s.erase(s.begin());

	cout << s;
}

/*
477

lẻ: 447 -> 477
chẵn: 777

474

lẻ: 444
chẵn: 774

447

lẻ: 444
chẵn: 477 -> 447

747

lẻ: 744
chẵn: 777

*/