#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool checkRange(char sign, int num, int sub) {
	if (sign == '=') {
		return num == sub;
	}
	else if (sign == '>') {
		return sub > num;
	}
	else if (sign == '<') {
		return sub < num;
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string str = "ACFJNMRT";  // 8명의 친구들을 문자열로 선언
	sort(str.begin(), str.end());
	do {
		bool flag = true;
		for (int i = 0; i < data.size(); i++) {
			int sub = abs((int)str.find(data[i][0]) - (int)str.find(data[i][2])) - 1;  // 두 친구의 위치 간격을 저장
			int num = data[i][4] - '0';  // 조건을 제시한 친구가 원하는 거리
			char sign = data[i][3];
			if (!checkRange(sign, num, sub)) {
				flag = false;
				break;
			}
		}
		if (flag) answer++;
	} while (next_permutation(str.begin(), str.end()));  // 문자열의 순열 구하기 (모든 경우의 수)
	cout << "answer: " << answer;
	return answer;
}