#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, a[(int)1e6+6], b[(int)1e6+6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] * i - sum;
		sum += b[i];
		cout<<b[i]<<" ";
	}
}

/*

5
1 2 2 3 3

1 3 2 6 3

*/