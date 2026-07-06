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
#define Name "TWINS"

bool p[(int)1e6 + 6];
int f[(int)1e6 + 6];

bool ok(int n) {
	if (!p[n])return 0;

	string a = to_string(n), b = to_string(n);
	reverse(b.begin(), b.end());

	if (a == b)return 0;
	return p[stoi(b)];
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
	for (int i = 2; i * i <= 1e6; i++)if (p[i])for (int j = i * i; j <= 1e6; j += i)p[j] = 0;

	FOR(i,1,1e6)f[i]=f[i-1]+ok(i);

	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<f[b ] - f[a-1]<<'\n';
	}
}	