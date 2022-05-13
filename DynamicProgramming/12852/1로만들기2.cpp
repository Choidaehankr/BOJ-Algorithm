#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000001
using namespace std;

int n, dp[MAX], route[MAX];

void solve(int num) {
    dp[1] = 0;
    for(int i = 2; i <= num; i++) {
        dp[i] = dp[i-1] + 1;
        route[i] = i-1;

        if(i % 3 == 0) {
            if(dp[i] > dp[i/3] + 1) {
                dp[i] = dp[i/3] + 1;
                route[i] = i/3;
            }
        }
        if(i % 2 == 0) {
            if(dp[i] > dp[i/2] + 1) {
                dp[i] = dp[i/2] + 1;
                route[i] = i/2;
            }
        }
    }
}

int main() {
    cin >> n;
    solve(n);
    cout << dp[n] << endl;
    int idx = n;
    while(1) {
        if(idx == 0) break;
        cout << idx << ' ';
        idx = route[idx];
    }
}