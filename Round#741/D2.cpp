#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)
#define pb push_back

const int MAX = 3 * 1e+5;
const int ODD = 1;
const int EVEN = 0;

int T;
int n, q;
int dp[MAX+5];
int excluding[MAX+5];
string s;
vector<int> choices;
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
int getSum(int lf, int rg) {
    if(lf > rg) {
        return 0;
    }
    return (lf%2 == 1) ? dp[rg] - dp[lf-1] : dp[lf-1] - dp[rg];
}
bool isAlreadyZero(int lf, int rg) {
    return getSum(lf, rg) == 0;
}
int convertToSegment(int x, int lf, int rg) {
    int leftLen = x - lf + 1;
    if(leftLen%2 == EVEN) {
        return getSum(lf, x-1) - getSum(x+1, rg);
    }
    else if(leftLen%2 == ODD) {
        return getSum(lf, x-1) + getSum(x+1, rg);
    }
    return -1;
}
int getSign(int x) {
    return x > 0 ? 1 : -1;
}
int searchZeroWhenExclude(int lf ,int rg) {
    if(lf == rg) {
        return lf;
    }
    int l = lf;
    int r = rg;
    int ret = -1;
    while(l < r) {
        int mid = (l + r) / 2;
        int leftSum = convertToSegment(l, lf, rg);
        int rigthSum = convertToSegment(r, lf, rg);
        int midSum = convertToSegment(mid, lf, rg);
        if(leftSum == 0) {
            ret = l;
            break;
        }
        if(rigthSum == 0) {
            ret = r;
            break;
        }
        if(midSum == 0) {
            ret = mid;
            break;
        }
        if(getSign(leftSum) == getSign(midSum)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return ret;
}
void solve() {
    memset(dp, 0, sizeof dp);
    initPrefixSum();
    int lf, rg;
    for(int i=0; i<q; i++) {
        choices = vector<int>();
        cin >> lf >> rg;
        int len = rg - lf + 1;
        if(len%2 == EVEN) {
            if(isAlreadyZero(lf, rg)) {
                cout << 0 << endl;
                continue;
            } else {
                cout << 2 << endl;
                choices.pb(rg);
                int cand = searchZeroWhenExclude(lf, rg-1);     
                choices.pb(cand);
            }
        }  
        if(len%2 == ODD) {
            cout << 1 << endl;
            int cand = searchZeroWhenExclude(lf, rg);
            choices.pb(cand);
        }
        for(auto elem: choices) {
            cout << elem << " ";
        }
        cout << endl;
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