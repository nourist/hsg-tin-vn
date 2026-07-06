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
#define Name "BAI4"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, q;
	cin >> q;

	while (q--) {
		cin >> n;
		signed ll res = n + 1;

		for (signed ll l = 1; l <= n;) {
			signed ll q = n / l;
			signed ll r = n / q;

			res += q * (n + 1) * (r - l + 1) - (r - l + 1) * (r + l) / 2 * (q * (q + 1) / 2);

			l = r + 1;
		}

		string s = "";
		while (res != 0) {
			s += (res % 10 + '0');
			res /= 10;
		}

		reverse(s.begin(), s.end());

		cout << s << '\n';
	}
}

/*
tinh dua tren d
l: 0 -> n/d
n + 1 - l*d

q * (n+1) - d (q*(q+1)/2)

*/
