#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[101];
bool visited[101];
int N;
priority_queue<int, vector<int>, greater<int>> q;  // 오름차순 정렬 우선순위 큐

// 숫자들간에 관계를 연결했을 때 결국 자기 자신으로 돌아오는 숫자 (idx==dest)를 집합에 포함

void solution(int idx, int dest) {
	if (visited[idx]) {  // 이미 방문한적 있고, 자기 자신으로 돌아왔다면
		if (idx == dest) {
			q.push(dest);
		}
	}
	else {  // 처음 방문이라면 계속해서 재귀 탐색. (idx는 다음에 방문할 arr[idx]로 바뀜)
		visited[idx] = true;
		solution(arr[idx], dest);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int index = 0;
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		solution(i, i);
	}
	cout << q.size() << endl;
	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
}