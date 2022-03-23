#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> q;
// 오름차순 정렬 후 앞에서부터 더해주면 됨.
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num; cin>> num;
        q.push(num);
    }
    int cur = q.top();
    q.pop();
    int result = 0;
    for(int i = 1; i < N; i++) {
        int sum = cur + q.top();
        q.pop();
        q.push(sum);
        result += sum;
        cur = q.top();
        q.pop();
    }
    cout << result << endl;
}