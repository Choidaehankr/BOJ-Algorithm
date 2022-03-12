#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<pair<int, int>> s;
	int N; cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		int cmd, score, time;
		cin >> cmd;
		if (cmd == 1) {  // 과제를 받자마자 스택에 넣어 가장 먼저 수행
			cin >> score >> time;
			s.push({score, time});
		}
		if (!s.empty()) {
			s.top().second--;  // 분마다 과제의 남은 시간을 1 감소.
			if (s.top().second == 0) {
				result += s.top().first;
				s.pop();
			}
		}
	}
	cout << result << endl;
}