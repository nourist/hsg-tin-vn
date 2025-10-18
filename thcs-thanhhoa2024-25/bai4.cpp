#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int mod = (int)1e9 + 7;

int p[(int)1e6 + 7];

int a, b;
int d[(int)1e6 + 7];

ll solve() {
	memset(d, 0, sizeof(d));
	for (int i = a; i <= b; i++) {
		int t = i;
		while(t!=1) {
			d[p[t]]++;
			t /= p[t];
		}
	}

	ll res = 1;
	for (int i = 1; i <= b; i++) {
		res *= (d[i] *2 % mod + 1);
		res %= mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	for (int i = 1; i <= 1e6; i++) {
		p[i] = i;
	}
	for(int i = 2; i*i<=1e6; i++) {
		if (p[i] == i) {
			for (int j = i*i; j <= 1e6; j+=i) {
				p[j] = i;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << solve()<<endl;
	}
}
