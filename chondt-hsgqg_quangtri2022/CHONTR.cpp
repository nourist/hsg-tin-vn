#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "CHONTR"

int a[(int)2e6 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, p, q, r;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> p >> q >> r;

	int L = 0, R = 0;
	FOR(i, 2, n)R += (a[i] == r);

	ll res = 0;
	FOR(i, 2, n - 1) {
		R -= a[i] == r;
		L += a[i - 1] == p;

		if (a[i] == q)res += 1LL * R * L;
	}
	cout << res;
}
