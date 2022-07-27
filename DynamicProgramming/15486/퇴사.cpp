#include <iostream>
#include <algorithm>
#define MAX 1500000 + 10
using namespace std;

int N;
int arr[MAX][2];
int dp[MAX];

int maxNum = 0, answer;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		//		소요 일   >>  받는 비용
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= N + 1; i++) {
		int day = arr[i][0];
		int cost = arr[i][1];
		int maxNum = max(maxNum, dp[i]);
		if (i + day > N + 1) {
			continue;
		}
		dp[i + day] = max(maxNum + cost, dp[i + day]);
		answer = maxNum;
	}
	cout << answer;
}