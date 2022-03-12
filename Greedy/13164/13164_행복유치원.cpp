#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int arr[300000];
int dif[300000];

// 입력은 오름차순으로 들어옴

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		dif[i] = num;
	}

	for (int i = 1; i < N; i++) {
		arr[i - 1] = dif[i] - dif[i - 1];
	}

	sort(arr, arr + N - 1);
	int sum = 0;
	for (int i = 0; i < N - K; i++) {
		sum += arr[i];
	}
	cout << sum << endl;
}