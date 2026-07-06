#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 10];
ll d[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)d[i] = d[i - 1] + a[i];

	int da, ma, ya, db, dm, dy;
	while (q--) {
		cin >> da >> ma >> ya >> db >> dm >> dy;

		ll daya = ya * d[n] + d[ma - 1] + da;
		ll dayb = dy * d[n] + d[dm - 1] + db;
		cout << dayb - daya + 1<<endl;
	}

}
