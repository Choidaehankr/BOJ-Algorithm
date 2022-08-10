#include <iostream>
#include <queue>
using namespace std;

// 작은 숫자들을 먼저 처리해주면 쉽게 풀이 가능
// priority_queue 사용으로 카드를 오름차순 정렬
// 자료형 주의

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long> > q;
	long long num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		q.push(num);
	}
	for (int i = 0; i < m; i++) {
		long long sum = q.top();
		q.pop();
		sum += q.top();
		q.pop();
		q.push(sum);
		q.push(sum);
	}
	long long answer = 0;
	while (!q.empty()) {
		answer += q.top();
		q.pop();
	}
	cout << answer << endl;
}