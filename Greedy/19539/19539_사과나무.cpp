#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
// 1, 2만큼 자라는 물뿌리개. 한번에 3을 줄 수 있음.
// 조건 1. 모든 원소의 합이 3으로 나누어 떨어지면 YES
// 반례: 1 2 1 1 1, 1 3 1 1, 1 1 1 등... 모든 원소의 합이 3의 배수
// 조건 2. 조건 1을 만족하되, 각 나무의 크기를 2로 나눈 몫의 합이 모든 나무 크기의 합을 3으로 나눈 것보다 커야함
// 즉, (각 나무 크기 / 2)의 합 >= (모든 나무의 크기의 합) / 3 
// 아래 18, 21번째 줄

int main() {
	int N;
	cin >> N;
	int cnt = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		sum += num;
		cnt += num / 2;
	}
	// 2 3 1 2 1  ---> 1 + 1 + 0 + 1 + 0 == 3
	if (sum % 3 == 0) {
		if (cnt >= sum / 3)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}