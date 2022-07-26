#include <iostream>
#include <algorithm>
using namespace std;

int N, M, answer = 0;

int maze[1001][1001];
int dp[1001][1001];
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }

/**
 * 3가지 숫자 중 가장 큰 수를 찾는 것
 * max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]))
 */
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = maze[i][j] + max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout << dp[N][M];
}