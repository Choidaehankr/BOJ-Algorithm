#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;

typedef pair<int, pair<int, int>> ii;
int parent[10001];
vector<ii> v;  // 가중치, 간선 정보

int findParent(int x) {  // 부모 찾기
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

bool checkParent(int x, int y) {  // 부모가 일치한다면 TRUE, 다르면 FALSE
	x = findParent(x);
	y = findParent(y);
	if (x == y) return true;
	else return false;
}


void setUnion (int x, int y) {  // 부모를 찾고, 서로 부모가 다르다면 사이클이 이루어 지지 않으므로 집합에 추가.
	x = findParent(x);
	y = findParent(y);
	if (x != y) parent[y] = x;
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int forth, back, val;
		cin >> forth >> back >> val;
		v.push_back({ val, {forth, back} });
	}
	sort(v.begin(), v.end());  // 오름차순 정렬

	for (int i = 1; i <= V; i++) {  // 시작은 노드가 각자 자기 자신으로 향하는 (자기 자신이 부모인) 사이클을 이룸
		parent[i] = i;
	}
	int result = 0;
	for (int i = 0; i < E; i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		if (!checkParent(x, y)) {
			setUnion(x, y);
			result += v[i].first;
		}
	}
	cout << result << endl;
}