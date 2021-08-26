#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int t;
int l, r;
int ans;
void input() {
	cin >> l >> r;
}
void solve() {
	if(r/l == 1) {
		ans = r%l;
	} else {
		ans = r%(r/2+1);
	}	
	cout << ans << endl;
}
int main(void) {
	cin >> t;
	while(t--) {
		input();
		solve();
	}
	return 0;
}
