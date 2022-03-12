#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str, boom;
	cin >> str >> boom;
	int str_len = str.size();
	string v; // vector<char> v; 동일한 결과
	for (int i = 0; i < str_len; i++) {
		//v.push_back(str[i]);
		v += str[i];  // 우선 v에 모든 문자를 넣음
		if (v.size() >= boom.size()) {
			bool flag = false;
			for (int j = 0; j < boom.size(); j++) {
				// cd cd 
				if (v[v.size() - boom.size() + j] != boom[j]) {  // 폭발 문자열 판별
					flag = true;  // 폭발 문자열이 아니라면 현재 for-loop 종료
					break;
				}
			}
			if (!flag) {  // 위에서 폭발 문자열임을 확인하면 그 크기만큼 pop_back()
				for (int k = 0; k < boom.size(); k++) {
					v.pop_back();
				}
			}
		}
	}
	if (v.empty()) {
		cout << "FRULA" << endl;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
}