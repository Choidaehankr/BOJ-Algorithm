#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int N;
int arr[MAX];

// 오름차순으로 정렬된 배열 arr[]

// 예시) arr[] = { 1 2 5 }, answer = 1
// 1. (1)에서, 1을 만들 수 있음. answer = 1 + 1 = 2
// 2. (2)에서, 1, 2, 3을 만들 수 있음. answer = 1 + 1 + 2 = 4
// 3. (5)에서, 4를 만들지 못함. ( arr[i] > answer == 4 ) 

// 즉, 배열의 현재 접근한 인덱스까지의 저울추로 1 ~ M 까지 무게를 만들 수 있다고 가정하면, 
// 다음 접근할 저울추(X)가 M 보다 작거나 같아야 (1 + M) ~ (M + X)를 만들 수 있음.
// 위의 예시처럼 X가 M 보다 크다면 1 + M을 측정하지 못함.

// 다른 예시로, 현재까지의 저울추로 1~5의 무게를 측정할 수 있다고 가정
// 다음 저울추가 6이라면 '6을 포함한 (1+6) ~ (5+6)', 즉 6~11 까지 무게 측정이 가능
// 하지만 다음 저울추가 7이라면, '6'을 측정할 수 없으므로 종료

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// 오름차순
	sort(arr, arr + N);  

	// 측정 가능한 최솟값은 1로 설정
	int answer = 1;

	for (int i = 0; i < N; i++) {
		if (arr[i] > answer) {
			break;
		}
		answer += arr[i];
	}
	cout << answer << endl;
}