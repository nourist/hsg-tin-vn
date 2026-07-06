#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)

string NAME = "eco";
int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long L, long long R) {
	return L + rd() % (R - L + 1);
}

// sinh mảng random
void gen_random(int n, int maxv, vector<int>& a) {
	FOR(i, 1, n) a[i] = Rand(1, maxv);
}

// sinh test phá XOR
void gen_xor_trap(int n, vector<int>& a, vector<int>& b) {
	// tạo pattern: {a,b} vs {c,d} có khả năng XOR giống
	// làm bằng cách lặp lại cấu trúc nhỏ
	int base = Rand(1, 1e6);

	FOR(i, 1, n) {
		int t = i % 4;
		if (t == 1) a[i] = base;
		else if (t == 2) a[i] = base + 1;
		else if (t == 3) a[i] = base + 2;
		else a[i] = base + 3;
	}

	// hoán vị lại để tạo đoạn khác nhau
	b = a;
	shuffle(b.begin() + 1, b.end(), rd);
}

// sinh query
void gen_query(int n, int q, vector<array<int, 4>>& queries) {
	FOR(i, 1, q) {
		int l = Rand(1, n);
		int r = Rand(l, n);
		int x = Rand(1, n);
		int y = Rand(x, n);
		queries.push_back({ l, r, x, y });
	}
}

void gen() {
	ofstream inp((NAME + ".inp").c_str());

	int n = Rand(1, 200000);
	int q = Rand(1, 200000);

	// để debug dễ hơn có thể giảm:
	if (Rand(1, 5) == 1) {
		n = Rand(1, 2000);
		q = Rand(1, 2000);
	}

	vector<int> a(n + 1), b(n + 1);

	// if (Rand(1, 2) == 1) {
		// random thường
	int maxv = Rand(1, n);
	gen_random(n, maxv, a);
	gen_random(n, maxv, b);
	// }
	// else {
	// 	// test phá XOR
	// 	gen_xor_trap(n, a, b);
	// }

	vector<array<int, 4>> queries;
	gen_query(n, q, queries);

	inp << n << " " << q << "\n";
	FOR(i, 1, n) inp << a[i] << " ";
	inp << "\n";
	FOR(i, 1, n) inp << b[i] << " ";
	inp << "\n";

	for (auto& qq : queries) {
		inp << qq[0] << " " << qq[1] << " " << qq[2] << " " << qq[3] << "\n";
	}

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	compile();

	FOR(i, 1, NTEST) {
		gen();
		if (test()) {
			cout << "Test " << i << " OK" << endl;
		}
		else {
			cout << "Test " << i << " WRONG" << endl;
			return 0;
		}
	}
}