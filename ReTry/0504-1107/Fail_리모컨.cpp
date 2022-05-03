#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string ch = "";
bool same = false;
int n;
vector<int> v;
string tmp_str = "";
bool number[11];
string result = "";
int answer = 0;

int bigger_case(int idx, string s) {
	int p = 0;
	for (int i = idx; i < ch.size(); i++) {
		int num = ch[i] - '0';
		int tmp_x = 10;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] - num < tmp_x) {
				p = j;
				tmp_x = abs(v[j] - num);
			}
		}
	//	s += tmp_x + '0';
		s += v[p] + '0';
	}
	return stoi(s);
}

int smaller_case(int idx, string s) {
	int p = 0;
	for (int i = idx; i < ch.size(); i++) {
		int tmp_x = 0;
		int num = ch[i] - '0';
		for (int j = 0; j < v.size(); j++) {
			//tmp_x = max(tmp_x, v[j] - num);
			if (v[j] - num > tmp_x) {
				p = j;
				tmp_x = abs(v[j] - num);
			}
		}
		// s += tmp_x + '0';
		s += v[p] + '0';
	}
	return stoi(s);
}

int compare(int num, int idx, string s) {
	int x = 10;
	int a, b;
	int z = ch[idx] - '0';  // 첫번째 숫자만 확인
	bool flag = false;
	int tmp = 0;
	for (int i = 0; i < v.size(); i++) {
		int sub = abs(z - v[i]);
		if (sub == x) {
			// 함수로 하나 빼주자
			flag = true;
		}
		if (sub < x) {
			x = sub;
			tmp = v[i];
		}
	}
	int res = stoi(ch);
	s += tmp + '0';
	if (flag) {
		a = bigger_case(idx+1, s);
		b = smaller_case(idx+1, s);
		if (abs(res - a) >= abs(res - b)) {
			return abs(res - b);
		}
		else {
			return abs(res - a);
		}
	}
	else {
		if (tmp > z) {
			//a = bigger_case(idx + 1, s);
			a = bigger_case(idx+1, s);
			return (abs(res - a));
		}
		else {
			//b = smaller_case(idx + 1, s); 
			b = smaller_case(idx+1, s);
			return (abs(res - b));
		}
	}
}

void solution(int dest) {
	// 일치하지 않은 순간
	// 1) 숫자가 더 커졌을 때, 차가 제일 작도록 (절대값?)
	// 1-1) 새로 넣을 숫자가에서 기존 숫자를 뺀 값이 가장 작도록
	// 2) 숫자가 더 작을 때, 차가 가장 크도록.
	// 2-1) 가장 크도록

	for(int i = 0; i < 10; i++) 

	bool bigger = false;
	bool smaller = false;

	bool flag = false;  // false는 큰거, true 작은거

	for (int i = 0; i < ch.size(); i++) {
		int num = ch[i] - '0';
		//cout << "num: " << num << endl;
		int x = 10;
		if (!same) {
			// v[j]버튼이 있다면
			if (!number[num]) {
				tmp_str += num + '0';
				continue;
			}
			else {
				same = true;
				answer = compare(num, i, tmp_str);
				break;
			}
		}
	}
}

int main() {
	cin >> ch;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		number[num] = true;
	}
	if (n == 0) {
		cout << ch.size() << endl;
		return 0;
	}
	if (n == 10) {
		cout << abs(stoi(ch) - 100) << endl;
		return 0;
	}
	if (ch == "100") {
		cout << 0 << endl;
		return 0;
	}
	int except_num = abs(100 - stoi(ch));
	for (int i = 0; i < 10; i++) {
		if (!number[i]) v.push_back(i);
	}
	sort(v.begin(), v.end());
	solution(stoi(ch));
	int min_result = 0;
	if (!same) {
		if (ch.size() < except_num)
			min_result = ch.size();
		else
			min_result = except_num;
	}
	else {
		if (answer + ch.size() < except_num)
			// cout << answer + ch.size() << endl;
			min_result = answer + ch.size();
		else
			//cout << except_num << endl;
			min_result = except_num;
	}
	int numb = stoi(ch);
	if (numb >= 10) {
		int mm = 0;
		int tstr = stoi(ch);
		ch.clear();
		ch = "";
		same = false;
		tstr -= 1;
		ch = to_string(tstr);
		solution(1);
		if (!same) {
			if (ch.size() < except_num)
				mm = ch.size();
			else
				mm = except_num;
		}
		else {
			if (answer + ch.size() < except_num)
				mm = answer + ch.size();
			else
				mm = except_num;
		}
		if (mm+1 > min_result) {
			cout << min_result << endl;
		}
		else {
			cout << mm + 1 << endl;
		}
	}
	else {
		cout << min_result << endl;
	}
}