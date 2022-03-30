#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 100001

using namespace std;
int in_come[MAX], costTime[1001];
int arr[1001][MAX];
int dp[1001];
int N, rules, dest;
vector<int> topologicalSort(vector<vector<int> > v, int in_come[], int *val) {
	vector<int> tmp;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in_come[i] == 0) {
			q.push(i);
		}
	}
	dp[q.front()] = val[q.front()];
	//cout << "dp[" << q.front() << "] = " << dp[q.front()] << endl;
	//cout << "test start!!!!!!" << endl;
	while (!q.empty()) {
		int cur = q.front();
		dp[cur] = max(dp[cur], val[cur]);
		for (int i = 0; i < v[cur].size(); i++) {
			//cout << "v[cur][i] is " << v[cur][i] << " " << endl;
			dp[v[cur][i]] = max(val[v[cur][i]] + dp[cur], dp[v[cur][i]]);
			//cout << "dp[] valuse is " << dp[v[cur][i]] << endl;
		}
		tmp.push_back(cur);
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (--in_come[v[cur][i]] == 0) {
				q.push(v[cur][i]);
				int now = v[cur][i];
				//cout << "@@@@now is@@@@ " << now << endl;
				/*if (now == dest) {
					dp[now] = dp[cur] + val[now];
					break;
				}*/
				//dp[now] = max(dp[now-dp[cur]], dp[cur] + val[now]);
				/*if (now == dest) {
					dp[now] = max(dp[now], dp[now] + val[now]);
				}*/
			}
		}
	}
	//cout << "!!!!!!!!!!!!!!!!!!DP TEST!!!!!!!!!!!!!!!!!!!" << endl;
	/*for (int i = 0; i <= N; i++) {
		cout << dp[i] << ' ';
	}*/
	//cout << endl;
	//cout << "tolo test" << endl;
	/*for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << ' ';
	}
	cout << endl;*/
	cout << dp[dest] << endl;
	return tmp;
}


void search(vector<vector<int> > v, vector<int> tologicVec, int* value) {
	queue<int> q;
	int sum = 0;
	cout << "vector check " << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << "[" << i << "] ";
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	dp[tologicVec[0]] = value[tologicVec[0]];
	for (int i = 0; i < tologicVec.size(); i++) {
		int cur = tologicVec[i];  // 건물
		cout << "--cur is --- " << cur << endl;
		dp[cur] = max(dp[cur], value[tologicVec[i]]);
		for (int j = 0; j < v[cur].size(); j++) {
			cout << "v[cur][j] is " << v[cur][j] << " ";
			//dp[v[cur][j]] = max(dp[v[cur][j]]+dp[v[cur][j]], dp[cur] + value[v[cur][j]]);
			dp[v[cur][j]] = max(dp[v[cur][j]], dp[cur] + value[v[cur][j]]);
			cout << "calc result: " << dp[v[cur][j]] << endl;
			if (v[cur][j] == dest) {
				break;
			}
		}
	}
	cout << endl <<  "===DP CHECK===" << endl;
	for (int i = 0; i <= N; i++) {
		cout << dp[i] << " ";
	}
	cout << "result: " << dp[dest] << endl;
}

vector<vector<int> > v;
vector<int> temp;
int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		cin >> N;
		cin >> rules;
		v.clear(); temp.clear();
		// cout << "N is " << N << " rules is " << rules << endl;
		// int in_come[MAX], costTime[1001];
		for (int i = 0; i <= N; i++) {  // 2차원 벡터 생성
			v.push_back(vector<int>());
		}
		for (int i = 1; i <= N; i++) {  // 건물 별 소요 시간 저장
			int num; cin >> num;
			// cout << "num is " << num << endl;
			costTime[i] = num;
		}
		// cout << "cost time check" << endl;
		// for(int i = 1; i <= N; i++) {
		//     cout << costTime[i] << ' ';
		// }
		// cout << "---------------" << endl;
		for (int i = 0; i < rules; i++) {  // 건물 간선 정보 저장
			int forth, back;
			cin >> forth >> back;
			v[forth].push_back(back);
			in_come[back] += 1;
		}
		cin >> dest;
		temp = topologicalSort(v, in_come, costTime);
		 //cout << endl << "topological check" << endl;
		 //for(int i = 0; i < temp.size(); i++) {
		 //    cout << temp[i] << ' ';
		 //}
		//search(v, temp, costTime);
		memset(dp, 0, sizeof(dp));
		memset(in_come, 0, sizeof(in_come));
		memset(costTime, 0, sizeof(costTime));
		//cout << "=============search end================" << endl;
	}
}