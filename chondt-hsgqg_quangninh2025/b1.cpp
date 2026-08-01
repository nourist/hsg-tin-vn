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

ll n, k;
ll a[40];

ll sumMask(int mask, vl& arr) {
	ll res = 0;
	FOR(i, 0, arr.size() - 1) {
		if (BIT(mask, i))
			res += arr[i];
	}
	return res;
}

ll solveHalf(vl& arr) {
	ll res = 0;
	FOR(mask, 1, (1 << arr.size()) - 1) {
		ll sum = sumMask(mask, arr);

		if (sum <= n / 2)continue;

		bool ok = 1;
		FOR(i, 0, arr.size() - 1) {
			if (BIT(mask, i) && sum - arr[i] > n / 2)ok = 0;
		}
		res += ok;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, k)cin >> a[i];

	sort(a + 1, a + k + 1);

	vl L, R;
	FOR(i, 1, k / 2)L.pb(a[i]);
	FOR(i, k / 2 + 1, k)R.pb(a[i]);

	ll res = solveHalf(L) + solveHalf(R);

	vl v;
	FOR(i, 1, (1 << R.size()) - 1) {
		v.push_back(sumMask(i, R));
	}

	sort(all(v));

	FOR(i, 1, (1 << L.size()) - 1) {
		ll sum = sumMask(i, L);
		ll minMember = L[LOWEST_BIT(i)];

		// cout << upper_bound(all(v), n / 2 - sum + minMember) - lower_bound(all(v), n / 2 - sum) << endl;
		res += upper_bound(all(v), n / 2 - sum + minMember) - upper_bound(all(v), n / 2 - sum);
	}

	cout << res;
}

/*
setL + setR > n/2
setR > n/2 - setL
n/2 - setL < setR <= n/2 - setL + minMember
setL - minMember + setR  <= n/2
*/
