#include <iostream>
using namespace std;
int d, k, cnt;
int arr[31];

// 1일: a, 2일: b, 3일: a+b, 4일: a+2b, 5일: 2a+3b, 6일: 3a+5b, 7일: 5a+8b...
// 따라서 N일차에는.. (N-2번째 피보나치수열 * a) + (N-1번째 * B)
// 즉, 피보나치 수열 값만 31일까지 모두 구한 뒤, 알맞은 A, B 값을 찾으면 됨

int main() {
	cin >> d >> k;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 31; i++) { // 31일차까지 피보나치 수열을 구함
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	int numA = arr[d - 2];  // N-2번째 피보나치 수열
	int numB = arr[d - 1];  // N-1번째 피보나치 수열
	for (int i = 1; i <= k; i++) {
		int tempA = numA * i;  // (N-2번째 피보나치 * A)
		for (int j = 1; j < k; j++) {
			int tempB = numB * j;  // (N-1번째 피보나치 * B)
			if (tempA + tempB == k) {
				cout << i << '\n' << j;
				return 0;
			}
		}
	}
}