#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
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
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b4"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n;
	cin >> n;

	ll res = 0;
	while (n != 0) {
		string s = to_string(n);
		int mx = *max_element(all(s));
		FOR(i, 0, s.size() - 1) {
			if (s[i] == mx) {
				ll prefix = stoll(s.substr(0, i + 1));
				ll suffix = stoll(i == s.size() - 1 ? "0" : s.substr(i + 1, s.size() - i - 1));

				// cout << prefix << ' ' << suffix << endl;

				res += suffix / (mx - '0') + 1;
				suffix %= (mx - '0');
				if (s.size() - i - 1 == 0) {
					prefix -= (mx - '0');
					n = prefix;
				}
				else {
					suffix = stoll("1" + string(s.size() - i - 1, '0')) - (mx - '0' - suffix);
					prefix--;
					n = prefix * stoll("1" + string(s.size() - i - 1, '0')) + suffix;
				}
				break;
			}
		}
	}
	cout << res;
}
