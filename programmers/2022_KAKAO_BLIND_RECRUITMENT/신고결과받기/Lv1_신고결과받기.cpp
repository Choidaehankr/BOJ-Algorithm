#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> reportingGuys;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	map<string, vector<string> > vector_map;
	vector<int> answer;
	for (int i = 0; i < report.size(); i++) {
		int idx = 0;
		string reporter = "", criminal = "";
		while (report[i][idx] != ' ') {
			reporter += report[i][idx++];
		}
		while (idx++ < report[i].size()) {
			criminal += report[i][idx];
		}
		bool flag = false;
		vector<string> inVec = vector_map[criminal];
		for (int i = 0; i < inVec.size(); i++) {
			if (reporter == inVec[i])
				flag = true;
		}
		if (!flag) {
			vector_map[criminal].push_back(reporter);
		}
	}
	for (auto it = vector_map.begin(); it != vector_map.end(); it++) {
		if ((*it).second.size() >= k) {
			for (auto j = 0; j < (*it).second.size(); j++) {
				reportingGuys[(*it).second[j]] += 1;
			}
		}
	}
	for (int i = 0; i < id_list.size(); i++) {
		answer.push_back(reportingGuys[id_list[i]]);
	}

	return answer;
}