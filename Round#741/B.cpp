#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

int T;
int k;
string s;
int arr[64];
bool prime[10000];
void init() {
	const int MAX = 10000;
	for(int i=2; i<sqrt(MAX); i++) {
		if(prime[i])	continue;
		for(int j=i*i; j<=MAX; j+=i) {
			prime[j] = true;
		}
	}
}
void input() {
	cin >> k;
	cin >> s;
	for(int i=0; i<k; i++) {
		arr[i] = s[i]-'0';
	}
}
void solve() {
	for(int i=0; i<k; i++) {
		if(arr[i] == 9 || arr[i]%2 == 0 || arr[i] == 1) {
			if(arr[i] == 2)	continue;
			cout << 1 << endl;
			cout << arr[i] << endl;
			return;
		}
	}
	map<int, int> m;
	for(int i=0; i<k; i++) {
		m[arr[i]]++;
		if(m[arr[i]] >= 2) {
			cout << 2 << endl;
			cout << arr[i] << arr[i] << endl;
			return;
		}
	}
	for(int i=0; i<k; i++) {
		for(int j=0; j<k; j++) {
			if(i == j)	continue;
			int tmp = 10*arr[i] + arr[j];
			if(prime[tmp]) {
				cout << 2 << endl;
				cout << tmp << endl;
				return;
			}
		}
	}
	for(int i=0; i<k; i++) {
		for(int j=0; j<k; j++) {
			if(i==j)	continue;
			for(int l=0; l<k; l++) {
				if(l==j || l==i)	continue;
				int tmp = 100*arr[i] + 10*arr[j] + arr[l];
				if(prime[tmp])	{
					cout << 3 << endl;
					cout << tmp << endl;
					return;
				}
			}
		}
	}
	for(int i=0; i<k; i++) {
		for(int j=0; j<k; j++) {
			if(i==j)	continue;
			for(int l=0; l<k; l++) {
				if(l==i || l==j)	continue;
				for(int m=0; m<k; m++) {
					if(m==i || m==j || m==l)	continue;
					int tmp = 1000*arr[i] + 100*arr[j] + 10*arr[l] + arr[m];
					if(prime[tmp]) {
						cout << 4 << endl;
						cout << tmp << endl;
						return;
					}
				}
			}
		}
	}	
}
bool validNum(int tmp) {
	while(tmp) {
		int mod = tmp%10;
		if(mod!=2 && mod!=3 && mod!=5 && mod!=7) {
			return false;
		}
		tmp/=10;
	}
	return true;
}
int main(void) {
	FastIO;
	init();
	cin >> T;
	while(T--) {
		input();
		solve();
	}
	return 0;
}
