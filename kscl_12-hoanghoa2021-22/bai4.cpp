#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define ull unsigned long long 

const ll mod = 1e9 + 7;

ull sum(ull n) {
	ull res = 0, turn = 1, chan = 2, le = 1;
	for (ull i = 1; 1; i *= 2) {
		ull left = i - 1, right = min(i * 2 - 1, n);
		ull cnt = right - left;
		if (turn == 1) {
			res += ((le + (cnt - 1)) * cnt) % mod;
			le += i * 2;
		}
		else {
			res += ((chan + (cnt - 1)) * cnt) % mod;
			chan += i * 2;
		}
		res %= mod;
		turn ^= 1;
		if (i * 2 - 1 >= n)break;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ull a, b;
	cin >> a >> b;
	cout << sum(b) - sum(a - 1);
}

/*
1
2 4
3 5 7 9
6 8 10 12 14 16 18 20
11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41
22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84

1
3 5 7 9
11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41
2 4
6 8 10 12 14 16 18 20
22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84
*/