#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int N, M;
vector<vector<int> > v;  // 노드와 간선의 관계 저장을 위한 2차원 벡터 선언
int incom_edge[MAX];  // 진입 간선을 저장할 1차원 배열 선언
queue<int> q;  // 노드를 저장할 queue
int main() {
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        v.push_back(vector<int>());  // 2차원 벡터를 N행 만큼 초기화
    }
    for(int i = 0; i < M; i++) {
        int forth, back;  // 문제에서 주어진 조건: 학생 B(back)앞에 A(forth)가 있어야 한다.
        cin >> forth >> back;
        v[forth].push_back(back);  // forth 뒤에 back을 push_back()
        incom_edge[back]+=1;  // back의 진입 간선 개수를 증가. (forth 다음 back이 와야하므로)
    }
    for(int i = 1; i <= N; i++) {
        if(incom_edge[i] == 0) {
            q.push(i);  // 진입 간선이 없다면 q에 push
        }
    }
    while(!q.empty()) {
        int cur = q.front();  // q의 맨 앞 노드를 꺼내고 출력 (line 28-30)
        cout << cur << " ";
        q.pop();
        for(int i = 0; i < v[cur].size(); i++) {  // 현재 학생(v[cur])의 뒤에 있어야하는 학생들을 접근(v[cur].size())
            if(--incom_edge[v[cur][i]] == 0) {  // 위에서 현재 학생을 꺼냈으니 전위 연산 --로 현재 학생(v[cur][i])의 진입 간선을 하나 줄이고,
                q.push(v[cur][i]);  // 줄인 후 진입 간선이 0이라면, q에 push해준다.
            }
        }
    }
}