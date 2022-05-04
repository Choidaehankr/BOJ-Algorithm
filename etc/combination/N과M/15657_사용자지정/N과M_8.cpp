#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int tmp[1001];
// n개중 r개
// 직접 입력받는 중복 조합

int n, m;

void printArray() {
    for(int i = 0; i < m; i++) {
        cout << tmp[i] << ' ';
    }
    cout << endl;
}

void duplicatedCombination(int depth, int idx) {
    if(depth == m) {
        printArray();
        return;
    }
    for(int i = idx; i < n; i++) {
        tmp[depth] = v[i];
        duplicatedCombination(depth + 1, i);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    duplicatedCombination(0, 0);
}