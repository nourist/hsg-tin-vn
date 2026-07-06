#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 5];
int n, s;
// unordered_map<int, int>freq;
int freq[(int)1e5 + 5];
int cnt = 0;

void transform() {
	map<int, int>mp;
	for (int i = 1; i <= n; i++)mp[a[i]] = 1;
	int count = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->second = count;
		count++;
	}
	for (int i = 1; i <= n; i++)a[i] = mp[a[i]];
}

void add(int x) {
	if (freq[x] == 0)cnt++;
	freq[x]++;
}

void remove(int x) {
	freq[x]--;
	if (freq[x] == 0)cnt--;
}

struct query {
	int l, r, id,v;
}v[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	cin >> n;
	s = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	transform();
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> v[i].l >> v[i].r;
		v[i].id = i;
	}

	sort(v + 1, v + q + 1, [&](query x, query y) {
		if (x.l / s != y.l / s) {
			return x.l / s < y.l / s;
		}
		return x.r < y.r;
		});

	int l = 0, r = 0;
	for (int i = 1; i <= q; i++) {
		while (l < v[i].l)remove(a[l++]);
		while (r < v[i].r)add(a[++r]);
		while (l > v[i].l)add(a[--l]);
		while (r > v[i].r)remove(a[r--]);
		v[i].v = cnt;
	}
	sort(v + 1, v + q + 1, [&](query x, query y) {
		return x.id < y.id;
		});
	for (int i = 1; i <= q; i++) {
		cout << v[i].v << '\n';
	}
}
