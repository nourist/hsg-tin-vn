#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

string a[(int)1e5 + 5];
string revA[(int)1e5 + 5];
vector<string>st[(int)4e5 + 5];

vector<string>merge(vector<string>a, vector<string>b) {
	vector<string>res;
	int i = 0, j = 0;

	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			res.push_back(a[i]);
			i++;
		}
		else {
			res.push_back(b[j]);
			j++;
		}
	}
	while (i < a.size()) {
		res.push_back(a[i]);
		i++;
	}
	while (j < b.size()) {
		res.push_back(b[j]);
		j++;
	}
	return res;
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id].push_back(revA[l]);
		return;
	}

	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

int queryNode(int id, string t) {
	return upper_bound(st[id].begin(), st[id].end(), t + '}') - lower_bound(st[id].begin(), st[id].end(), t);
}

int query(int id, int l, int r, int u, int v, string t) {
	if (v<l || u>r)return 0;
	if (l >= u && r <= v) {
		return queryNode(id, t);
	}

	int mid = (l + r) / 2;
	return query(id * 2, l, mid, u, v, t) + query(id * 2 + 1, mid + 1, r, u, v, t);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("RNA.inp", "r")) {
		freopen("RNA.inp", "r", stdin);
		freopen("RNA.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1);

	FOR(i, 1, n) {
		revA[i] = a[i];
		reverse(revA[i].begin(), revA[i].end());
	}

	build(1, 1, n);

	FOR(i, 1, m) {
		string p, q;
		cin >> p >> q;
		int l = lower_bound(a + 1, a + n + 1, p) - a, r = upper_bound(a + 1, a + n + 1, p + '}') - a - 1;

		if (l > r) {
			cout << 0 << '\n';
			continue;
		}

		reverse(q.begin(), q.end());
		cout << query(1, 1, n, l, r, q) << '\n';
	}
}
