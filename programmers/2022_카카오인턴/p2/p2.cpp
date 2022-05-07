#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_sum(vector<int> v1, vector<int> v2) {
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < v1.size(); i++) {
        sum1 += v1[i];
    }
    for(int i = 0; i < v2.size(); i++) {
        sum2 += v2[i];
    }
    if(sum1 == sum2) return true;
    else return false;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    
    return answer;
}

int main() {

}