#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int daysInMonth(int month, int year) {
	if (month == 2)
		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;
}

int countDays(int d, int m, int y) {
	int totalDays = 0;

	for (int year = 1900; year < y; ++year)
		totalDays += (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 366 : 365;

	for (int month = 1; month < m; ++month)
		totalDays += daysInMonth(month, y);

	totalDays += d;

	return totalDays;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	cout << countDays(stoll(b.substr(0, 2)), stoll(b.substr(3, 2)), stoll(b.substr(6, 4))) - countDays(stoll(a.substr(0, 2)), stoll(a.substr(3, 2)), stoll(a.substr(6, 4)));
}