#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 100001

using namespace std;
int dp[1001];
int N, rules, dest;

void topologicalSort(vector<vector<int> > v, int in_come[], int *val) {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in_come[i] == 0) {
			q.push(i);
		}
	}
	// dp[q.front()] = val[q.front()];
	while (!q.empty()) {
		int cur = q.front();
		dp[cur] = max(dp[cur], val[cur]);
		for (int i = 0; i < v[cur].size(); i++) {
			dp[v[cur][i]] = max(val[v[cur][i]] + dp[cur], dp[v[cur][i]]);
		}
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (--in_come[v[cur][i]] == 0) {
				q.push(v[cur][i]);
			}
		}
	}
	cout << dp[dest] << endl;
}


int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) { 
        vector<vector<int> > v;
        int in_come[MAX], costTime[1001], arr[1001][MAX];
		cin >> N >> rules;
		for (int i = 0; i <= N; i++) {  // 2차원 벡터 생성
			v.push_back(vector<int>());
		}
		for (int i = 1; i <= N; i++) {  // 건물 별 소요 시간 저장
			int num; cin >> num;
			costTime[i] = num;
		}
		for (int i = 0; i < rules; i++) {  // 건물 간선 정보 저장
			int forth, back;
			cin >> forth >> back;
			v[forth].push_back(back);
			in_come[back] += 1;
		}
		cin >> dest;
		topologicalSort(v, in_come, costTime);

		memset(dp, 0, sizeof(dp));
	}
}

