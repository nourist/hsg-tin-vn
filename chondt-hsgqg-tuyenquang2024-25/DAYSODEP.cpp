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
#define Name "daysodep"

bool p[(int)1e3 + 3];
int a[(int)5e5 + 5];
vector<int>primes;

int cnt(int n) {
	int i = 0, res = 1;
	while (i < primes.size() && primes[i] * primes[i] <= n) {
		int cnt = 0;
		while (n % primes[i] == 0) {
			cnt++;
			n /= primes[i];
		}
		res *= (cnt + 1);
		i++;
	}
	if (n != 1)res *= 2;
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

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e3; i++)if (p[i])for (int j = i * i; j <= 1e3; j += i)p[j] = 0;

	FOR(i, 1, 1e3)if (p[i])primes.push_back(i);

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)a[i] = cnt(a[i]);

	vector<int>lis;
	FOR(i, 1, n) {
		if (lis.empty() || lis.back() < a[i])lis.push_back(a[i]);
		else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
	}

	cout << lis.size();
}