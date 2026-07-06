#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "bai5"

unordered_map<int, int>dist;

namespace buildGraph {
	vi createEdges(int u) {
		string cur = to_string(u);
		if (cur.size() == 8)cur = "0" + cur;

		pii pos;
		FOR(i, 0, 2)FOR(j, 0, 2) {
			if (cur[i * 3 + j] == '0') {
				pos = { i, j };
			}
		}

		vi res;

		if (pos.X != 0) {
			swap(cur[pos.X * 3 + pos.Y], cur[(pos.X - 1) * 3 + pos.Y]);
			res.push_back(stoll(cur));
			swap(cur[pos.X * 3 + pos.Y], cur[(pos.X - 1) * 3 + pos.Y]);
		}
		if (pos.X != 2) {
			swap(cur[pos.X * 3 + pos.Y], cur[(pos.X + 1) * 3 + pos.Y]);
			res.push_back(stoll(cur));
			swap(cur[pos.X * 3 + pos.Y], cur[(pos.X + 1) * 3 + pos.Y]);
		}
		if (pos.Y != 0) {
			swap(cur[pos.X * 3 + pos.Y], cur[pos.X * 3 + pos.Y - 1]);
			res.push_back(stoll(cur));
			swap(cur[pos.X * 3 + pos.Y], cur[pos.X * 3 + pos.Y - 1]);
		}
		if (pos.Y != 2) {
			swap(cur[pos.X * 3 + pos.Y], cur[pos.X * 3 + pos.Y + 1]);
			res.push_back(stoll(cur));
			swap(cur[pos.X * 3 + pos.Y], cur[pos.X * 3 + pos.Y + 1]);
		}

		return res;
	}

	void bfs() {
		int s = 0;
		FOR(i, 0, 8)s = s * 10 + i;

		deque<int>q;
		q.push_back(s);

		dist[s] = 1;

		while (!q.empty()) {
			int u = q.front();
			q.pop_front();

			for (int v : createEdges(u)) {
				if (dist[v] == 0) {
					dist[v] = dist[u] + 1;
					q.push_back(v);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	buildGraph::bfs();

	int t;

	cin >> t;
	while (t--) {
		ll num = 0;
		FOR(i, 0, 8) {
			int x;
			cin >> x;
			num = num * 10 + x;
		}

		cout << dist[num] - 1 << '\n';
	}
}