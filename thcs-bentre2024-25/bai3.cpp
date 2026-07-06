#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	string str;
	getline(cin, str);

	vector<string>a;

	string tmp = "";
	for(int i = 0 ; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp+=str[i];
		}
		else {
			if (!tmp.empty())a.push_back(tmp), tmp = "";
			if(str[i] != ' ')
			a.push_back(string(1, str[i]));
		}
	}
	if(!tmp.empty())a.push_back(tmp);
	
	// for (string x : a)cout << x << " ";

	stack<string>st;
	for (string x : a) {
		if (x == "(") {
			string tmp = "";
			while (!st.empty() && st.top() != "(") {
				tmp = st.top() + tmp;
				st.pop();
			}
			if (!tmp.empty())st.push(tmp);
			st.push("(");
		}
		else if (x == ")") {
			string tmp = "";
			while (!st.empty() && st.top() != "(") {
				tmp = st.top() + tmp;
				st.pop();
			}
			st.pop();
			if (!tmp.empty())st.push(tmp);
		}
		else if(x[0]>='A'&&x[0]<='Z') {
			st.push(x);
		}
		else {
			string tmp = st.top();
			st.pop();
			string sum = "";
			for (int i = 1; i <= stoll(x); i++)sum += tmp;
			if(!sum.empty())
				st.push(sum);
		}
		cout << st.top() << endl;
	}
	string res = "";
	while (!st.empty()) {
		res = st.top() + res;
		st.pop();
	}
	cout << res;
}
