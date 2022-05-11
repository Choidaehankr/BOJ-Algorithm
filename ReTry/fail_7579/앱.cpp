#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++) {
        int bytes; 
        cin >> bytes;
        v[i].first = bytes;
    }
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[i].second = val;
    }
    // for(int i = 0; i < n; i++) {
    //     cout << v[i].first << ' ' << v[i].second << endl;
    // }
    sort(v.begin(), v.end(), [] (pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    int sum = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(sum >= m) break;
        sum += v[i].first;
        res += v[i].second;
    }
    cout << res << endl;
}