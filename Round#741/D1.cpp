#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 3 * 1e+5;

int T;
int n, q;
string s;
int dp[MAX+5];
void input() {
    cin >> n >> q;
    cin >> s;
}
void initPrefixSum() {
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        if(s[i-1] == '+') {
            dp[i] = dp[i-1] + (i%2?1:-1);
        } else {
            dp[i] = dp[i-1] + (i%2?-1:1);
        }
    } 
}
void solve() {
    memset(dp, 0, sizeof dp);
    initPrefixSum();
    int lf, rg;
    for(int i=0; i<q; i++) {
        cin >> lf >> rg;
        int len = rg - lf + 1;
        if(len%2 == 0) {
            int segSum = dp[rg] - dp[lf-1];
            if(segSum == 0) {
                cout << 0 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << 1 << endl;
        }
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