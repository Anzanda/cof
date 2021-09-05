#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

int t;
int n;
string str;
void input() {
    cin >> n;
    cin >> str;
}
void solve() {
    for(int i=0; i<n; i++) {
        if(str[i] == 'U') {
            cout << "D";
        } else if(str[i] == 'D') {
            cout << "U";
        } else {
            cout << str[i];
        }
    }
    cout << endl;
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