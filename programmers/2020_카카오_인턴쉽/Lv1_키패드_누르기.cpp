/**
 * 
 *  이 전화 키패드에서 왼손과 오른손의 엄지손가락만을 이용해서 숫자만을 입력하려고 합니다.
    맨 처음 왼손 엄지손가락은 * 키패드에 오른손 엄지손가락은 # 키패드 위치에서 시작하며, 엄지손가락을 사용하는 규칙은 다음과 같습니다.

    엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당합니다.
    왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용합니다.
    오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용합니다.
    가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용합니다.
    
    만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을
    사용합니다.
    
    순서대로 누를 번호가 담긴 배열 numbers, 왼손잡이인지 오른손잡이인 지를 나타내는 문자열 hand가 매개변수로 주어질 때, 각 번호를 누른 엄지손가락이 왼손인 지 오른손인 지를 나타내는 연속된 문자열 형태로 return 하도록 solution 함수를 완성해주세요.
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

string answer = "";
char keypad[4][3];
map<int, pair<int, int> > m;
pair<int, int> finger, left_finger, right_finger;

void init() {
	// map으로 각 숫자의 키패드 상 좌표 초기화
	int num = 1;
	m[0] = make_pair(3, 1);
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			m[num++] = make_pair(i, j);
		}
	}
	// 초기 손가락 위치
	keypad[3][0] = 'l';
	keypad[3][2] = 'r';
	left_finger = make_pair(3, 0);
	right_finger = make_pair(3, 2);
}

void checkFinger(int num, char ch) {
	// 왼쪽 손가락으로 눌러야 할 경우 (ch == 'L')
	if (ch == 'L') {
		keypad[m[num].first][m[num].second] = 'l';  // 왼 손가락으로 눌렀다고 키패드 상 표시
		answer += 'L';
		finger = left_finger;  // 직전에 위치했던 손가락의 위치를 없애주기 위해 직전 왼손의 위치를 저장
		left_finger = m[num];  // 현재 왼손가락의 위치를 갱신
	}
	else {
		keypad[m[num].first][m[num].second] = 'r';
		answer += 'R';
		finger = right_finger;
		right_finger = m[num];
	}
}

string solution(vector<int> numbers, string hand) {
	init();
	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];
		int x = m[num].first;
		int y = m[num].second;
		if (num == 1 || num == 4 || num == 7) {
			checkFinger(num, 'L');
		}
		else if (num == 3 || num == 6 || num == 9) {
			checkFinger(num, 'R');
		}
		else if (num == 2 || num == 5 || num == 8 || num == 0) {
			// 눌러야 할 버튼과 현재 왼/오른손가락의 위치를 비교
			int left_dist = abs(left_finger.first - x) + abs(left_finger.second - y);  
			int right_dist = abs(right_finger.first - x) + abs(right_finger.second - y);
			if (left_dist == right_dist) {
				if (hand == "left") {
					checkFinger(num, 'L');
				}
				else if (hand == "right") {
					checkFinger(num, 'R');
				}
			}
			else {
				if (left_dist > right_dist) {
					checkFinger(num, 'R');
				}
				else {
					checkFinger(num, 'L');
				}
			}
		}
		keypad[finger.first][finger.second] = '0';  // 버튼을 누른 이후 직전에 있던 손가락의 위치를 제거
	}
	return answer;
}