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
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "BOUQUET"

int l[(int)2e5 + 5];
int r[(int)2e5 + 5];
int bit[(int)2e5 + 5];
int dp[(int)2e5 + 5];

void update(int idx, int v) {
	if (idx == 0)return;
	for (idx; idx <= 2e5; idx += (idx & (-idx)))bit[idx] = max(bit[idx], v);
}

int query(int idx) {
	int res = 0;
	for (idx; idx >= 1; idx -= (idx & (-idx)))res = max(res, bit[idx]);
	return res;
}

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
	FOR(i, 1, n)cin >> l[i] >> r[i];

	priority_queue<pii, vii, greater<pii>>q;
	FOR(i, 1, n) {
		while (!q.empty() && q.top().X < i) {
			update(q.top().Y, dp[q.top().Y]);
			q.pop();
		}
		dp[i] = query(max(0, i - l[i] - 1)) + 1;
		q.push({ i + r[i], i });
	}
	cout << *max_element(dp + 1, dp + n + 1);
}
