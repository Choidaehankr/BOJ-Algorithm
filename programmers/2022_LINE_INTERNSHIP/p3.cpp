#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;

int solution(int fuel, vector<int> powers, vector<int> distances) {
    int answer = 0;
    vector<pair<double, int> > needs;
    for(int i = 0; i < powers.size(); i++) {
        // (거리 / 속력)의 비율로 나눔.
        double rate = (double) distances[i] / (double) powers[i];
        needs.push_back(make_pair(rate, i));
    }
    // (거리 / 속력)의 비율의 내림차순으로 정렬
    sort(needs.begin(), needs.end(), [](pair<double, int> a, pair<double, int> b) {
        return a.first > b.first;
    });
    int sum = 0;  // 총 비율의 합
    for(int i = 0; i < needs.size(); i++) {
        sum += needs[i].first;
    }
    vector<int> v;
    // 우주선 한 대당 주입할 연료를 계산하기 위한 비율
    double rate = (double)fuel / (double)sum;
    for(int i = 0; i < needs.size(); i++) {
        // num = 한 대당 연료를 주입할 비율 * (거리/속력)
        double num = round(rate * needs[i].first);
        v.push_back(num);  // 연료를 넣어줄 양
    }
    // 이후 저 num으로 계산하면 될 것 같은데 시간 부족 ㅠㅠ
    return answer;
}