#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

int t;
string n;
void input() {
    cin >> n;
}
void solve() {
    int odd = 0;
    int even = 0;
    int oddIdx = 0;
    int evenIdx = 0;
    for(int i=n.length()-1; i>=0; i--) {
        if(i%2 == 0) {
            odd += (n[i]-'0')*pow(10, oddIdx);
            oddIdx++;
        }  else {
            even += (n[i]-'0')*pow(10, evenIdx);
            evenIdx++;
        }
    }    
    int ans = (odd+1)*(even+1) - 2;
    cout << ans << endl;
}
int main(void ) {
    FastIO;
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}