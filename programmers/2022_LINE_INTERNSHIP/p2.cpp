#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

// sum : 잘린 갯수 , target: 목표 갯수, time: 소요 시간
void solve(int idx, int time, int sum, int target, vector<int> v) {
    if(sum == target || idx == v.size()-1) {
        if(sum < answer && answer > 0) {
            answer = time;
            return;
        }
    }
    // sum += idx+1;
    // time += v[idx];
    solve(idx, time+v[idx], sum+idx+1, target, v);
    solve(idx+1, time+v[idx+1], sum+idx+2, target, v);
}

int solution(int n, vector<int> times) {
    solve(0, 0, 1, n, times);
    return answer;
}