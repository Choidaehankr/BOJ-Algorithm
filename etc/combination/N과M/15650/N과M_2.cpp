#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    vector<bool> tmp(v.size(), true);
    // for(int i = 0; i < v.size() - m; i++) {  // 내림차순
    for(int i = 0; i < m; i++) {
        tmp[i] = false;
    }
    do {
        for(int i = 0; i < v.size(); i++) {
            // if(tmp[i]) {  // 내림차순
            if(!tmp[i]) {
                cout << v[i] << ' ';
            }
        }
        cout << endl;
    } while (next_permutation(tmp.begin(), tmp.end()));
}