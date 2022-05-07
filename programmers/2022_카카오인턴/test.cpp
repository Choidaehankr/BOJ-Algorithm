#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int tmp[50000][50000];
vector<vector<int> > arr;
vector<string> cmd;


void rotate_arr(vector<vector<int> > &rc, int s) {
    cout << "rotate call" << endl;
}

void shiftrow_arr(vector<vector<int> > &rc, int s) {
  // 맨 아래 원소들만 맨 위로 보내고 나머지는 한칸 아래 이동
    vector<int> tmp;
    for(int i = 0; i < s; i++) {
        tmp.push_back(rc[s-1][i]);
    }
    for(int i = s-1; i >= 0; i--) {
        for(int j = 0; j < s; j++) {
            rc[i][j] = rc[i-1][j];
        }
    }
    for(int i = 0; i < s; i++) {
        rc[0][i] = tmp[i];
    }
    cout << "rc check" << endl;
    for(int i = 0; i < rc.size(); i++) {
        for(int j = 0; j < rc[i].size(); j++) {
            cout << rc[i][j] << ' ';
        }
        cout << endl;
    }
}

vector<vector<int> > solution(vector<vector<int> > rc, vector<string> operations) {
    vector<vector<int> > answer;
    int len = rc.size();
    // for(int i = 0; i < rc.size(); i++) {
    //     for(int j = 0; j < rc[i].size(); j++) {
    //         tmp[i][j] = rc[i][j];
    //     }
    // }
    for(int i = 0; i < operations.size(); i++) {
        string cmd = operations[i];
        if(cmd == "Rotate") {
            rotate_arr(rc, len);
        } else if(cmd == "ShiftRow") {
            shiftrow_arr(rc, len);
        }
    }
    // return answer;
    return rc;
}

// int arr[50000][50000];

int main() {
    for(int i = 0; i < 3; i++) {
        vector<int> v;
        for(int j = 0; j < 3; j++) {
            // cin >> arr[i][j];
            int num; cin >> num;
            v.push_back(num);
        }
        arr.push_back(v);
    } 
    for(int i = 0; i < 2; i++) {
        string str;
        cin >> str;
        cmd.push_back(str);
    }
    vector<vector<int> > res = solution(arr, cmd);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0 ; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}