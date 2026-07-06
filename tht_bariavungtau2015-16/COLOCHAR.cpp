#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("COLOCHAR.inp", "r")) {
		freopen("COLOCHAR.inp", "r", stdin);
		freopen("COLOCHAR.out", "w", stdout);
	}

	string str = "HOITHITINHOCTRETINHBARIAVUNGTAULANTHUXX";
	string color = "XDTV";
	int n;
	cin >> n;
	cout<<str[n%str.size()]<<endl<<color[n%color.size()];
}
