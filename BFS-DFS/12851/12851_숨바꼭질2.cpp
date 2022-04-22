#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int N, K, min_time = 0, cnt = 0;
bool visited[MAX];

void solution() {
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		int mv[3] = { 1, -1, x };
		q.pop();
		visited[x] = true;
		if (cnt != 0 && x == K && time == min_time) {
			cnt++;
		}
		if (cnt == 0 && x == K) {
			min_time = time;
			cnt++;
		}
		for (int i = 0; i < 3; i++) {
			int nx = x + mv[i];
			if (nx >= 0 && nx <= MAX && !visited[nx]) {
				q.push(make_pair(nx, time + 1));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	solution();
	cout << min_time << endl << cnt << endl;
}