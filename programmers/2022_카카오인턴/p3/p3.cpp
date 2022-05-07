#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int alp, cop;

// bool cmp(vector<int> v1, vector<int> v2) {
//     int tmp_a = alp, tmp_c = cop;
//     if(v1[0]-tmp_a >)
// }

bool check[101];

int solution(int alp, int cop, vector<vector<int> > problems) {
    int answer = 0;
    int idx = 0;
    // sort(problems.begin() + idx, problems.end(), cmp);
    // sort(problems.begin() + idx, problems.end());
    // for(int i = 0; i < problems.size(); i++) {
    //     int alp_req = problems[i][0], cop_req = problems[i][1];
    //     if(alp < alp_req || cop < cop_req) {
    //         if(alp < alp_req) {
    //             answer += alp_req - alp;
    //         } else if(cop < cop_req) {
    //             answer += cop_req - cop;
    //         }
    //     }
    // }
    for(int i = 0; i < problems.size(); i++) {
        int cur_alp = problems[i][0], cur_cop = problems[i][1];
        int idx = 0;
        for(int j = 1; j < problems.size(); j++) {
            int alp_req = problems[j][0], cop_req = problems[j][1];
            int alp_dif = 150, cop_dif = 150;
            if(alp_req - cur_alp < alp_dif || cop_req - cur_cop < cop_dif) {
                idx = j;
                alp_dif = alp_req - cur_alp;
                cop_dif = cop_req - cur_cop;
            }
            
            if(cur_alp < alp_req || cur_cop < cop_req) {  // 아무것도 풀 수 없을 때.
                while(cur_alp == alp_req && cur_cop == cop_req) {
                    if(cur_alp < alp_req) {
                        answer += 1;
                        cur_alp += 1;
                    } 
                    if(cur_cop < cop_req) {
                        answer += 1;
                        cur_cop += 1;
                    } 
                }
            }  
            // 문제를 풀 수 있을 때,
            if(cur_alp >= alp_req && cur_cop >= cop_req) {
                
            } 
        }
    }
    return answer;
}

int main() {
    vector<vector<int> > v;
    vector<int> tmp;
    cin >> alp >> cop;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 5; j++) {
            int num; cin >> num;
            tmp.push_back(num);
        }
        v.push_back(tmp);
    }
    cout << solution(alp, cop, v);
    
}