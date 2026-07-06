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
#define LOWEST_BIT(x) (__builtin_ctzll(x))
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))

struct thLargest {
	int v[3];

	thLargest() {
		v[0] = v[1] = v[2] = -1e9;
	}

	int operator [] (int i) {
		return v[i];
	}

	const int operator [] (int i) const {
		return v[i];
	}

	void operator += (int x) {
		if (x >= v[0]) {
			v[2] = v[1];
			v[1] = v[0];
			v[0] = x;
		}
		else if (x >= v[1]) {
			v[2] = v[1];
			v[1] = x;
		}
		else if (x >= v[2]) {
			v[2] = x;
		}
	}
};

struct Node {
	thLargest big, small;

	Node() {}

	Node(int x) {
		big += x;
		small += (-x);
	}
};

Node operator + (const Node& a, const Node& b) {
	Node res;
	res.big += a.big[0];
	res.big += a.big[1];
	res.big += a.big[2];
	res.small += a.small[0];
	res.small += a.small[1];
	res.small += a.small[2];
	res.big += b.big[0];
	res.big += b.big[1];
	res.big += b.big[2];
	res.small += b.small[0];
	res.small += b.small[1];
	res.small += b.small[2];

	return res;
}

int a[(int)3e5 + 5];
Node st[(int)12e5 + 5];

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = Node(a[l]);
		return;
	}

	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

Node query(int id, int l, int r, int u, int v) {
	if (v<l || u>r)return Node();

	if (l >= u && r <= v)return st[id];

	int mid = l + r >> 1;
	return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];

	build(1, 1, n);

	while (q--) {
		int l, r;
		cin >> l >> r;
		Node t = query(1, 1, n, l, r);

		cout << max(1LL * t.big[0] * t.big[1] * t.big[2], 1LL * t.big[0] * t.small[0] * t.small[1]) << endl;
	}
}