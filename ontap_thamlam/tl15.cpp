#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,b,a) for(int i = b; i >= a; i--)
#define A first
#define B second
#define pii pair<int,int>
#define pib pair<int,bool>
#define Name ""

pib a[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n) {
		cin >> a[i].A;
		a[i].B = 1;
	}
	FOR(i, n + 1, 2 * n) {
		cin >> a[i].A;
		a[i].B = 0;
	}

	sort(a + 1, a + 2 * n + 1);

	int res = 0;
	FOR(i, 2, 2 * n) {
		if (a[i].B != a[i - 1].B) {
			res++;
			i++;
		}
	}

	cout << res;
}
