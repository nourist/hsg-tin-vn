#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen(".INP", "r", stdin);
//	freopen(".OUT", "w", stdout);

    ld a,b;
    cin>>a>>b;
    ll res = a*b;
    if(res>=2000000)res=res/100*85;
    cout<<setprecision(0)<< res;
}
