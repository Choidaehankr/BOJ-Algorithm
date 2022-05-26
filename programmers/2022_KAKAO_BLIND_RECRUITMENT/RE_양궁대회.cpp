#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxSub = 0;
vector<int> answer(1, -1);

bool getMoreScore(vector<int> &v) {
    for(int i = 10; i >= 0; i--) {
        if(v[i] > answer[i]) return true;
        else if(v[i] < answer[i]) return false;
    }
}

void getScores(vector<int> &apeach, vector<int> &ryan) {
    int ryanScore = 0, apeachScore = 0;
    for(int i = 0; i < 11; i++) {
        if(apeach[i] >= ryan[i] && apeach[i] > 0) {
            apeachScore += 10-i;
        } else if(ryan[i] > apeach[i] && ryan[i] > 0) {
            ryanScore += 10-i;
        }
    }
    int sub = ryanScore - apeachScore;
    if(sub > 0 && sub >= maxSub) {
        if(maxSub == sub && !getMoreScore(ryan)) return;
        maxSub = sub;
        answer = ryan;
    }
}

void DFS(int idx, int arrows, vector<int> &apeach, vector<int> &ryan) {
    if(idx > 10 || arrows == 0) {
        ryan[10] += arrows;
        getScores(apeach, ryan);
        ryan[10] -= arrows;
        return;
    }
    if(apeach[idx] < arrows) {
        ryan[idx] += apeach[idx]+1;
        DFS(idx+1, arrows-apeach[idx]-1, apeach, ryan);
        ryan[idx] -= apeach[idx]+1;
    }
    DFS(idx+1, arrows, apeach, ryan);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0);
    DFS(0, n, info, ryan);
    return answer;
}