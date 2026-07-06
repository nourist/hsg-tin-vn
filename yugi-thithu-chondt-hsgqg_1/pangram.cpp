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
#define Name "pangram"

int a[30];
int f[(1 << 25) + 25];

int getKeyMask(string s) {
	int mask = 0;
	for (auto i : s) {
		mask = TURNON(mask, i - 'a');
	}
	return mask;
}

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

	FOR(i, 0, n - 1) {
		string s;
		cin >> s;
		a[i] = getKeyMask(s);
	}

	FOR(mask, 0, (1 << n) - 1) {
		FOR(i, 0, n - 1) {
			if (BIT(mask, i))continue;

			int newMask = TURNON(mask, i);
			f[newMask] = f[mask] | a[i];
		}
	}

	int res = 0;
	FOR(mask, 0, (1 << n) - 1) {
		if (f[mask] == ((1 << 26) - 1)) {
			res++;
		}
	}
	cout << res;
}
