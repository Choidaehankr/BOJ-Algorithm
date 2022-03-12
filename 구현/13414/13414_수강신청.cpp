#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int K, L;
	cin >> K >> L;
	string str; 
	map<string, int> m;
	queue<pair<string, int>> q;

	for (int i = 0; i < L; i++) {
		cin >> str;
		q.push({ str, i });  // queue에 입력 받은 모든 학번(str)과 순서(i)를 push
		if (m.find(str) != m.end()) {  // 찾았다면(중복 클릭) 해당 학번을 대기열 맨뒤로 보냄.
			m[str] = i;
		}
		else {
			m.insert({ str, i });
		}
	}
	int cnt = 0;
	
	// map에 저장된 해당 학번의 최종 대기 순위와 queue에서의 해당 학번의 순서를 비교
	// 일치한다면 출력, K번 반복
	// 20103372
	while (!q.empty()) {
		if (cnt == K)
			break;
		string s = q.front().first;
		int num = q.front().second;
		q.pop();
		if (m[s] == num) {  
			cout << s << "\n";  // 줄바꿈으로 endl 사용시 시간초과.
			cnt++;
		}
	}
}