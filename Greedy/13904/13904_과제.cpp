#include <iostream>
#include <queue>
using namespace std;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
priority_queue<int, vector<int>, greater<int>> ans;

// 마감일이 빠른 순으로 정렬을해서 과제 점수를 다 더하다가
// 점수가 높은 과제를 할 수 없게 됐을 때, 가장 낮은 점수의 과제를 포기하고 
// 포기한 만큼 과제 할 수 있는 시간을 하루를 늘려준다.

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int d_day, score;
		cin >> d_day >> score;
		q.push({ d_day, score }); // 마감일이 빠른 순으로 정렬
	}
	int result = 0;
	// (1, 20), (2, 50), (3, 30), (4, 10), (4, 40), (4, 60), (6, 5)
	// ans의 원소 (크기, ans.top()) = (1, 20) -> (2, 20) -> (3, 20) -> (4, 10) -> (5, 10)에서
	// (ans.size() > q.top().first)에 걸림. 10을 result에서 뺀 이후 pop(). ans.size() = 4. ans.top() = 20.
	// 이후 40점을 push한 이후 ans.size()=5, (4, 60)을 만나서 if 문에 걸림. ans.top()인 20을 pop().

	while (!q.empty()) {
		ans.push(q.top().second);  // 큐 answer에 점수의 오름차순으로 push (이후 가장 낮은 점수를 빼기 위함)
		result += q.top().second;  // 일단 모든 과제 점수를 더함.
		if (ans.size() > q.top().first) {  // answer의 크기는 경과한 날짜. 
			result -= ans.top();  // 경과한 날짜가 마감기한 보다 커진다면 제출 불가능하므로 가장 낮은 과제 점수를 뺀다.
			ans.pop();
		}
		q.pop();
	}
	cout << result << endl;
}