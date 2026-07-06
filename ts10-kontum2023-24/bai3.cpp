#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	
}

/*

S(u,v)=F[v]-F[u-1]
S(l,r)=F[r]-F[l-1]

S(u,v)-S(l,r)=0=>F[v]+F[l-1]==F[r]+F[u-1]

*/