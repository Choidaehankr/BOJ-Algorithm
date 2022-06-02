#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cctype>
#include <map>

using namespace std;

map<string, int> m1, m2;

int solution(string str1, string str2) {
	int answer = 0;
	// 대소문자의 구분이 없으므로 str1, str2 모두 대문자로 변환
	transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) {return toupper(c); });
	for (int i = 0; i < str1.size() - 1; i++) {
		if (str1[i] < 'A' || str1[i] > 'Z' || str1[i + 1] < 'A' || str1[i + 1] > 'Z') continue;
		string tmp = str1.substr(i, 2);
		m1[tmp] += 1;
	}
	transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) {return toupper(c); });
	for (int i = 0; i < str2.size() - 1; i++) {
		if (str2[i] < 'A' || str2[i] > 'Z' || str2[i + 1] < 'A' || str2[i + 1] > 'Z') continue;
		string tmp = str2.substr(i, 2);
		m2[tmp] += 1;
	}

	if (m1.size() + m2.size() == 0) return 65536;  // 각 집합이 없는 경우 조기 종료

	int num = 0, cnt = 0;

	// 교집합 찾기 min(m1의 집합, m2의 집합)
	// 다중집합 A = { 1, 1, 2, 2, 3 }, 다중집합 B = { 1, 2, 2, 4, 5 }라고 하면, 
	// 교집합 A ∩ B = { 1, 2, 2 }
	// -> A(= m1)는 '1': 2개, '2': 2개, '3': 1개 / B(= m2)는 '1': 1개, '2': 2개, '4': 1개, '5': 1개
	// -> m1['1'] = 2, m2['1'] = 1, min(1, 2) = 1이므로, 누적 교집합 수에 1을 더해줘야함.
	for (auto it = m1.begin(); it != m1.end(); it++) {
		string name = it->first;
		cnt += min(it->second, m2[name]);
	}
	// 합집합 찾기
	// 다중집합 A = {1, 1, 2, 2, 3}, 다중집합 B = {1, 2, 2, 4, 5}라고 하면, 
	// 합집합 A ∪ B = {1, 1, 2, 2, 3, 4, 5}
	// 중복을 피하기 위해 가장 큰 수를 더해줌
	for (auto it = m1.begin(); it != m1.end(); it++) {
		string name = it->first;
		num += max(m2[name], it->second);
		m2.erase(name);
	}
	// 위에서 지우지 못하고 남은 원소를 합집합에 추가해줌.
	for (auto it = m2.begin(); it != m2.end(); it++) {
		num += it->second;
	}
	float rate = (float)cnt / float(num);
	answer = rate * 65536;
	return answer;
}