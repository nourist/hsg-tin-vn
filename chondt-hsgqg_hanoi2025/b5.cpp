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
#define Name "b5"

char a[(int)1e3 + 3][(int)1e3 + 3];
pii U[(int)1e3 + 3][(int)1e3 + 3];
pii D[(int)1e3 + 3][(int)1e3 + 3];
pii L[(int)1e3 + 3][(int)1e3 + 3];
pii R[(int)1e3 + 3][(int)1e3 + 3];
int dist[(int)1e3 + 3][(int)1e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j] == '1') {
			L[i][j] = L[i][j - 1];
			U[i][j] = U[i - 1][j];
		}
		else {
			L[i][j] = U[i][j] = { i, j };
		}
	}
	FOD(i, n, 1)FOD(j, m, 1) {
		if (a[i][j] == '1') {
			R[i][j] = R[i][j + 1];
			D[i][j] = D[i + 1][j];
		}
		else {
			R[i][j] = D[i][j] = { i, j };
		}
	}

	FOR(i, 1, n)FOR(j, 1, m)dist[i][j] = 1e9;
	deque<pii>q;
	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j] == '@') {
			dist[i][j] = 0;
			q.push_back({ i, j });
		}
	}

	while (!q.empty()) {
		pii u = q.front();
		q.pop_front();

		if (u.X != 1) {
			if (a[u.X - 1][u.Y] == '1') {
				pii v = U[u.X - 1][u.Y];
				if (v.X != 0 && dist[v.X][v.Y] > dist[u.X][u.Y] + 1) {
					dist[v.X][v.Y] = dist[u.X][u.Y] + 1;
					q.push_back(v);
				}
			}
			else {
				pii v = { u.X - 1, u.Y };
				if (dist[v.X][v.Y] > dist[u.X][u.Y]) {
					dist[v.X][v.Y] = dist[u.X][u.Y];
					q.push_front(v);
				}
			}
		}
		if (u.Y != 1) {
			if (a[u.X][u.Y - 1] == '1') {
				pii v = L[u.X][u.Y - 1];
				if (v.X != 0 && dist[v.X][v.Y] > dist[u.X][u.Y] + 1) {
					dist[v.X][v.Y] = dist[u.X][u.Y] + 1;
					q.push_back(v);
				}
			}
			else {
				pii v = { u.X, u.Y - 1 };
				if (dist[v.X][v.Y] > dist[u.X][u.Y]) {
					dist[v.X][v.Y] = dist[u.X][u.Y];
					q.push_front(v);
				}
			}
		}
		if (u.X != n) {
			if (a[u.X + 1][u.Y] == '1') {
				pii v = D[u.X + 1][u.Y];
				if (v.X != 0 && dist[v.X][v.Y] > dist[u.X][u.Y] + 1) {
					dist[v.X][v.Y] = dist[u.X][u.Y] + 1;
					q.push_back(v);
				}
			}
			else {
				pii v = { u.X + 1, u.Y };
				if (dist[v.X][v.Y] > dist[u.X][u.Y]) {
					dist[v.X][v.Y] = dist[u.X][u.Y];
					q.push_front(v);
				}
			}
		}
		if (u.Y != m) {
			if (a[u.X][u.Y + 1] == '1') {
				pii v = R[u.X][u.Y + 1];
				if (v.X != 0 && dist[v.X][v.Y] > dist[u.X][u.Y] + 1) {
					dist[v.X][v.Y] = dist[u.X][u.Y] + 1;
					q.push_back(v);
				}
			}
			else {
				pii v = { u.X, u.Y + 1 };
				if (dist[v.X][v.Y] > dist[u.X][u.Y]) {
					dist[v.X][v.Y] = dist[u.X][u.Y];
					q.push_front(v);
				}
			}
		}
	}
	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j] == '#') {
			cout << dist[i][j];
		}
	}
}
