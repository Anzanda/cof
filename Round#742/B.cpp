#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int t;
int a, b;
void input() {
    cin >> a >> b;
}
void solve() {
    int res = 0;
    for(int i=0; i<a; i++) {
        res = res ^ i;
    }
    if(a == b) {
        cout << a + 2 << endl;
    } else {
        if(res == b) {
            cout << a << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
}
int main(void) {
    FastIO;
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}