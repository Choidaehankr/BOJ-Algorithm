#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;

// 아래와 같이 작성하니 segmentation error, swap()으로 변경
// m[str[i+1]]++;
// s.push(str[i+1]);
// i--;

// 첫번째 시도보다 약간 깔끔해졌다!

int main() {
	int X;
	string str;
	stack<char> s;
	map<char, int> m;
	cin >> X >> str;
	m['W'] = m['M'] = 0;
	for (int i = 0; i < str.size(); i++) {
		if (abs(m['W'] - m['M']) >= X) {
			if (s.top() != str[i]) {
				s.push(str[i]);
				m[str[i]]++;
			}
			else {
				if (str[i + 1] != s.top()) {
					swap(str[i], str[i + 1]);
					m[str[i]]++;
					s.push(str[i]);

				}
				else if(str[i+1] == s.top()) {
					break;
				}
			}
		}
		else {
			s.push(str[i]);
			m[str[i]]++;
		}
	}
	cout << m['W'] + m['M'] << endl;
}