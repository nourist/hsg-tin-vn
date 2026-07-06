#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2_songuyentobithieu.inp", "r")) {
		freopen("bai2_songuyentobithieu.inp", "r", stdin);
		freopen("bai2_songuyentobithieu.out", "w", stdout);
	}

	memset(p, true, sizeof(p));
	p[0] = p[1] = false;
	for(int i = 2; i * i <= (int)1e6; ++i) {
		if (p[i]) {
			for (int j = i * i; j <= (int)1e6; j += i) {
				p[j] = false;
			}
		}
	}

	int n;
	cin >> n;
	int x;
	while (n--) {
		cin >> x;
		p[x] = 0;
	}
	FOR(i,2,1e6) {
		if (p[i]) {
			cout << i << " ";
			return 0;
		}
	}
	cout << "No prime number missing!" << endl;
}
