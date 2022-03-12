#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if(cmd == "order") {
            int table, time;
            cin >> table >> time;
            // cin >> time >> table;
            // v.push_back({table, time});
            v.push_back({time, table});
        } else if(cmd == "sort") {
            sort(v.begin(), v.end());
        } else if(cmd == "complete") {
            int table;
            cin >> table;
            for(int j = 0; j < v.size(); j++) {
                if(v[j].second == table) {
                    v.erase(v.begin()+j);
                }
            }
        }
        if(v.empty()) {
            cout << "sleep" << endl;
        } else {
            for(int k = 0; k < v.size(); k++) {
                cout << v[k].second << ' ';
            } 
            cout << endl;
        }
    }
}