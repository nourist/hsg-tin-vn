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
#define Name "bai4"

vi groups[3]{
	{
		0, 3, 6, 9
	},
	{
		1, 4, 7
	},
	{
		2, 5, 8
	}
};

ll dp1[(int)1e4 + 4][20][2][2];
ll dp2[(int)1e4 + 4][20][2][2];

const ll mod = 1e9 + 7;

string s;

ll f1(int idx, bool smaller, int sum, bool use0, bool started) {
	if (idx == -1)return sum == 0;

	auto& memo = dp1[idx][sum][use0][started];
	if (smaller && memo != -1)return memo;

	ll res = 0;
	int limit = smaller ? 9 : s[idx] - '0';

	for (auto i : groups[1])if (i <= limit)
		res += f1(idx - 1, smaller || (i < limit), (sum * 10 + i) % 19, use0, 1);

	if (!use0)
		for (auto i : groups[0])if (i <= limit)
			res += f1(idx - 1, smaller || (i < limit), (sum * 10 + i) % 19, (!started && i != 0) || started, started || (i != 0));

	res %= mod;

	if (smaller)memo = res;
	return res;
}

ll f2(int idx, bool smaller, int sum, bool use0, bool started) {
	if (idx == -1)return sum == 0;

	auto& memo = dp2[idx][sum][use0][started];
	if (smaller && memo != -1)return memo;

	ll res = 0;
	int limit = smaller ? 9 : s[idx] - '0';

	for (auto i : groups[2])if (i <= limit)
		res += f2(idx - 1, smaller || (i < limit), (sum * 10 + i) % 19, use0, 1);

	if (!use0)
		for (auto i : groups[0])if (i <= limit)
			res += f2(idx - 1, smaller || (i < limit), (sum * 10 + i) % 19, (!started && i != 0) || started, started || (i != 0));

	res %= mod;

	if (smaller)memo = res;
	return res;
}


ll solve(string n) {
	s = n;
	reverse(s.begin(), s.end());

	return (f1((int)s.size() - 1, 0, 0, 0, 0) + f2((int)s.size() - 1, 0, 0, 0, 0)) % mod;
}

string stringMinus1(string n) {
	FOD(i, n.size() - 1, 0) {
		if (n[i] == '0')n[i] = '9';
		else {
			n[i]--;
			break;
		}
	}

	if (n[0] == '0' && n.size() > 1) n.erase(n.begin());

	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);

	int t;
	string l, r;

	cin >> t;
	while (t--) {
		cin >> l >> r;
		cout << (solve(r) - solve(stringMinus1(l)) + mod) % mod << '\n';
	}
}