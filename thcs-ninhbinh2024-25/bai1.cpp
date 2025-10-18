#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    #define lcm(a,b) (a/__gcd(a,b)*b)
    ll s1 = y/a-y/lcm(a,b);
    ll s2 = (x-1)/a-(x-1)/lcm(a,b);
    cout << s1-s2;
}
