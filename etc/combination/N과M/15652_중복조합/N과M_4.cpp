#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

// n개중 r개
// int dcArr[r] = {0,};

int n, m;

void printArray() {
    for(int i = 0; i < m; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void duplicatedCombination(int depth, int idx) {
    if(depth == m) {
        printArray();
        return;
    }
    for(int i = idx; i <= n; i++) {
        v[depth] = i;
        duplicatedCombination(depth + 1, i);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    duplicatedCombination(0, 1);
}