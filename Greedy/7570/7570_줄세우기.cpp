#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 1000001
using namespace std;

int N, answer;
int dp[MAX];

/**
 * 입력을 다 받고 '증가하는 가장 긴 수열' 을 찾으니 시간초과.
 * 입력과 동시에 연속하는 수열인지를 확인
 */

int main() {
    cin >> N;
    int x;
    for(int i = 1; i <= N; i++) {
        cin >> x;
        dp[x] = dp[x-1] + 1;  // 입력과 동시에 '연속하는 수열'을 찾음
    }

    for(int i = 1; i <= N; i++) {
        answer = max(dp[i], answer);  // 가장 긴 연속하는 수열
    }

    cout << N - answer;
}