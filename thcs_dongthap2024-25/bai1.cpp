#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
    
    ll n, k;
    cin>>n>>k;
    
    cout << n/k+(!!(n%k));
}
