#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    int num = stages.size();
    vector<pair<double, int> > v;
    vector<int> answer;
    sort(stages.begin(), stages.end());
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 0; j < stages.size(); j++) {
            if(stages[j] == i) {
                cnt++;
            }
        }
        double rate = (double)cnt / (double)num;
        num -= cnt;
        if(cnt == 0) {  // 성공한 사람이 없을 경우,
            v.push_back(make_pair(0, i));
        } else  {
            v.push_back(make_pair(rate, i));
        }
       
    }
    sort(v.begin(), v.end(), [](pair<double, int> a, pair<double, int> b) {
      if(a.first == b.first) {
          return a.second < b.second;
      }
      return a.first > b.first;
    });

    for(int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].second);
    }
    return answer;
}