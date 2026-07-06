#include <iostream>
#include <ctime>

int days_between(int y1, int m1, int d1, int y2, int m2, int d2) {
	std::tm a = {};
	a.tm_year = y1-1900;
	a.tm_mon = m1 - 1;
	a.tm_mday = d1;

	std::tm b = {};
	b.tm_year = y2-1900;
	b.tm_mon = m2 - 1;
	b.tm_mday = d2;

	std::time_t x = std::mktime(&a);
	std::time_t y = std::mktime(&b);

	double difference = std::difftime(y, x) / (60 * 60 * 24);
	return static_cast<int>(difference);
}

int main() {
	std::cout << days_between(2025, 1, 1, 2025, 1, 1) << " ngày\n";
	return 0;
}
