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
#define Name "b3"

int a[(int)1e5 + 5];
int b[(int)1e5 + 5];
int id[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, x, y, z;
	cin >> n >> x >> y >> z;

	FOR(i, 1, n)cin >> a[i] >> b[i];

	FOR(i, 1, n)id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) {
		return a[x] - b[x] > a[y] - b[y];
		});

	ll res = 0;
	set<pii>st;
	FOR(idx, 1, n) {
		int i = id[idx];
		if (a[i] == b[i])continue;

		if (a[i] > b[i]) {
			res += (a[i] - b[i]) * y;
			st.insert({ i, a[i] - b[i] });
		}
		else {
			while (!st.empty()) {
				auto it = st.lower_bound({ i, -1 });

				if (it == st.end()) {
					--it;
				}
				else if (it != st.begin()) {
					auto prv = prev(it);

					if (abs(prv->X - i) <= abs(it->X - i))
						it = prv;
				}

				int pos = it->X;
				int val = it->Y;

				if ((i - pos) * z - y >= x)
					break;

				int need = b[i] - a[i];
				int cost = abs(i - pos) * z - y;

				if (val <= need) {
					res += 1LL * cost * val;
					a[i] += val;
					st.erase(it);
				}
				else {
					res += 1LL * cost * need;

					st.erase(it);
					st.insert({ pos, val - need });

					a[i] = b[i];
					break;
				}
			}

			res += 1LL * (b[i] - a[i]) * x;
		}
	}
	cout << res;
}
