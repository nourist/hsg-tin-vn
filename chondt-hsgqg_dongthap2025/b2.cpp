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
#define Name "b2"

struct AhoCorasick {
	int nxt[2003][2];
	int cnt[2003];
	int match_cnt[2003];
	int suffix_link[2003];
	int sz = 0;

	AhoCorasick() {
		nxt[0][0] = nxt[0][1] = -1;
	}

	int newNode() {
		sz++;
		nxt[sz][0] = nxt[sz][1] = -1;
		return sz;
	}

	void add_string(string s) {
		int p = 0;
		FOR(i, 0, s.size() - 1) {
			if (nxt[p][s[i] - '0'] == -1) {
				nxt[p][s[i] - '0'] = newNode();
			}
			p = nxt[p][s[i] - '0'];
		}
		cnt[p]++;
	}

	void build_automaton() {
		for (deque<int>q = { 0 }; !q.empty(); q.pop_front()) {
			int u = q.front();
			int sf = suffix_link[u];
			match_cnt[u] = cnt[u] + match_cnt[suffix_link[u]];
			FOR(c, 0, 1) {
				int nsf = u ? nxt[sf][c] : 0;

				if (nxt[u][c] == -1)nxt[u][c] = nsf;
				else {
					suffix_link[nxt[u][c]] = nsf;
					q.push_back(nxt[u][c]);
				}
			}
		}
	}
}aho;

int dp[202][2003];
const int mod = 111539786;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	FOR(i, 1, k) {
		string s;
		cin >> s;
		aho.add_string(s);
	}

	aho.build_automaton();

	dp[0][0] = 1;
	FOR(i, 0, n - 1)FOR(j, 0, aho.sz) {
		if (aho.match_cnt[j])continue;
		dp[i + 1][aho.nxt[j][0]] += dp[i][j];
		dp[i + 1][aho.nxt[j][0]] %= mod;
		dp[i + 1][aho.nxt[j][1]] += dp[i][j];
		dp[i + 1][aho.nxt[j][1]] %= mod;
	}
	int res = 0;
	FOR(j, 0, aho.sz) {
		if (aho.match_cnt[j])continue;
		res += dp[n][j];
		res %= mod;
	}
	cout << res;
}
