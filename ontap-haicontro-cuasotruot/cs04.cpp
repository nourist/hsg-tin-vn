#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 8];
int d[(int)1e6 + 8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll l = 0, r = 0;
	for (r; r + 1 < k; r++) {
		d[a[r]]++;
	}
	for (r; r < n; r++) {
		d[a[r]]++;
		if (d[a[r]] > 1) {
			cout << "YES";
			return 0;
		}
		d[a[l]]--;
		l++;
	}
	cout << "NO";
}
//=)) 
//AC plzz
