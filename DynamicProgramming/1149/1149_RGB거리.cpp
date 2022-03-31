#include <iostream>
#include <algorithm>
#include <stdio.h>

#define MAX 1001
#define RED 0
#define GREEN 1
#define BLUE 2
using namespace std;

int dp[MAX][3];
int N;
int main() {
    cin >> N;
    cin >> dp[0][RED] >> dp[0][GREEN] >> dp[0][BLUE];
    for(int i = 1; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        dp[i][RED] = min(dp[i-1][BLUE], dp[i-1][GREEN]) + r;
        dp[i][GREEN] = min(dp[i-1][BLUE], dp[i-1][RED]) + g;
        dp[i][BLUE] = min(dp[i-1][RED], dp[i-1][GREEN]) + b;
    }
    N--;
    int num = (dp[N][RED] <= dp[N][GREEN] && dp[N][RED] <= dp[N][BLUE]) ? dp[N][RED] : (dp[N][GREEN] <= dp[N][BLUE] && dp[N][GREEN] <= dp[N][RED]) ? dp[N][GREEN] : dp[N][BLUE];
    cout << num << endl;
}