#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define FOD(i, r, l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define X first
#define Y second

int a[2004][2004];

pii maxPair(pii x, int u) {
  if (u <= x.X) {
    x.Y = x.X;
    x.X = u;
  } else if (u <= x.Y) {
    x.Y = u;
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  if (fopen("minmaxrec.inp", "r")) {
    freopen("minmaxrec.inp", "r", stdin);
    freopen("minmaxrec.out", "w", stdout);
  }

  int n, m;
  cin >> n >> m;

  if (n > m)
    swap(n, m);

  FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

  int res = 1e9;

  FOR(i, 1, n) FOR(j, i + 1, n) {
    pii tmp = {1e9, 1e9};
    FOR(k, 1, m) { tmp = maxPair(tmp, max(a[i][k], a[j][k])); }
    res = min(res, max(tmp.X, tmp.Y));
  }
  cout << res;
}
