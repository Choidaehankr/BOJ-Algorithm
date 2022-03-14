#include <iostream>
#include <algorithm>
using namespace std;

int dp[301];
int stair[301];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> stair[i];
    }

    // 1.
    // dp[1] = stair[1];
    // dp[2] = max(stair[1]+stair[2], stair[2]);
    // dp[3] = max(stair[2]+stair[3], stair[1]+stair[3]);
    // for(int i = 4; i <= N; i++) {
    //     dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
    // }

    // 2.
    dp[1] = stair[1];
    dp[2] = stair[1]+stair[2];

    for(int i = 3; i <= N; i++) {
        dp[i] = stair[i] + max(dp[i-2], stair[i-1] + dp[i-3]);
    }

    cout << dp[N] << endl;
}