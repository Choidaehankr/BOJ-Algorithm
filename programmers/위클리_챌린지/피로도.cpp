#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int> > dungeons) {
    vector<int> v;
    for(int i = 0; i < dungeons.size(); i++) {
        v.push_back(i);
    }
    int answer = 0;
    do {
        int temp_num = k, cnt = 0;
        for(int i = 0; i < v.size(); i++) {
            int need = dungeons[v[i]][0];
            int val = dungeons[v[i]][1];
            if(need > temp_num) {
                continue;
            }
            need -= val;
            cnt++;
        }
        answer = max(answer, cnt);
    } while(next_permutation(v.begin(), v.end()));
    
    return answer;
}