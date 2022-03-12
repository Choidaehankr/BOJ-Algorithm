#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for(int i = 0; i < M; i++) {
        int value; cin >> value;
        auto start = lower_bound(v.begin(), v.end(), value);
        auto end = upper_bound(v.begin(), v.end(), value);
        cout << end - start << ' ';
    }
}