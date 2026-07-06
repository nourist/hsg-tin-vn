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

ll n, k;
ll a[(int)1e5 + 5];
int l[(int)1e5 + 5];
int r[(int)1e5 + 5];

void calcLR() {
	stack<int>st;
	FOR(i, 1, n) {
		while (!st.empty() && a[i] < a[st.top()]) {
			r[st.top()] = i - 1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		r[st.top()] = n;
		st.pop();
	}
	FOD(i, n, 1) {
		while (!st.empty() && a[i] <= a[st.top()]) {
			l[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		l[st.top()] = 1;
		st.pop();
	}
}

struct Query {
	ll i, l, r, delta, h;
};

vector<Query>L, R;

struct FENWICK {
	int bit[(int)3e5 + 5];

	void update(int idx) {
		if (idx == 0)return;
		for (idx; idx <= 3e5; idx += (idx & (-idx)))bit[idx]++;
	}

	int query(int idx) {
		int res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}
}bit;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	calcLR();

	FOR(i, 1, n) {
		if ((r[i] - i + 1) < (i - l[i] + 1)) {
			L.pb({ i, i, r[i], 1, k - a[i] });
			L.pb({ l[i] - 1, i, r[i], -1, k - a[i] });
		}
		else {
			R.pb({ r[i] + 1,l[i], i,-1, k - a[i] });
			R.pb({ i,l[i], i,1, k - a[i] });
		}
	}

	sort(all(L), [&](Query x, Query y) {
		return x.i < y.i;
		});

	ll res = 0;

	vector<ll>v;
	FOR(i, 1, n)v.pb(a[i]);
	FOR(i, 1, n)v.pb(-a[i]);
	sort(all(v));
	v.erase(unique(all(v)), v.end());

	int cur = 0;
	FOR(i, 0, (int)L.size() - 1) {
		while (cur + 1 <= L[i].i) {
			cur++;
			bit.update(upper_bound(all(v), a[cur]) - v.begin() + 1);
		}

		FOR(j, L[i].l, L[i].r) {
			res += L[i].delta * bit.query(upper_bound(all(v), L[i].h + a[j]) - v.begin() + 1);
		}
	}

	sort(all(R), [&](Query x, Query y) {
		return x.i < y.i;
		});

	bit = FENWICK();

	cur = n + 1;
	FOD(i, (int)R.size() - 1, 0) {
		while (cur - 1 >= R[i].i) {
			cur--;
			bit.update(upper_bound(all(v), -a[cur]) - v.begin() + 1);
		}

		FOR(j, R[i].l, R[i].r) {
			res += R[i].delta * bit.query(upper_bound(all(v), R[i].h - a[j]) - v.begin() + 1);
		}
	}
	cout << res;
}

/*
a[i] - a[j]<=h
a[i]<=h + a[j]
-a[j]<=-a[i]+h
*/