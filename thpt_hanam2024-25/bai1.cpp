#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name ""

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    string str;
    cin>>str;
    
    int cnt =0;
    for(char i : str)cnt+=(i!='0'&&i!='1');
    cout<<cnt;
}
