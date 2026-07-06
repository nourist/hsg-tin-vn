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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "CHIABA"

int a[(int)1e6 + 6];
int l[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	if (accumulate(a + 1, a + n + 1, 0LL) % 3 != 0) {
		cout << 0;
		return 0;
	}

	ll sum = 0;
	FOR(i, 1, n) {
		sum += a[i];
		l[i] = l[i - 1];
		if (sum % 3 == 0) {
			l[i]++;
		}
	}

	sum = 0;
	ll res = 0;
	FOD(i, n, 1) {
		sum += a[i];

		if (sum % 3 == 2)res += l[i - 1];
	}
	cout << res;
}