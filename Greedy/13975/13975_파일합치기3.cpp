#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 파일 크기를 오름차순으로 정렬한 후 앞에서 부터 합치면 됨.
// 우선순위 큐 사용

int main() {
	int testCase;
	cin >> testCase;
	for (int test = 0; test < testCase; test++) {
		int N; cin >> N;
		long long result = 0;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			pq.push(num);
		}
		while (1) {
			long long sum = pq.top();
			pq.pop();
			if (pq.empty()) {
				break;
			}
			sum += pq.top();
			pq.pop();
			pq.push(sum);
			result += sum;
		}
		cout << result << endl;
	}
}