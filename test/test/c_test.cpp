#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

string NAME = "c";
int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long L, long long R) {
	assert(L <= R);
	return L + rd() % (R - L + 1);
}

void gen() {
	ofstream inp((NAME + ".inp").c_str());

	inp.close();
}

void compile() {
system(("g++ -o " + NAME + ".exe " + NAME + ".cpp -std=c++17 -O2").c_str());
system(("g++ -o " + NAME + "_trau.exe " + NAME + "_trau.cpp -std=c++17 -O2").c_str());
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

	compile();

	FOR(i, 1, NTEST) {
		gen();
		if (test()) {
			cout << "Test " << i << " OK\n";
		}
		else {
			cout << "Test " << i << " Wrong\n";
			return 0;
		}
	}
}