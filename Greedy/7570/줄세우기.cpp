#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 1000001
using namespace std;

int N, answer;
int dp[MAX];

int main() {
    cin >> N;
    int x;
    for(int i = 1; i <= N; i++) {
        cin >> x;
        dp[x] = dp[x-1] + 1;
    }

    for(int i = 1; i <= N; i++) {
        answer = max(dp[i], answer);
    }

    cout << N - answer;
}