#include <iostream>
#include <algorithm>
using namespace std;

string s;
int N, cnt = 0;
int answer = 1e9;

// 1. 빨간색 공을 왼쪽으로 몰아넣는 경우
// 2. 빨간색 공을 오른쪽으로 몰아넣는 경우
// 3. 파란색 공을 왼쪽으로 몰아넣는 경우
// 4. 파란색 공을 오른쪽으로 몰아넣는 경우

// 목표 공을 찾기 위한 지점을 flag = true로 설정
// 만약 s[i]가 목표 공이 아닐 경우 flag = true로 설정. 이 지점을 기준으로 s[i]가 위치를 바꿔야 할 색상의 공인지 파악

void solution(char x) {
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != x) {
			flag = true;
		}
		else if (flag && s[i] == x) {
			cnt++;
		}
	}
	answer = min(answer, cnt);
	cnt = 0;
	flag = false;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != x) {
			flag = true;
		}
		else if (flag && s[i] == x) {
			cnt++;
		}
	}
	answer = min(answer, cnt);
}

int main() {
	cin >> N;
	cin >> s;
	solution('R');
	solution('B');
	cout << answer << endl;
}