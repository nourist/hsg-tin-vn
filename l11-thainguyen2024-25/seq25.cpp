#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct query {
	int v, id, res;
}qr[(int)1e5 + 5];
int n, q, a[(int)1e5 + 5];
int l[(int)1e5 + 5], r[(int)1e5 + 5], maxRange[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("seq25.inp", "r")) {
		freopen("seq25.inp", "r", stdin);
		freopen("seq25.out", "w", stdout);
	}

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> qr[i].v;
		qr[i].id = i;
	}
	qr[0].v = 1e9;
	sort(qr + 1, qr + q + 1, [&](query x, query y) {
		return x.v > y.v;
		});

	stack<int>st;

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && a[st.top()] >= a[i])
			st.pop();
		if(!st.empty())
			l[i] = st.top();
		st.push(i);
	}

	while (!st.empty())st.pop();

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && a[st.top()] >= a[i])
			st.pop();
		if (!st.empty())
			r[i] = st.top();
		else
			r[i] = n + 1;
		st.push(i);
	}

	for (int i = 1; i <= n; i++) {
		maxRange[i] = r[i] - l[i] - 1;
	}

	map<int, int>mp;
	for (int i = 1; i <= n; i++) {
		mp[a[i]] = max(mp[a[i]], maxRange[i]);
	}

	int res = 0;
	for (int i = 1; i <= q; i++) {
		for (auto it = mp.lower_bound(qr[i].v); it != mp.lower_bound(qr[i - 1].v); it++) {
			res = max(res, it->second);
		}
		qr[i].res = res;
	}
	sort(qr + 1, qr + q + 1, [&](query x, query y) {
		return x.id < y.id;
		});

	for (int i = 1; i <= q; i++) {
		cout << qr[i].res << '\n';
	}
}
