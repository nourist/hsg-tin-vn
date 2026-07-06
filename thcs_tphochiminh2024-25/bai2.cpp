#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name ""

int a[(int)1e5+5], l[(int)1e5+5], r[(int)1e5+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++)cin>>a[i];
    l[1]=a[1];
    r[n]=a[n];

    for(int i = 2; i <= n; i++)l[i]=__gcd(l[i-1], a[i]);
    for(int i = n-1; i >= 1; i--)r[i]=__gcd(r[i+1], a[i]);

    int res =0;
    for(int i = 2; i < n; i++){
        res=max(res, __gcd(l[i-1], r[i+1]));
    }
    cout << res;
}
