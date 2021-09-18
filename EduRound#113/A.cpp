#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int t;
int n;
string str;
void input() {
    cin >> n;
    cin >> str;
}
void solve() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int a = 0;
            int b = 0;
            for(int k=i; k<=j; k++) {
                if(str[k] == 'a') {
                    a++;
                } else {
                    b++;
                }
            }
            if(a == b) {
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
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
