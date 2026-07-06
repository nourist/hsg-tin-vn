#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "bai2"

ll a[(int)1e3 + 3];
#define lcm(a,b) (a/__gcd(a,b)*b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n)cin >> a[i];

	int res = 0;
	FOR(i, 1, n)FOR(j, i + 1, n) {
		if (lcm(a[i], a[j]) % __gcd(a[i], a[j]) == 0 && sqrt(lcm(a[i], a[j]) / __gcd(a[i], a[j])) == (ll)sqrt(lcm(a[i], a[j]) / __gcd(a[i], a[j])))res++;
	}
	cout << res;
}