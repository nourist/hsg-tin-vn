#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define FOD(i, r, l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define vi vector<int>

unordered_set<int> adj[(int)1e5 + 5];
int num[(int)1e5 + 5];
int low[(int)1e5 + 5];
int res[(int)1e5 + 5];

int timeDfs = 1;

void dfs(int u, int par) {
    num[u] = low[u] = timeDfs++;

    int cnt1 = 0;
    int cnt2 = 0;

    for (auto v : adj[u]) {
        if (v == par)
            continue;

        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            cnt1++;
            cnt2 += low[v] >= num[u];
        } else {
            low[u] = min(low[u], num[v]);
        }
    }

    if (par == 0)
        res[u] = cnt1;
    else
        res[u] = cnt2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen("bai3.inp", "r")) {
        freopen("bai3.inp", "r", stdin);
        freopen("bai3.out", "w", stdout);
    }

    int n, m;
    cin >> n >> m;

    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    dfs(1, 0);

    FOR(i, 1, n) cout << res[i] << ' ';
}
