#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    map<string, int> m;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        m[str]++;
    }
    int max_num =  0;
    for(auto it = m.begin(); it != m.end(); it++) {
        max_num = max(it->second, max_num);
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second == max_num) {
            cout << it->first << endl;
            return 0;
        }
    }
}