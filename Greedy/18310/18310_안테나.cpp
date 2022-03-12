#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;
	// 배열의 중간값이 정답이 됨.
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	if (N % 2 == 0) {
		cout << v[(N / 2) - 1];
	}
	else {
		cout << v[N / 2];
	}
}