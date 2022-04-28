#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

vector<int> v[MAX];
int result[MAX];
int N;

void findParent(int idx) {
	//visited[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];  // 현재 idx에 연결된 노드들을 탐색
		if (!result[next]) {
			result[next] = idx;  // idx에서 방문하지 않은 노드가 있을 경우 현재 idx를 부모 노드로 기록
			findParent(next);  // 부모 노드 기록 후 이어서 탐색
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);  // 양방향 push
		v[y].push_back(x);
	}
	findParent(1);  // 루트부터 탐색 시작
	for (int i = 2; i <= N; i++) {
		cout << result[i] << '\n';
	}
}