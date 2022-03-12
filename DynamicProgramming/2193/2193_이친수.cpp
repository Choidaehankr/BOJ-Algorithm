#include <iostream>
using namespace std;
long long int dp[91] = { 0, 1, 1 };

// 이친수의 개수는 피보나치 수열을 따름!
long long int fibo(int n) {
	if (dp[n] > 0) return dp[n];
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	int N;
	cin >> N;
	cout << fibo(N) << endl;
}