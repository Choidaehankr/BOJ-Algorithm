#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N;
int arr[MAX];
int dp[MAX];

int main() {
    cin >> N;
    int num; 
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    /**
     * 6 10 13 9 8 1
     * N번째까지 마신 최대 포도주 양의 경우의 수 (5번째, '8'로 예시)
     * 3개를 연속으로 마실 수 없음
     * 1. (N-3까지 마신 양) + N-1 + N  : 'N-2를 마시면 N-1을 마실 수 없음'
     *    (6 + 10) + 9 + 8 = 33
     * 2. (N-2까지 마신 양) + N  : 'N-1 까지 마시면 규칙 위반'
     *    (10 + 13) + 8 = 21
     * 3. (N-1까지 마신 양) : N번째 잔을 안마실 경우에도 최댓값이 될 수 있음.
     *    예시) 1 1 10 10 1에서 (1 + 10 + 10) 이 최댓값
     */

    for(int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], max(dp[i-2] + arr[i], dp[i-1]));
    }
    cout << dp[N] << endl;
}