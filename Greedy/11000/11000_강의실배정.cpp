#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N; cin >> N;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end }); 
	}
	
	// 수업이 일찍 시작하는 순서대로 정렬. 시작시간이 같다면 일찍 끝나는 순서대로 정렬

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
		});

	pq.push(v[0].second);  // 첫번째 수업이 끝나는 시간을 push
	// 현재 수업이 끝나는 시간과, 다음 수업이 시작하는 시간을 비교.
	for (int i = 1; i < N; i++) {
		pq.push(v[i].second);
		if (pq.top() <= v[i].first) {
			pq.pop();
		}
	}
	cout << pq.size();
}