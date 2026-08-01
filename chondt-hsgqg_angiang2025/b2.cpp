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
#define Name "b2"

int n, A, B, a[10], b[10];
const ll mod = 1e9 + 7;
ll dp[35][55][55];

int f(int idx, int carryA, int carryB) {
	if (idx == 31)return carryA == 0 && carryB == 0;

	ll& memo = dp[idx][carryA][carryB];
	if (memo != -1)return memo;

	memo = 0;

	FOR(mask, 0, (1 << n) - 1) {
		int sumA = carryA;
		int sumB = carryB;

		FOR(i, 0, n - 1) {
			if (BIT(mask, i)) {
				sumA += a[i];
				sumB += b[i];
			}
		}

		if (sumA % 2 == BIT(A, idx) && sumB % 2 == BIT(B, idx))
			memo += f(idx + 1, sumA / 2, sumB / 2);
		memo %= mod;
	}
	return memo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	memset(dp, -1, sizeof dp);

	cin >> n >> A >> B;
	FOR(i, 0, n - 1)cin >> a[i] >> b[i];

	cout << f(0, 0, 0);
}
