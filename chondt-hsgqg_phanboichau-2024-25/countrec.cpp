#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define FOD(i, r, l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define X first
#define Y second

int n;
int x[(int)2e5 + 5], y[(int)2e5 + 5];

void compress(int arr[]) {
  map<int, int> mp;
  FOR(i, 1, n) mp[arr[i]] = 1;

  int cnt = 1;

  for (auto it = mp.begin(); it != mp.end(); it++) {
    it->second = cnt++;
  }
}

vector<int> row[(int)2e5 + 5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  if (fopen("countrec.inp", "r")) {
    freopen("countrec.inp", "r", stdin);
    freopen("countrec.out", "w", stdout);
  }

  cin >> n;
  FOR(i, 1, n) cin >> x[i] >> y[i];

  compress(x);
  compress(y);

  int limX = *max_element(x + 1, x + n + 1);
  int limY = *max_element(y + 1, y + n + 1);

  if (limX < limY) {
    FOR(i, 1, n) swap(x[i], y[i]);
    swap(limX, limY);
  }

  FOR(i, 1, n) { row[x[i]].push_back(y[i]); }

  ll res = 0;
  unordered_map<ll, int> mp;

  FOR(i, 1, limX) sort(row[i].begin(), row[i].end());

  FOR(k, 1, limX) {
    FOR(i, 0, row[k].size() - 1) FOR(j, i + 1, row[k].size() - 1) {
      ll hs = row[k][i] * (int)(2e5 + 5) + row[k][j];

      res += mp[hs]++;
    }
  }

  cout << res;
}
