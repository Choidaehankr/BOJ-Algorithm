#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 문자열의 맨 뒤 c부터 문자열의 맨 앞 str[0]까지 접근
// c가 str[i]보다 커지는 순간, 문자를 swap하고 인덱스 i를 저장
// str[i]부터 str[str.size()-1]까지 오름차순 정렬.

// 도대체 왜 틀린지 모르겠음; 재도전

string solution(string str) {
	int idx = 0;
	bool flag = false;
	for (int i = str.size() - 1; i >= 0; i--) {
		for (int j = i-1; j >= 0; j--) {
			if (str[i] > str[j]) {
				swap(str[i], str[j]);
				idx = j;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (idx == 0) {
		return str;
	}
	else {
		sort(str.begin() + idx + 1, str.end());
		return str;
	}
}

int main() {
	int N; cin >> N;
	while (N--) {
		string str;
		cin >> str;
		cout << solution(str) << endl;
	}
}
