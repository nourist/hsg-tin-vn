#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)cin >> a[i];

	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if ((ld)d / a[i] + i < (ld)d / a[j] + j)res++;
		}
	}
	cout << res;
}

