#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

// 사용자의 고유한 id로 사용자의 이름을 식별하기 위한 map 선언
map<string, string> user;  // key: id, value: 이름
vector<pair<char, string>> result;  // 최종 결과 출력을 위해 'pair<동작, id>'으로 저장

vector<string> solution(vector<string> record) {
	vector<string> answer;
	for (int i = 0; i < record.size(); i++) {
		int idx = 0;
		vector<string> v;
		string tmp;
		stringstream ss(record[i]);
        // 공백을 기준으로 문자열(tmp)을 나눠 vetor v에 넣어줌
		while (ss >> tmp) {
			v.push_back(tmp);
		}
		string action = v[0], id = v[1];  // v[2]: 이름
		if (action == "Enter") {
			result.push_back(make_pair('E', id));
			user[id] = v[2];  // id 와 이름을 매칭
		}
		else if (action == "Leave") {
			result.push_back(make_pair('L', id));
		}
		else {  // "Change"일 경우 해당 id를 가진 사용자의 이름만 갱신해줌.
			user[id] = v[2];
		}
	}
	for (int i = 0; i < result.size(); i++) {
		if (result[i].first == 'E') {
			answer.push_back(user[result[i].second] + "님이 들어왔습니다.");
		}
		else {
			answer.push_back(user[result[i].second] + "님이 나갔습니다.");
		}
	}
	return answer;
}