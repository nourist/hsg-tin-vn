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
#define Name "photo"

int n, k;
int a[(int)1e6 + 6];
int f[(int)1e6 + 6];
int cnt = 0;

void add(int x) {
	if (f[x] == 0)cnt++;
	f[x]++;
}

void rem(int x) {
	if (f[x] == 1)cnt--;
	f[x]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, k)add(a[i]);

	int res = cnt;
	FOR(i, k + 1, n) {
		add(a[i]);
		rem(a[i - k]);

		res = max(res, cnt);
	}
	cout << res;
}