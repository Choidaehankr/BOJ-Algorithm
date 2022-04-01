#include <iostream>
#include <string>
#include <queue>
#define MAX 1001
using namespace std;

bool visited[MAX];
char arr[MAX];

string str;
int ans = 0;

void solution(int idx) {
    queue<int> q;
    q.push(idx);
    visited[idx] = true;
    bool flag = false;
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        int nx;
        if(arr[idx] == 'W') nx = idx -1;
        else if(arr[idx] == 'E') nx = idx + 1; 
        if(nx < 0 || nx >= str.size() || visited[nx]) continue;
        if(visited[nx] == false) {
          flag = true;
        }
        q.push(nx);
        visited[nx] = true;
    }
    if(flag) ans++;
}

int main() {
    int n; cin >> n;
    cin >> str ;
    for(int i = 0; i < str.size(); i++) {
        arr[i] = str[i];
    }
    for(int i = 0; i < str.size(); i++) {
        solution(i);
    }
    cout << ans << endl;
}