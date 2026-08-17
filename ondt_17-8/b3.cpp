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

int n, q;
int a[(int)5e5 + 5];
int res = 0;

namespace Trie {
	int child[(int)9e6 + 6][2];
	int cnt[(int)9e6 + 6];

	int mx = 0;
	void build(int id, int depth) {
		if (depth == 19)return;
		child[id][0] = id * 2;
		child[id][1] = id * 2 + 1;
		build(id * 2, depth + 1);
		build(id * 2 + 1, depth + 1);
	}

	void add(int id, int val, int depth, int delta) {
		cnt[id] += delta;
		if (depth == 19)return;
		add(child[id][BIT(val, depth)], val, depth + 1, delta);
	}

	void dfs(int id, int depth) {
		if (depth == 19)return;
		if (cnt[id] % 2)res ^= (1 << depth);
		dfs(child[id][0], depth + 1);
		swap(child[id][0], child[id][1]);
	}

	int get_zeros(int id, int depth) {
		if (depth == 19) return cnt[id];
		return get_zeros(child[id][0], depth + 1);
	}
}

int last_D[(int)5e5 + 5];
int D = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> q;
	Trie::build(1, -1);

	FOR(i, 1, n)Trie::add(1, 0, 0, 1);

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			int v = max(0, a[x] - D + last_D[x]);
			Trie::add(1, v, 0, -1);
			res ^= v;
			v++;
			res ^= v;
			a[x] = v;
			last_D[x] = D;
			Trie::add(1, v, 0, 1);
			cout << res << endl;
		}
		else {
			int zeros = Trie::get_zeros(1, 0);
			if (zeros > 0) Trie::add(1, 0, 0, -zeros);
			Trie::dfs(1, 0);
			if (zeros > 0) Trie::add(1, 0, 0, zeros);
			D++;
			cout << res << endl;
		}
	}
}
