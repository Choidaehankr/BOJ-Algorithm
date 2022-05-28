#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;


map<string, int> solver_list;
map<string, vector<string> > m;  // map<문제 이름, <문제를 푼 사람들> >

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    for(int i = 0; i < logs.size(); i++) {
        int idx = 0;
        string solver = "", problem = "";
        while(logs[i][idx] != ' ') {
            solver += logs[i][idx];
            idx++;
        }
        idx++;
        while(idx < logs[i].size()) {
            problem += logs[i][idx];
            idx++;
        }
        bool flag = false;
        // 'problem' 문제를 푼 사람들을 조회
        vector<string> inVec = m[problem];
        for(int i = 0; i < inVec.size(); i++) {
            // 이미 해당 문제를 푼 사람이라면 추가하지 않음
            if(inVec[i] == solver) {
                flag = true;
            }
        }
        // solver가 해당 문제를 푼 적이 없을 경우
        if(!flag) {
            m[problem].push_back(solver);  // 해당 문제를 푼 '사람'을 추가
        }
        solver_list[solver] = 1;  // 문제를 푼 사람 저장, 추후 '1문제 이상 푼' 사람을 새기 위함
    }

    double rate = double(solver_list.size()) / 2;
    for(auto it = m.begin(); it != m.end(); it++) {
        // 절반 이상이 푼 문제라면 answer에 문제를 추가
        if((*it).second.size() >= ceil(rate)) {
            answer.push_back((*it).first);
        }
    }
    return answer;
}