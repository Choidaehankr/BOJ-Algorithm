#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check[1000];

vector<pair<int, pair<int, int> > > v;

void init() {
	// check 배열의 모든 수를 true로 초기화
	fill(check, check + 1000, true);
	// 답이 될 수 없는 수 (123 ~ 987, 0이 없고 중복된 수가 없는 3자리 수)를 false로 초기화+

	for (int i = 123; i <= 987; i++) {
		string str = to_string(i);
		if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0]) check[i] = false;
		if (str[0] - '0' == 0 || str[1] - '0' == 0 || str[2] - '0' == 0) check[i] = false;
	}
}

int main() {
	int N; cin >> N;
	init();
	for (int i = 0; i < N; i++) {
		int number, strike, ball;
		cin >> number >> strike >> ball;
		v.push_back(make_pair(number, make_pair(strike, ball)));
	}
	for (int i = 0; i < v.size(); i++) {
		int number = v[i].first;  // 민혁이가 영수에게 한 질문 (숫자)
		int strike = v[i].second.first;  // number에 strike와 ball 여부
		int ball = v[i].second.second;
		string tmp = to_string(number);
		for (int j = 123; j <= 987; j++) {
			int expStrike = 0;
			int expBall = 0;
			if (check[j]) {  // init()에서 false로 만들 수를 제외하고 답이 될 수 있는 수들을 탐색
				string str = to_string(j);
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y && tmp[x] == str[y]) expStrike += 1;  // 자리수와 숫자가 일치하면 strike
						if (x != y && tmp[x] == str[y]) expBall += 1;  // 숫자만 일치하면 ball
					}
				}
				if (strike != expStrike || ball != expBall)  // 영수가 알려준 strike와 ball의 개수와 일치하지 않으면 답이 될 수 없으므로 해당 숫자는 false로 초기화
					check[j] = false;
			}
		}
	}
	int result = 0;
	for (int i = 123; i <= 987; i++) {
		if (check[i]) result += 1;
	}
	cout << result << endl;
}