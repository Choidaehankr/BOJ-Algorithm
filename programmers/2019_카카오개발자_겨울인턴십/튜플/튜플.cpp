#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 집합을 보고 튜플을 유추해야함
// 예를 들어 튜플이 (2, 1, 3, 4)인 경우 이는

// {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}와 같이 표현할 수 있습니다. 
// 이때, 집합은 원소의 순서가 바뀌어도 상관없으므로

// {{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}
// {{2, 1, 3, 4}, {2}, {2, 1, 3}, {2, 1}}
// {{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}
// 는 모두 같은 튜플 (2, 1, 3, 4)를 나타냅니다.

// 해결 방법
// 원소가 등장하는 횟수를 카운팅해서 튜플을 유추
// 원소의 순서가 뒤바뀌어도 위 모든 예시들은 2가 4번, 1이 3번, 2가 2번, 1이 1번 등장하므로, 튜플 {2, 1, 3, 4}로 유추 가능

vector<int> solution(string s) {
    map<int, int> m;
    vector<int> answer;
    string num;
    for(int i = 1; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num += s[i];
        }
        if (s[i] == ',' || s[i] == '}') {
            if(num.size() > 0) {
                m[stoi(num)] += 1;
                num.erase();
            }
            
        }
    }

    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [] (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    for(auto num : vec) {
        answer.push_back(num.first);
    }
    return answer;
}