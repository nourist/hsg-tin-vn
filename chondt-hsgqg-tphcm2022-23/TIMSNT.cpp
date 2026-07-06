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
#define Name "TIMSNT"

bool p[(int)1e7+7];
ll f[(int)1e7+7];
ll pow10x[10];

const ll mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	memset(p,1,sizeof p);
	p[0] = p[1] = 0;
	for(int i =2 ; i*i<=1e7; i++)if(p[i])for(int j = i*i; j <= 1e7; j+=i)p[j] = 0;

	pow10x[0] =1;
	FOR(i,1,7)pow10x[i] = pow10x[i-1]*10;

	string s;
	cin>>s;

	FOR(i,1,s.size()){
		f[i] = (f[i-1]*10+s[i-1]-'0')%mod;
	}

	int j = 0;
	ll sum = 0;
	FOR(i,1,1e7){
		if(!p[i])continue;

		int l = to_string(i).size();

		if(j+l>s.size()){
			cout<<-1;
			return 0;
		}

		sum = (sum*pow10x[l] + i)%mod;
		j += l;

		// cout<<sum<< ' '<<f[j]<< ' ';

		if(sum!=f[j]){
			cout<<-1;
			// cout<<endl<<i<<endl;
			return 0;
		}

		if(j==s.size()){
			cout<<i;
			return 0;
		}
	}
}	