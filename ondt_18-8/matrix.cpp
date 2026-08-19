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
#define Name "matrix"

int tr[10];
int dl[10];
int a[10][10];
int t[10][10];
int d[10][10];
int l[10][10];
int r[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> tr[i];
	FOR(i, 1, n)cin >> dl[i];

	FOR(mask, 0, (1 << (n * (n - 1))) - 1) {
		int cnt = 0;
		FOR(i, 1, n)FOR(j, 1, n) {
			if (i == j)continue;
			a[i][j] = BIT(mask, cnt++);
		}
		FOR(i, 1, n)FOR(j, 1, n) {
			t[i][j] = t[i - 1][j] + a[i][j];
			l[i][j] = l[i][j - 1] + a[i][j];
		}
		FOD(i, n, 1)FOD(j, n, 1) {
			d[i][j] = d[i + 1][j] + a[i][j];
			r[i][j] = r[i][j + 1] + a[i][j];
		}
		int ok = 0;
		FOR(i, 1, n) {
			ok += (t[i][i] + r[i][i] == tr[i] && d[i][i] + l[i][i] == dl[i]);
		}
		if (ok == n) {
			cout << "YES" << endl;
			FOR(i, 1, n)FOR(j, 1, n)cout << a[i][j] << " \n"[j == n];
			return 0;
		}
	}
	cout << "NO";
}
