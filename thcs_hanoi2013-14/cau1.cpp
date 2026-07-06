#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct ps {
	ll ts;
	ll ms = 1;
};

void toigian(ps* n) {
	ll c = __gcd(n->ms, n->ts);
	n->ms /= c;
	n->ts /= c;
	if (n->ms < 0 && n->ts < 0) {
		n->ms = abs(n->ms);
		n->ts = abs(n->ts);
	}
	else if (n->ms < 0) {
		n->ms = -(n->ms);
		n->ts = -(n->ts);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}
	
	ps a, b, n;

	cin >> a.ts >> a.ms >> b.ts >> b.ms;

	n.ts = a.ts * b.ms - b.ts * a.ms;
	n.ms = a.ms * b.ms;

	toigian(&n);
	cout << n.ts << " " << n.ms;
}
