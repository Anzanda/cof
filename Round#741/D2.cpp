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
set<int> choices;
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
void initExcludeSum() {
    for(int i=1; i<=n; i++) {
        excluding[i] = dp[i-1] - (dp[n] - dp[i]);
    }
}
bool isAlreadyZero(int lf, int rg) {
    int sum = dp[rg] - dp[lf-1];
    return sum == 0;
}
int convertToSegment(int x, int lf, int rg) {
    return excluding[x] - dp[lf-1] + (dp[n] - dp[rg]); 
}
int searchZeroWhenExclude(int lf ,int rg) {
    int POS;
    int NEG;
    if(convertToSegment(lf, lf, rg) > 0) {
        POS = lf;
        NEG = rg;
    } else {
        POS = rg;
        NEG = lf;
    }
    while(POS != NEG) {
        int mid = (POS + NEG) / 2;
        int excludedSum = convertToSegment(mid, lf, rg);
        if(excludedSum == 0) {
            return mid;
        } else if(excludedSum > 0) {
            POS = mid; 
        } else {
            NEG = mid;
        }
    } 
    return rg;
}
void solve() {
    memset(dp, 0, sizeof dp);
    initPrefixSum();
    initExcludeSum();
    int lf, rg;
    for(int i=0; i<q; i++) {
        choices = set<int>();
        cin >> lf >> rg;
        int len = rg - lf + 1;
        if(len == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        if(len%2 == EVEN) {
            if(isAlreadyZero(lf, rg)) {
                cout << 0 << endl;
            } else {
                cout << 2 << endl;
                choices.insert(rg);
                int cand = searchZeroWhenExclude(lf, rg-1);     
                choices.insert(cand);
            }
            
        }  
        if(len%2 == ODD) {
            cout << 1 << endl;
            int cand = searchZeroWhenExclude(lf, rg);
            choices.insert(cand);
        }
        for(auto elem: choices) {
            cout << elem << " ";
        }
        if(choices.size()) {
            cout << endl;
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