#include <bits/stdc++.h>
using namespace std;

#define endl  "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int T;
int l, r;
void input() {
	cin >> l >> r;
}
void solve() {
	if(l > r/2+1) {
		cout << r%l << endl;
	} else {
		cout << r%(r/2+1) << endl;
	}
}
int main(void) {
	FastIO;
	cin >> T;
	while(T--) {
		input();
		solve();
	}
	return 0;
}
