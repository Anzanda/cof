#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)


const int MAX = 3*1e6;
int t;
int a, b;
int xorArr[MAX+1];
void initXorArr() {
    xorArr[0] = 0;
    for(int i=1; i<=MAX; i++) {
        xorArr[i] = xorArr[i-1]^i;
    }
}
void input() {
    cin >> a >> b;
}
void solve() {
    if(xorArr[a-1] == b) {
        cout << a << endl;
    } else {
        if(xorArr[a] == b) {
            cout << a + 2 << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
}
int main(void) {
    FastIO;
    initXorArr();
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}