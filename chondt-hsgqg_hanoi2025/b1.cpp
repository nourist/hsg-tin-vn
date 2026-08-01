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
#define Name "b1"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	string s;
	getline(cin, s);

	if (s.size() < 9) { cout << s.size() + 1; return 0; }

	FOR(i, 1, s.size()) {
		if (i <= 2 && !(s[i - 1] >= 'A' && s[i - 1] <= 'Z')) {
			cout << i;
			return 0;
		}
		else if (i == 3 && s[i - 1] != '-') {
			cout << i;
			return 0;
		}
		else if (i >= 4 && i <= 6 && !(s[i - 1] >= '0' && s[i - 1] <= '9')) {
			cout << i;
			return 0;
		}
		else if (i == 7 && s[i - 1] != '.') {
			cout << i;
			return 0;
		}
		else if (i >= 8 && i <= 9 && !(s[i - 1] >= '0' && s[i - 1] <= '9')) {
			cout << i;
			return 0;
		}
		else if (i >= 10) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}
