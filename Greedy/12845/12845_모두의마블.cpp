#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

// 내림차순 정렬
// 가장 큰 레벨의 카드 v[0]와 이후 나오는 카드의 레벨의 합을 누적해서 더함.

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    int score = v[0];
    for(int i = 1; i < v.size(); i++) {
        sum += score + v[i];
    }
    cout << sum;
}