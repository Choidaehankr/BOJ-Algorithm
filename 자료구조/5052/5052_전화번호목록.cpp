#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// string 형태를 sort 하면, 사전순으로 정렬. 예시로, 123, 11111, 111 -> 
// 사전순으로 정렬됐기 때문에, 바로 다음 인덱스만 보더라도 일관성 여부를 판단할 수 있음. (접두어만 찾으면 되므로)
// 111, 1111234, 123
bool solution(vector<string> v) {
	for (int i = 0; i < v.size()-1; i++) {
		int cnt = 0;
		int len = v[i].size();  // 현재 전화번호와 바로 다음에 정렬된 전화번호의 일치 유무만 따짐.
		for (int j = 0; j < len; j++) {
			if (v[i][j] == v[i + 1][j]) {
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt == len) {  
			// v[i]번째 번호의 길이 만큼 v[i+1]번째 번호도 일치했다면, 즉, v[i]가 v[i+1]의 접두어라면
			// 일관성이 없는 번호 (v[i+1]은 전화를 걸 수 없는 번호)
			return true;
		}
	}
	return false;
}

int main() {
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int N; cin >> N;
		vector<string> v;
		for (int j = 0; j < N; j++) {
			string str; cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());  // vector의 문자열을 사전순으로 정렬
		if (solution(v)) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}