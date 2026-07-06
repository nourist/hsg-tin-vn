#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int fib[100];
unordered_map<int,bool>isfib;

bool ok(int n){
    int s =0;

    while(n!=0){
        s+=n%10;
        n/=10;
    }

    return isfib[s];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fib[1]=fib[2]=1;

    isfib[1]=1;
    for(int i =3; i <= 30; i++){
        fib[i]=fib[i-1]+fib[i-2];
        isfib[fib[i]]=1;
    }

    int n;
    cin>>n;

    int res =0;
    for(int i =1; i *i<=n; i++){
        res+=ok(i*i);
    }
    cout << res;
}
