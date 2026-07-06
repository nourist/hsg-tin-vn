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
#define Name "tbc"

int a[1005];

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

	map<int, int>mp;
	map<int, bool>ok;
	FOR(i, 1, n)mp[a[i]]++;

	FOR(i, 1, n) {
		FOR(j, i + 1, n) {
			if (a[i] == a[j]) {
				ok[a[i]] = 1;
			}
			else if ((a[i] + a[j]) % 2 == 0) {
				ok[(a[i] + a[j]) / 2] = 1;
			}
		}
	}

	int res = 0;
	for (auto it : mp) {
		if (ok[it.X])res += it.Y;
	}

	cout << res;
}