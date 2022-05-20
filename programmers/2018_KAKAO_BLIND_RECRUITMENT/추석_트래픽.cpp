#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> start, end;
	for (int i = 0; i < lines.size(); i++) {
		lines[i].pop_back();  // 맨 뒤 's' 제거
		string h = lines[i].substr(11, 2);
		string m = lines[i].substr(14, 2);
		string s = lines[i].substr(17, 2);
		string ms = lines[i].substr(20, 3);
		int cost = stof(lines[i].substr(24, 5)) * 1000;

		int tmp_h = stoi(h) * 1000 * 3600;
		int tmp_m = stoi(m) * 1000 * 60;
		int tmp_s = stoi(s) * 1000;
		int tmp_ms = stoi(ms);

		start.push_back((tmp_h + tmp_m + tmp_s + tmp_ms) - cost + 1);
		end.push_back(tmp_h + tmp_m + tmp_s + tmp_ms);
	}

	for (int i = 0; i < end.size(); i++) {
		// 끝난 시각 +1000를 해주어 그 사이 있는 요청들 개수 카운트
		int end_t = end[i] + 1000;
		int cnt = 0;
		for (int j = i; j < start.size(); j++) {
			if (start[j] < end_t) {
				cnt++;
			}
		}
		answer = max(cnt, answer);
	}
	cout << "answer = " << answer << endl;
	return answer;
}