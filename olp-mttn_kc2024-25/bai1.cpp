#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 
#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)

bool prime(int n) {
	for (int i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 1;
}

void printDate(int d, int m, int y) {
	if (d <= 9)cout << 0 << d;
	else cout << d;
	cout << "/";
	if (m <= 9)cout << 0 << m;
	else cout << m;
	cout << "/";
	if (y <= 9)cout << "000" << y;
	else if (y <= 99)cout << "00" << y;
	else if (y <= 999)cout << 0 << y;
	else cout << y;
	cout << endl;
}

vector<pii>primeDays;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	FOR(i, 1, 12)FOR(j, 1, 30)if (prime(i) && prime(j))primeDays.push_back({ i,j });
	primeDays.push_back({ 13,2 });
	primeDays.push_back({ 13,3 });
	primeDays.push_back({ 13,5 });

	string str;
	cin >> str;

	int d = stoi(str.substr(0, 2));
	int m = stoi(str.substr(3, 2));
	int y = stoi(str.substr(6, 4));

	{
		auto it = lower_bound(primeDays.begin(), primeDays.end(), make_pair(m, d));
		if (it == primeDays.begin()) {
			printDate(primeDays.back().Y, primeDays.back().X, y - 1);
		}
		else {
			it--;
			printDate(it->Y, it->X, y);
		}
	}

	{
		auto it = upper_bound(primeDays.begin(), primeDays.end(), make_pair(m, d));
		if (it == primeDays.end()) {
			printDate(primeDays.front().Y, primeDays.front().X, y + 1);
		}
		else {
			printDate(it->Y, it->X, y);
		}
	}
}
