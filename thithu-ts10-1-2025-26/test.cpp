#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

string INP = "grade";
string NAME = "grade";
int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long L, long long R) {
	assert(L <= R);
	return L + rd() % (R - L + 1);
}

void gen() {
	ofstream inp((INP + ".inp").c_str());
	inp << Rand(0, 9);
	FOR(i, 1, 8) {
		inp << (Rand(0, 1) ? '+' : '*');
		inp<<Rand(0, 9);
	}
	inp << '\n';
	int n = Rand(1, 100);
	inp << n << ' ' << Rand(1, 10) << ' ' << Rand(1, 10) << '\n';
	FOR(i, 1, n) {
		inp << Rand(0, 1000) << ' ';
	}
	inp.close();
}

bool test() {
	system((NAME + ".exe").c_str());
	system((NAME + "_trau.exe").c_str());

	return system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	FOR(i, 1, NTEST) {
		gen();
		if (test()) {
			cout << "Test " << i << " OK\n";
			cnt++;
		}
		else {
			cout << "Test " << i << " Wrong\n";
		}
	}
	cout<<"Total: " << cnt << "/" << NTEST << '\n';
}