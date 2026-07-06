#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1000];
map<int, bool>mp;

void Try(int n) {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i < 1000; i++) {
		if (p[i]) {
			for (int j = i * i; j < 1000; j += i) {
				p[j] = 0;
			}
		}
	}

	vector<int>s;
	for (int i = 1; i <= 162; i++) {
		if (p[i])
			s.push_back(i);
	}

}
