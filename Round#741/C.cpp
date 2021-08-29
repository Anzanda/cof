#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int len;
string s;
void input() {
	cin >> len;
	cin >> s;
}
void solve() {
	bool flag = false;
	for(int i=0; i<len; i++) {
		if(s[i] != '1') {
			flag = true;
			break;
		}
	}
	if(!flag) { // all of char is '1'
		cout << 1 << " " << len-1 << " ";
		cout << 2 << " " << len << endl;
		return;
	}
	for(int i=0; i<len/2; i++) {
		if(s[i] == '0') {
			cout << i+2 << " " << len << " ";
			cout << i+1 << " " << len << endl;
			return;
		}
	}
	for(int i=len/2; i<len; i++) {
		if(s[i] == '0') {
			cout << 1 << " " << i+1 << " ";
			cout << 1 << " " << i << endl; 
			return;
		}
	}
}
int main(void) {
	FastIO;
	int T;
	cin >> T;
	while(T--) {
		input();
		solve();
	}
	return 0;
}
