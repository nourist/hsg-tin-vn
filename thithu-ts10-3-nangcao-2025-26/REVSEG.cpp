#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int n, a[(int)1e5+5], b[(int)1e5+5];

bool ok(int l, int r) {
	int u = l, v = r;
	while (r>=u&&l<=v) {
		if (a[l] != b[r])return false;
		l++;
		r--;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("REVSEG.inp", "r")) {
		freopen("REVSEG.inp", "r", stdin);
		freopen("REVSEG.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1, greater<int>());
	int l = 0, r = 0;
	FOR(i, 1, n) {
		if (a[i] != b[i]) {
			if (!l) l = i;
			r = i;
		}
	}
	if(l==0&&r==0) {
		cout << "YES" << endl;
		cout << "1 1" << endl;
		return 0;
	}
	if (ok(l, r)) {
		cout << "YES" << endl;
		cout<< l << " " << r << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

/*
6
160 155 150 152 148 140
160 155 152 150 148 140
1 2 3 5 4
5 4 3 2 1 
*/