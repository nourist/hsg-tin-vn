#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll unsigned long long
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

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	uint32_t f[5][5]{};
	Node() {
		// memset(f, 0, sizeof f);
	}
	Node(int x) {
		// memset(f, 0, sizeof f);
		f[x][x]++;
	}
}st[(int)2e6 + 6];

Node operator + (Node x, Node y) {
	Node res;

	FOR(i, 0, 4)FOR(j, 0, 4) {
		res.f[i][j] = (x.f[i][j] + y.f[i][j]);
	}

	FOR(i, 0, 4)FOR(j, 0, 4) {
		FOR(k, i, j - 1) {
			int h = k + 1;
			res.f[i][j] = res.f[i][j] + x.f[i][k] * y.f[h][j];
		}
	}

	return res;
}

string s;
int n, q;
int a[(int)1e6 + 6];

void build() {
	FOR(i, 1, n)st[i + n - 1] = Node(a[i]);
	FOD(i, n - 1, 1)st[i] = st[i * 2] + st[i * 2 + 1];
}

uint32_t query(int l, int r) {
	Node left, right;
	for (l += n - 1, r += n; l < r; l /= 2, r /= 2) {
		if (l & 1)left = left + st[l++];
		if (r & 1)right = st[--r] + right;
	}
	return (left + right).f[0][4];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> s >> q;
	n = s.size();
	FOR(i, 1, n) {
		if (s[i - 1] == 'D')a[i] = 0;
		if (s[i - 1] == 'I')a[i] = 1;
		if (s[i - 1] == 'S')a[i] = 2;
		if (s[i - 1] == 'C')a[i] = 3;
		if (s[i - 1] == 'O')a[i] = 4;
	}

	build();

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}