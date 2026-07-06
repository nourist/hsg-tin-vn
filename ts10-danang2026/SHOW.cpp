#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

vector<int>preP = { 2,
3,
5,
7,
11,
13,
17,
19,
23,
29,
31,
37,
41,
43,
47,
53,
59,
61,
67,
71,
73,
79,
83,
89,
97 };
vector<int>primes;

int sum = 0;
vector<int>res;

void Try(int i) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("SHOW.inp", "r")) {
		freopen("SHOW.inp", "r", stdin);
		freopen("SHOW.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i : preP)if (i <= n)primes.push_back(i);

	Try(1);
}
