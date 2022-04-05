#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

int N;
vector<pair<int, int > > v[MAX];
bool visited[MAX];

int result = 0;
int maxNode = 0;
void dfs(int idx, int sum) {
	if (visited[idx])
		return;
	visited[idx] = true;
	if (result < sum) {
		result = sum;
		maxNode = idx;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		dfs(v[idx][i].first, sum + v[idx][i].second);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, val;
		cin >> x;
		vector<pair<int, int> > tmp;
		while (1) {
			cin >> y;
			if (y == -1) {
				break;
			}
			cin >> val;
			v[x].push_back(make_pair(y, val));
		}
	}
	memset(visited, false, sizeof(visited));
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(maxNode, 0);
	cout << result << endl;
}